#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS 
#define MAX_SIZE 100 
//��ʼ����
void welcome() {
    printf("��ܰ��ʾ��������������ʾ�밴enter��\n");
    printf("****��㿴������\n");
    printf("****1.ȷ�����г���\n");
    printf("****2.�鿴��ͷԪ��\n");
    printf("****3.��Ӳ���\n");
    printf("****4.���Ӳ���\n");
    printf("****5.��ն���\n");
    printf("****6.���ٶ���\n");
    printf("****7.��ӡ����\n");
    printf("****8.�˳�����\n");
}

//��������
void clear()
{
    system("cls");
    system("pause");
    system("cls");
}



//������������
typedef enum {
    INT_TYPE,
    FLOAT_TYPE,
    CHAR_TYPE,
    STRING_TYPE
}DataType;

//��ʽ���нṹ
typedef struct node
{
    void* data;                   //������ָ��
    struct node* next;          //ָ��ǰ������һ���
    DataType type[50];        //���������������
} Node;

typedef struct Lqueue
{
    Node* front;                   //��ͷ
    Node* rear;                    //��β
    size_t length;            //���г���
} LQueue;

typedef enum
{
    FALSE = 0, TRUE = 1
} Status;
char type;
char datatype[30];

//������뻺����
void clearInputBuffer()
{
    while (getchar() != '\n');
}

//��ʼ������
void InitLQueue(LQueue* Q) {
    Q->front = Q->rear = NULL;
    Q->length = 0;
}

//�ж϶����Ƿ�Ϊ��
Status IsEmptyLQueue(const LQueue* Q)
{
    return(Q->length == 0)?TRUE:FALSE ;
}


//��ӡ����
void LPrint(LQueue* Q)
{
    if (IsEmptyLQueue(Q)) {
        printf("����Ϊ��\n");
        return;
    }
    printf("������Ԫ��Ϊ��");
    Node* current = Q->front;
    while (current != NULL) {
        printf("%s->", (char*)current->data);
        current = current->next;
    }
}
//ȷ�����г���
int LengthLQueue(LQueue* Q)
{   
    return Q->length;

}
//�鿴��ͷԪ��
Status GetHeadLQueue(LQueue* Q)
{
    if (IsEmptyLQueue(Q)) {
        printf("����Ϊ��\n");
        return FALSE;
    }
    printf("������Ԫ��Ϊ��");
    Node* current = Q->front;
    printf("%s->", (char*)current->data);
    return TRUE;
}

//��Ӳ���
Status EnLQueue(LQueue* Q, void* data, size_t size, DataType dataType)
{
    Node* newNode = (Node*)malloc(sizeof(Node));  //�����½��
    if (!newNode) {
        printf("�ڴ����ʧ��");
            return FALSE;
    }
    //���½��βָ���ÿ�
    newNode->next = NULL;
    newNode->data = data;
    if (Q->rear == NULL) {
        Q->front = Q->rear = newNode;
    }

    else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
    Q->length++;
    printf("��ӳɹ�!");
    return TRUE;
}





//���Ӳ���
Status DeLQueue(LQueue* Q)
{
    if (IsEmptyLQueue(Q)) {
        printf("����Ϊ��\n");
        return FALSE;
    }
    Node* temp = Q->front;  //����һ��ָ��ָ��ͷָ��
    Q->front = Q->front->next;//��ͷָ��ָ���¸����
    free(temp);               //�ͷŵ�ǰ���
    if (Q->front == NULL)
    {
        Q->rear = NULL;
    }
    Q->length--; 
    return TRUE;
}
//��ն���
void ClearLQueue(LQueue* Q)
{
    //���ó����Ѵ���ն���ÿ�����
    while (DeLQueue(Q))
    {
        continue;
    }
}

//���ٶ���
void DestoryLQueue(LQueue* Q)
{
    if (IsEmptyLQueue(Q)) {
        printf("���ٳɹ�");
        return;
    }
    //���ͷ����н�㣬Ȼ������ͷָ���βָ��ָ���
    ClearLQueue(Q);
    Q->front = Q->rear = NULL;
    printf("���ٳɹ�");

}