#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS 
#define MAX_SIZE 100  //栈长
//开始界面
void welcome() {
	printf("温馨提示：程序运行无提示请按enter键\n");
	printf("****随便看看就行\n");
	printf("****1.添加元素到栈顶\n");
	printf("****2.从栈顶移除元素\n");
	printf("****3.获取栈顶元素\n");
	printf("****4.获取栈的大小\n");
	printf("****5.输出栈\n");
	printf("****6.清空栈\n");
	printf("****7.销毁栈\n");
	printf("****8.退出界面\n");
}


//清屏函数
void clear()
{
	system("cls");
	system("pause");
	system("cls");
}


//清空输入缓存区
void clearInputBuffer()
{
	while (getchar() != '\n');
}

//定义数据类型
typedef enum {
	INT_TYPE,
	FLOAT_TYPE,
	CHAR_TYPE,
	STRING_TYPE
}DataType;

//定义一个栈
typedef struct {
	void* data[MAX_SIZE];// 可以为任何类型的数据域
	int top;             // 顶栈
	DataType type[MAX_SIZE];            //数据类型
}Stack;

//初始化栈
void initstack(Stack* stack)
{
	stack->top =-1;
}
// 判断栈是否为空
int isEmpty(Stack* stack) {
	return (stack->top == -1);
}

//判断栈是否已满
int isFull(Stack* stack) {
	return(stack->top == MAX_SIZE - 1);
}



// 输出栈中的全部元素
void printStackElements(Stack* stack) {
    if (isEmpty(stack)) {
        printf("栈为空\n");
        return;
    }

    printf("栈中的元素为：\n");
    for (int i = stack->top; i >= 0; i--) {
        if (stack->data[i] != NULL) {
			switch (stack->type[i]) {
			case INT_TYPE:
				printf("%d->", *((int*)stack->data[i]));
				break;
			case FLOAT_TYPE:
				printf("%f->", *((float*)stack->data[i]));
				break;
			case CHAR_TYPE:
				printf("%c->", *((char*)stack->data[i]));
				break;
			case STRING_TYPE:
				printf("%s->", (char*)stack->data[i]);
				break;
			default:
				printf("未知类型\n");
			}
        }
    }
}



//添加元素到栈顶
void pushElement(Stack* stack, void* element, size_t size, DataType dataType) {
	if (isFull(stack)) {
		printf("栈已经满了\n");
		return;
	}

	stack->data[++stack->top] = malloc(size);
	memcpy(stack->data[stack->top], element, size);
	stack->type[stack->top] = dataType;
}

//从栈顶移除元素
void move(Stack* stack) {
	if (isEmpty(stack)) {
		printf("栈已经空了");
			return;
	}
	stack->data[stack->top--];
	printf("移除元素后的栈为：");
	printStackElements(stack);
}

//获取栈顶元素
void get(Stack* stack) {
	if (isEmpty(stack)) {
		printf("栈已经空了");
		return;
	}
	printf("栈顶元素为:");
	printStackElements(stack);
}

//获取栈长
void len(Stack* stack) {
	if (isEmpty(stack)) {
		printf("栈已经空了");
		return;
	}
	printf("栈长为:%d",stack->top+1);
}

//清空栈
void freedom(Stack* stack) {
	stack->top = -1;
	printf("清空成功");
}

//销毁栈
void empty(Stack* stack) {
	while (!isEmpty(stack)) {
		stack->top--;
	}
	printf("销毁成功");
}