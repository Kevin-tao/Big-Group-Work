#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS 
#define MAX_SIZE 100  //ջ��
//��ʼ����
void welcome() {
	printf("��ܰ��ʾ��������������ʾ�밴enter��\n");
	printf("****��㿴������\n");
	printf("****1.���Ԫ�ص�ջ��\n");
	printf("****2.��ջ���Ƴ�Ԫ��\n");
	printf("****3.��ȡջ��Ԫ��\n");
	printf("****4.��ȡջ�Ĵ�С\n");
	printf("****5.���ջ\n");
	printf("****6.���ջ\n");
	printf("****7.����ջ\n");
	printf("****8.�˳�����\n");
}


//��������
void clear()
{
	system("cls");
	system("pause");
	system("cls");
}


//������뻺����
void clearInputBuffer()
{
	while (getchar() != '\n');
}

//������������
typedef enum {
	INT_TYPE,
	FLOAT_TYPE,
	CHAR_TYPE,
	STRING_TYPE
}DataType;

//����һ��ջ
typedef struct {
	void* data[MAX_SIZE];// ����Ϊ�κ����͵�������
	int top;             // ��ջ
	DataType type[MAX_SIZE];            //��������
}Stack;

//��ʼ��ջ
void initstack(Stack* stack)
{
	stack->top =-1;
}
// �ж�ջ�Ƿ�Ϊ��
int isEmpty(Stack* stack) {
	return (stack->top == -1);
}

//�ж�ջ�Ƿ�����
int isFull(Stack* stack) {
	return(stack->top == MAX_SIZE - 1);
}



// ���ջ�е�ȫ��Ԫ��
void printStackElements(Stack* stack) {
    if (isEmpty(stack)) {
        printf("ջΪ��\n");
        return;
    }

    printf("ջ�е�Ԫ��Ϊ��\n");
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
				printf("δ֪����\n");
			}
        }
    }
}



//���Ԫ�ص�ջ��
void pushElement(Stack* stack, void* element, size_t size, DataType dataType) {
	if (isFull(stack)) {
		printf("ջ�Ѿ�����\n");
		return;
	}

	stack->data[++stack->top] = malloc(size);
	memcpy(stack->data[stack->top], element, size);
	stack->type[stack->top] = dataType;
}

//��ջ���Ƴ�Ԫ��
void move(Stack* stack) {
	if (isEmpty(stack)) {
		printf("ջ�Ѿ�����");
			return;
	}
	stack->data[stack->top--];
	printf("�Ƴ�Ԫ�غ��ջΪ��");
	printStackElements(stack);
}

//��ȡջ��Ԫ��
void get(Stack* stack) {
	if (isEmpty(stack)) {
		printf("ջ�Ѿ�����");
		return;
	}
	printf("ջ��Ԫ��Ϊ:");
	printStackElements(stack);
}

//��ȡջ��
void len(Stack* stack) {
	if (isEmpty(stack)) {
		printf("ջ�Ѿ�����");
		return;
	}
	printf("ջ��Ϊ:%d",stack->top+1);
}

//���ջ
void freedom(Stack* stack) {
	stack->top = -1;
	printf("��ճɹ�");
}

//����ջ
void empty(Stack* stack) {
	while (!isEmpty(stack)) {
		stack->top--;
	}
	printf("���ٳɹ�");
}