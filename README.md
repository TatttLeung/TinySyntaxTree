# TinySyntaxTree

## 基本信息

### 华南师范大学 2021级（2023年） 编译原理 实验三 TINY扩充语言的语法树生成

## 运行环境

QT Creator 5.0.2

QT 5.12.12 MinGW 64-bit

同时打代码使用VS2019+QT插件

## 文档说明

docs 文档文件夹

test 测试文件夹

code 源码文件夹

## **！！本项目缺陷：**

暂未发现

## 题目

一、实验内容：

（一）为Tiny语言扩充的语法有

1.实现改写书写格式的新if语句；

2.增加for循环；

3.扩充算术表达式的运算符号：+= 加法赋值运算符号（类似于C语言的+=）、求余%、乘方^，

4.扩充扩充比较运算符号：=（等于），>(大于)、<=(小于等于)、>=(大于等于)、<>(不等于)等运算符号，

5.增加正则表达式，其支持的运算符号有： 或(|) 、连接(&)、闭包(#)、括号( ) 、可选运算符号（？）和基本正则表达式。 

6.增加位运算表达式，其支持的位运算符号有 and(与)、or（或）、 not(非），如果对位运算不熟悉，可以参考C/C++的位运算。

（二）对应的语法规则分别为：

1. 把TINY语言原有的if语句书写格式
   
  ```
  if_stmt-->if exp then stmt-sequence end | | if exp then stmt-sequence else stmt-sequence end 
  ```

  改写为：

  ```
  if_stmt-->if(exp) stmt-sequence else stmt-sequence | if(exp) stmt-sequence
  ```
2. for语句的语法规则：
（1) for-stmt-->for identifier:=simple-exp to simple-exp do stmt-sequence enddo  步长递增1
（2） for-stmt-->for identifier:=simple-exp downto simple-exp do stmt-sequence enddo  步长递减1

3. += 加法赋值运算符号、求余%、乘方^等运算符号的文法规则请自行组织。
4. =（等于），>(大于)、<=(小于等于)、>=(大于等于)、<>(不等于)等运算符号的文法规则请自行组织。
5. 为tiny语言增加一种新的表达式——正则表达式，其支持的运算符号有： 或(|) 、连接(&)、闭包(#)、括号( ) 、可选运算符号（？）和基本正则表达式，对应的文法规则请自行组织。
6. 为tiny语言增加一种新的语句，ID:=正则表达式 
7. 为tiny语言增加一种新的表达式——位运算表达式，其支持的运算符号有 and(与) 、or (或)、非(not)。
8. 为tiny语言增加一种新的语句，ID:=位运算表达式 
9. 为了实现以上的扩充或改写功能，还需要注意对原tiny语言的文法规则做一些相应的改造处理。 

Tiny语言原来的文法规则，可参考：云盘中参考书P97及P136的文法规则。

二、实验要求：

（1）要提供一个源程序编辑的界面，以让用户输入源程序（可输入，可保存、可打开源程序）

（2）可由用户选择是否生成语法树，并可查看所生成的语法树。

（3）实验3的实现只能选用的程序设计语言为：C++

（4）要求应用程序的操作界面应为Windows界面。

（5）应该书写完善的软件文档

三、完成时间：四周（第9周-第13周）

四、上交方法：通过砺儒云平台进行实验提交

五、完成方式：每个学生自行独立完成。


测试文件1：(该程序中的if语句还是采用原Tiny语言中if语句的书写格式进行书写，作为实验3的测试源程序，你需要根据实验3实际要求的改写方式进行改写)

```
{ Sample program
 in TINY language -
 computes factorial
}
read x; { input an integer }
if 0<x then { don't compute if x <= 0 }
 for fact := x downto 1 do 
  fact := fact * x;
 enddo
 write fact; { output factorial of x }
end
```

测试文件2：(该程序中的if语句还是采用原Tiny语言中if语句的书写格式进行书写，作为实验3的测试源程序，你需要根据实验3实际要求的改写方式进行改写)

```
{ Sample program
  in TINY language -
  computes factorial
}
read x; { input an integer }
 
if  x>0 then { don't compute if x <= 0 }
  fact := 1;
  repeat
    fact := fact * x;
    x := x - 1
  until x = 0;
  write fact  { output factorial of x }
end
```

