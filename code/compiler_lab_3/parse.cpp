#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"
#include <string>
#include <QDebug>
using namespace std;
#pragma execution_character_set("utf-8")

static TokenType token; /* holds current token */

/* function prototypes for recursive calls */
static TreeNode* stmt_sequence(void);
static TreeNode* statement(void);
static TreeNode* if_stmt(void);
static TreeNode* repeat_stmt(void);
static TreeNode* assign_stmt(void);
static TreeNode* read_stmt(void);
static TreeNode* write_stmt(void);
static TreeNode* exp(void);
static TreeNode* simple_exp(void);
static TreeNode* term(void);
static TreeNode* power(void);
static TreeNode* factor(void);
static TreeNode* for_stmt(void);
static TreeNode* orexp(void);
static TreeNode* andexp(void);
static TreeNode* notexp(void);
static TreeNode* regex_stmt(void);
static TreeNode* andreg(void);
static TreeNode* topreg(void);
static TreeNode* reg_factor(void);


static void syntaxError(std::string message)
{
    qDebug() << "第" << lineno << "行，存在错误：" << QString::fromStdString(message);
    std::string msg =  (string)"行，存在错误：" + message;
    debugMsg.append("\n").append(QString::number(lineno)).append(QString::fromStdString(msg));
    /*fprintf(listing, "\n>>> ");
    fprintf(listing, "Syntax error at line %d: %s", lineno, message);*/
    Error = TRUE;
}

static void match(TokenType expected)
{
    if (token == expected) token = getToken();
    else {
        syntaxError("unexpected token -> " + getTokenString(token, tokenString).toStdString());
        printToken(token, tokenString);
        fprintf(listing, "      ");
    }
}

TreeNode* stmt_sequence(void)
{
    TreeNode* t = statement();
    TreeNode* p = t;
    while ((token != ENDFILE) && (token != END) &&
        (token != ELSE) && (token != UNTIL) && (token != ENDDO) && (token != RPM))
    {
        TreeNode* q;
        match(SEMI);
        q = statement();
        if (q != NULL) {
            if (t == NULL) t = p = q;
            else /* now p cannot be NULL either */
            {
                p->sibling = q;
                p = q;
            }
        }
    }
    return t;
}


//P394 
//lineno: 961
TreeNode* statement(void)
{
    TreeNode* t = NULL;
    switch (token) {
    case IF: t = if_stmt(); break;
    case REPEAT: t = repeat_stmt(); break;
    case ID: t = assign_stmt(); break;
    case READ: t = read_stmt(); break;
    case WRITE: t = write_stmt(); break;
    case FOR: t = for_stmt(); break;
    default: syntaxError("unexpected token -> ");
        printToken(token, tokenString);
        token = getToken();
        break;
    } /* end case */
    return t;
}


//P394 
//lineno: 977
TreeNode* if_stmt(void)
{
    TreeNode* t = newStmtNode(IfK);
    match(IF);
    match(LPAREN);
    if (t != NULL) t->child[0] = exp();
    match(RPAREN);
    match(LPM);
    if (t != NULL) t->child[1] = stmt_sequence();
    match(RPM);
    if (token == ELSE) {
        match(ELSE);
        match(LPM);
        if (t != NULL) t->child[2] = stmt_sequence();
        match(RPM);
    }
    return t;
}

//P394 
//lineno:991
TreeNode* repeat_stmt(void)
{
    TreeNode* t = newStmtNode(RepeatK);
    match(REPEAT);
    if (t != NULL) t->child[0] = stmt_sequence();
    match(UNTIL);
    if (t != NULL) t->child[1] = exp();
    return t;
}

TreeNode* assign_stmt(void)
{
    TreeNode* t = newStmtNode(AssignK);
    if ((t != NULL) && (token == ID))
        t->attr.name = copyString(tokenString);
    match(ID);
    if (token == ASSIGN)
    {
        match(ASSIGN);
        if (t != NULL) t->child[0] = exp();
    }
    else if (token == PLUSEQ)
    {
        match(PLUSEQ);
        //if (t != NULL) t->child[0] = exp();
        if (t != NULL) {
            TreeNode* p = newExpNode(OpK);
            if (p != NULL) {
                TreeNode* temp = newExpNode(IdK);
                if (temp != NULL)
                    temp->attr.name = copyString(t->attr.name);
                p->child[0] = temp;
                p->attr.op = PLUS;
                p->child[1] = exp();
                t->child[0] = p;
            }
        }
    }
    else if (token == REGEX)
    {
        match(REGEX);
        if (t != NULL) t->child[0] = regex_stmt();
    }
    return t;
}

TreeNode* read_stmt(void)
{
    TreeNode* t = newStmtNode(ReadK);
    match(READ);
    if ((t != NULL) && (token == ID))
        t->attr.name = copyString(tokenString);
    match(ID);
    return t;
}

TreeNode* write_stmt(void)
{
    TreeNode* t = newStmtNode(WriteK);
    match(WRITE);
    if (t != NULL) t->child[0] = exp();
    return t;
}

TreeNode* exp(void)
{
    TreeNode* t = orexp();
    while (token == OR)
    {
        TreeNode* p = newExpNode(OpK);
        if (p != NULL) {
            p->child[0] = t;
            p->attr.op = token;
            t = p;
            match(token);
            t->child[1] = orexp();
        }
    }
    return t;
}

TreeNode* orexp(void)
{
    TreeNode* t = andexp();
    while (token == AND)
    {
        TreeNode* p = newExpNode(OpK);
        if (p != NULL) {
            p->child[0] = t;
            p->attr.op = token;
            t = p;
            match(token);
            t->child[1] = andexp();
        }
    }
    return t;
}

