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
	printf("                            |      ����������      |\n");
	printf("                            ------------------------\n");
	printf("                            |       +   �ӷ�       |\n");
	printf("                            ------------------------\n");
	printf("                            |       -   ����       |\n");
	printf("                            ------------------------\n");
	printf("                            |       *   �˷�       |\n");
	printf("                            ------------------------\n");
	printf("                            |       /   ����       |\n");
	printf("                            ------------------------\n");
	printf("                            |      ()   ����       |\n");
	printf("                            ------------------------\n");
	printf("                            |       Ӣ�����뷨     |\n");
	printf("                            ------------------------\n");
	printf("ע�⣺�����ʾͬʱ���ּ������ͼ�����Ϊ-1��-1������ʵֵ\n");
}


//���������ջ�ṹ
typedef struct {
	char items[MAX_SIZE];
	int top;

}OpearandStack;

//���������ջ�ṹ
typedef struct {
	float items[MAX_SIZE];
	int top;

}OpearatorStack;


//��ʼ��������ջ
void initstack1(OpearatorStack* stack)
{
	stack->top = -1;
}

//��ʼ��������ջ
void initstack2(OpearandStack* stack)
{
	stack->top = -1;
}

//��������ջ
void OpearatorPush(OpearatorStack* stack, float value)
{
	stack->items[++stack->top] = value;

}
// ��������ջ
void OpearandPush(OpearandStack* stack, char value)
{
	stack->items[++stack->top] = value;
}

//��������ջ
float OperatorPop(OpearatorStack* stack){
	return stack->items[stack->top--];
}

//��������ջ

char OpearandPop(OpearandStack* stack)
{
	return stack->items[stack->top--];
}

//�ж��Ƿ�ʱ������
bool isOperator(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}


//�ж����ȼ�

int precedence(char op) {
	if (op == '+' || op == '-') {
		return 1;
	}
	else if (op == '*' || op == '/') {
		return 2;
	}
	return 0;
}


//Ѱ����һ��')'
int Fingnext(char* input, int start)
{
	//����������
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

//�������
float evaluate(char *input, OpearandStack* opearandstack, OpearatorStack* opearatorstack,int start,int end)
{
	int i = start; //���ڱ���input��ÿһ���ַ�
	for (; i <= end;i++) {
		
		
		//���ַ�Ϊ�ո�ʱֱ������
		if (input[i] == ' ') {
			continue;
		}

		//���ַ�Ϊ���ֻ���С����
		else if (isdigit(input[i])||input[i]=='.') {
			float num = 0;  //����num�����洢����
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

			//��ջ
			OpearatorPush(opearatorstack, num);
		}


		//���ַ�Ϊ���������ʱ
		 if(isOperator(input[i])) {



			//�ж�ջ�Ƿ�Ϊ�գ����ұȽ�ջ�������������ȼ��͵�ǰ���ʽ�в����������ȼ���
			while (opearandstack->top != -1 && precedence(opearandstack->items[opearandstack->top]) >= precedence(input[i])) {
				
				//��ò�����ջ����������
				float num1 = OperatorPop(opearatorstack);
				float num2 = OperatorPop(opearatorstack);


				//��ò�����ջ���Ĳ�����
				char op= OpearandPop(opearandstack);
				
				//�Ѽ����������������ջ
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
			//�ѵ�ǰ��������ջ
			OpearandPush(opearandstack, input[i]);
		}

		//���ַ�Ϊ����ʱ
	  if (input[i] == '(') {
			int judge = Fingnext(input, i);
			if (judge == -1) {
				printf("                   �������");
				return -1;                        //-1��Ϊ����ֵ
			}
			
			//�ݹ鴦�������ڵĽ��
			float sub = evaluate(input, opearandstack, opearatorstack,i + 1, judge - 1);
			
			//�������ڼ�������ջ
			OpearatorPush(opearatorstack, sub);
		}
	  //�жϳ�����ĸ
	  if (input[i] >= 'A' && input[i] <= 'z') {
		  printf("            �������");
		  return -1;
	  }
	  //�ж��������
	  if (input[i] == ',' || input[i] == ':' || input[i] == '!' || input[i] == '@' || input[i] == '#'
		  || input[i] == '$' || input[i] == '%' || input[i] == '^' || input[i] == '&' || input[i] == '*'
		  || input[i] == '_' || input[i] == '{' || input[i] == '}' || input[i] == ';' || input[i] == '?'
		  || input[i] == '`' || input[i] == '~' || input[i] == '>' || input[i] == '<' || input[i] == '/'
		  || input[i] == '\\' || input[i] == '\'' || input[i] == '\"' ) {

		  printf("            �������");
		  return -1;
	  }
	}
	while (opearandstack->top != -1 ) {

		//��ò�����ջ����������
		float num1 = OperatorPop(opearatorstack);
		float num2 = OperatorPop(opearatorstack);


		//��ò�����ջ���Ĳ�����
		char op = OpearandPop(opearandstack);

		//�Ѽ����������������ջ
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