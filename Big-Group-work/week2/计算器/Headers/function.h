#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX_SIZE 200
#define _CRT_SECURE_NO_WARNINGS 
void welcome()
{
	printf("                            ------------------------\n");
	printf("                            |      四则运算器      |\n");
	printf("                            ------------------------\n");
	printf("                            |       +   加法       |\n");
	printf("                            ------------------------\n");
	printf("                            |       -   减法       |\n");
	printf("                            ------------------------\n");
	printf("                            |       *   乘法       |\n");
	printf("                            ------------------------\n");
	printf("                            |       /   除法       |\n");
	printf("                            ------------------------\n");
	printf("                            |      ()   括号       |\n");
	printf("                            ------------------------\n");
	printf("                            |       英文输入法     |\n");
	printf("                            ------------------------\n");
	printf("注意：如果提示同时出现计算错误和计算结果为-1，-1不是真实值\n");
}


//定义操作符栈结构
typedef struct {
	char items[MAX_SIZE];
	int top;

}OpearandStack;

//定义操作数栈结构
typedef struct {
	float items[MAX_SIZE];
	int top;

}OpearatorStack;


//初始化操作数栈
void initstack1(OpearatorStack* stack)
{
	stack->top = -1;
}

//初始化操作符栈
void initstack2(OpearandStack* stack)
{
	stack->top = -1;
}

//操作数入栈
void OpearatorPush(OpearatorStack* stack, float value)
{
	stack->items[++stack->top] = value;

}
// 操作符入栈
void OpearandPush(OpearandStack* stack, char value)
{
	stack->items[++stack->top] = value;
}

//操作数出栈
float OperatorPop(OpearatorStack* stack){
	return stack->items[stack->top--];
}

//操作符出栈

char OpearandPop(OpearandStack* stack)
{
	return stack->items[stack->top--];
}

//判断是否时操作符
bool isOperator(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}


//判断优先级

int precedence(char op) {
	if (op == '+' || op == '-') {
		return 1;
	}
	else if (op == '*' || op == '/') {
		return 2;
	}
	return 0;
}


//寻找下一个')'
int Fingnext(char* input, int start)
{
	//用于找括号
	int count = 0;
	for (int i = start; input[i] != '\0'; i++) {
		if (input[i] == '(')
			count++;
		else if (input[i] == ')') {
			count--;
			if (count == 0)
				return i;
		}
			
		
	}
	return -1;
}

//计算操作
float evaluate(char *input, OpearandStack* opearandstack, OpearatorStack* opearatorstack,int start,int end)
{
	int i = start; //用于遍历input的每一个字符
	for (; i <= end;i++) {
		
		
		//当字符为空格时直接跳过
		if (input[i] == ' ') {
			continue;
		}

		//当字符为数字或者小数点
		else if (isdigit(input[i])||input[i]=='.') {
			float num = 0;  //定义num用来存储数字
			while (isdigit(input[i]) || input[i] == '.') {
				if (input[i] == '.') {
					i++;
					float fraction = 0.1;
					while (isdigit(input[i])) {
						num = num + (input[i] - '0') * fraction;
						fraction /= 10.0;
						i++;
					}
				}
				else if (isdigit(input[i])) {
					num = 10 * num + (input[i] - '0');
					i++;
				}
				
			}

			//入栈
			OpearatorPush(opearatorstack, num);
		}


		//当字符为四则运算符时
		 if(isOperator(input[i])) {



			//判断栈是否为空，并且比较栈顶操作符的优先级和当前表达式中操作符的优先级。
			while (opearandstack->top != -1 && precedence(opearandstack->items[opearandstack->top]) >= precedence(input[i])) {
				
				//获得操作数栈顶的两个数
				float num1 = OperatorPop(opearatorstack);
				float num2 = OperatorPop(opearatorstack);


				//获得操作符栈顶的操作符
				char op= OpearandPop(opearandstack);
				
				//把计算结果重新入操作数栈
				if (op == '+') {
					OpearatorPush(opearatorstack, num1 + num2);
				}
				else if (op == '-') {
					OpearatorPush(opearatorstack, num2 - num1);
				}
				else if (op == '*') {
					OpearatorPush(opearatorstack, num1 * num2);
				}
				else if (op == '/') {
					OpearatorPush(opearatorstack, num2/num1);
				}
			}
			//把当前操作符入栈
			OpearandPush(opearandstack, input[i]);
		}

		//当字符为括号时
	  if (input[i] == '(') {
			int judge = Fingnext(input, i);
			if (judge == -1) {
				printf("                   输入错误");
				return -1;                        //-1作为返回值
			}
			
			//递归处理括号内的结果
			float sub = evaluate(input, opearandstack, opearatorstack,i + 1, judge - 1);
			
			//将括号内计算结果入栈
			OpearatorPush(opearatorstack, sub);
		}
	  //判断出现字母
	  if (input[i] >= 'A' && input[i] <= 'z') {
		  printf("            输入错误");
		  return -1;
	  }
	  //判断所有情况
	  if (input[i] == ',' || input[i] == ':' || input[i] == '!' || input[i] == '@' || input[i] == '#'
		  || input[i] == '$' || input[i] == '%' || input[i] == '^' || input[i] == '&' || input[i] == '*'
		  || input[i] == '_' || input[i] == '{' || input[i] == '}' || input[i] == ';' || input[i] == '?'
		  || input[i] == '`' || input[i] == '~' || input[i] == '>' || input[i] == '<' || input[i] == '/'
		  || input[i] == '\\' || input[i] == '\'' || input[i] == '\"' ) {

		  printf("            输入错误");
		  return -1;
	  }
	}
	while (opearandstack->top != -1 ) {

		//获得操作数栈顶的两个数
		float num1 = OperatorPop(opearatorstack);
		float num2 = OperatorPop(opearatorstack);


		//获得操作符栈顶的操作符
		char op = OpearandPop(opearandstack);

		//把计算结果重新入操作数栈
		if (op == '+') {
			OpearatorPush(opearatorstack, num1 + num2);
		}
		else if (op == '-') {
			OpearatorPush(opearatorstack, num2 - num1);
		}
		else if (op == '*') {
			OpearatorPush(opearatorstack, num1 * num2);
		}
		else if (op == '/') {
			OpearatorPush(opearatorstack, num2 / num1);
		}
	}
	return OperatorPop(opearatorstack);
}