TreeNode* andexp(void)
{
    TreeNode* t = simple_exp();
    if (token == LTEQ || token == RTEQ || token == LT || token == RT || token == NOTEQ || token == EQ) {
        TreeNode* p = newExpNode(OpK);
        if (p != NULL) {
            p->child[0] = t;
            p->attr.op = token;
            t = p;
        }
        match(token);
        if (t != NULL)
            t->child[1] = simple_exp();
    }
    return t;
}

TreeNode* simple_exp(void)
{
    TreeNode* t = term();
    while ((token == PLUS) || (token == MINUS))
    {
        TreeNode* p = newExpNode(OpK);
        if (p != NULL) {
            p->child[0] = t;
            p->attr.op = token;
            t = p;
            match(token);
            t->child[1] = term();
        }
    }
    return t;
}

TreeNode* term(void)
{
    TreeNode* t = notexp();
    while ((token == TIMES) || (token == OVER) || (token == MOD))
    {
        TreeNode* p = newExpNode(OpK);
        if (p != NULL) {
            p->child[0] = t;
            p->attr.op = token;
            t = p;
            match(token);
            p->child[1] = notexp();
        }
    }
    return t;
}

TreeNode* notexp(void)
{
    if (token == NOT)
    {
        match(NOT);
        TreeNode* p = newExpNode(OpK);
        p->attr.op = NOT;
        if (token == NOT)
        {
            p->child[0] = notexp();
        }
        else
        {
            p->child[0] = power();
        }
        return p;
    }
    else
    {
        TreeNode* t = power();
        return  t;
    }
}

TreeNode* power(void)
{
    TreeNode* t = factor();
    while ((token == POWER))
    {
        TreeNode* p = newExpNode(OpK);
        if (p != NULL) {
            p->child[0] = t;
            p->attr.op = token;
            t = p;
            match(token);
            p->child[1] = factor();
        }
    }
    return t;
}

TreeNode* factor(void)
{
    TreeNode* t = NULL;
    switch (token) {
    case NUM:
        t = newExpNode(ConstK);
        if ((t != NULL) && (token == NUM))
            t->attr.val = atoi(tokenString);
        match(NUM);
        break;
    case ID:
        t = newExpNode(IdK);
        if ((t != NULL) && (token == ID))
            t->attr.name = copyString(tokenString);
        match(ID);
        break;
    case LPAREN:
        match(LPAREN);
        t = exp();
        match(RPAREN);
        break;
    default:
        syntaxError("unexpected token -> ");
        printToken(token, tokenString);
        token = getToken();
        break;
    }
    return t;
}

TreeNode* for_stmt(void)
{
    // 赋值节点
    TreeNode* p = newStmtNode(AssignK);
    match(FOR);
    if ((p != NULL) && (token == ID))
    {
        p->attr.name = copyString(tokenString);
    }
    match(ID);
    match(ASSIGN);
    if (p != NULL)
    {
        p->child[0] = simple_exp();
    }
    // FOR节点
    TreeNode* t = NULL;
    if (token == TO) { // 步长+1
        t = newStmtNode(ForToK);
        t->child[0] = p;
        match(TO);
    }
    else if (token == DOWNTO) { // 步长-1
        t = newStmtNode(ForDowntoK);
        t->child[0] = p;
        match(DOWNTO); 
    }
    else    // 出错提示
    {
        syntaxError("Expecting 'to' or 'downto' after assignment in for statement");
    } 
    t->child[1] = simple_exp();
    match(DO);
    t->child[2] = stmt_sequence();
    match(ENDDO);
    return t;
}

TreeNode* regex_stmt(void)
{
    TreeNode* t = andreg();
    while ((token == RGOR))
    {
        TreeNode* p = newExpNode(OpK);
        if (p != NULL) {
            p->child[0] = t;
            p->attr.op = token;
            t = p;
            match(token);
            t->child[1] = andreg();
        }
    }
    return t;
}

TreeNode* andreg(void)
{
    TreeNode* t = topreg();
    while ((token == RGAND))
    {
        TreeNode* p = newExpNode(OpK);
        if (p != NULL) {
            p->child[0] = t;
            p->attr.op = token;
            t = p;
            match(token);
            t->child[1] = topreg();
        }
    }
    return t;
}

TreeNode* topreg(void)
{
    TreeNode* t = reg_factor();
    while ((token == RGCLOSE) || (token == RGCHOOSE))
    {
        TreeNode* p = newExpNode(OpK);
        if (p != NULL) {
            p->child[0] = t;
            p->attr.op = token;
            t = p;
            match(token);
        }
    }
    return t;
}

TreeNode* reg_factor(void)
{
    TreeNode* t = NULL;
    switch (token) {
    case NUM:
        t = newExpNode(ConstK);
        if ((t != NULL) && (token == NUM))
            t->attr.val = atoi(tokenString);
        match(NUM);
        break;
    case ID:
        t = newExpNode(IdK);
        if ((t != NULL) && (token == ID))
            t->attr.name = copyString(tokenString);
        match(ID);
        break;
    case LPAREN:
        match(LPAREN);
        t = regex_stmt();
        match(RPAREN);
        break;
    default:
        syntaxError("unexpected token -> ");
        printToken(token, tokenString);
        token = getToken();
        break;
    }
    return t;
}

/****************************************/
/* the primary function of the parser   */
/****************************************/
/* Function parse returns the newly
 * constructed syntax tree
 */
TreeNode* parse(void)
{
    TreeNode* t;
    token = getToken();
    t = stmt_sequence();
    if (token != ENDFILE)
        syntaxError("Code ends before file\n");
    return t;
}
