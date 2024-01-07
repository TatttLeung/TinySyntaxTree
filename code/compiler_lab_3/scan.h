#pragma once

#ifndef _SCAN_H_
#define _SCAN_H_

/* MAXTOKENLEN is the maximum size of a token */
#define MAXTOKENLEN 40

/* tokenString array stores the lexeme of each token */
extern char tokenString[MAXTOKENLEN + 1];

void reset();

/* function getToken returns the
 * next token in source file
 */
TokenType getToken(void);

#endif