#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS 
#define MAX_SIZE 100 
//开始界面
void welcome() {
    printf("温馨提示：程序运行无提示请按enter键\n");
    printf("****随便看看就行\n");
    printf("****1.确定队列长度\n");
    printf("****2.查看队头元素\n");
    printf("****3.入队操作\n");
    printf("****4.出队操作\n");
    printf("****5.清空队列\n");
    printf("****6.销毁队列\n");
    printf("****7.打印队列\n");
    printf("****8.退出界面\n");
}

//清屏函数
void clear()
{
    system("cls");
    system("pause");
    system("cls");
}



//定义数据类型
typedef enum {
    INT_TYPE,
    FLOAT_TYPE,
    CHAR_TYPE,
    STRING_TYPE
}DataType;

//链式队列结构
typedef struct node
{
    void* data;                   //数据域指针
    struct node* next;          //指向当前结点的下一结点
    DataType type[50];        //数据域的数据类型
} Node;

typedef struct Lqueue
{
    Node* front;                   //队头
    Node* rear;                    //队尾
    size_t length;            //队列长度
} LQueue;

typedef enum
{
    FALSE = 0, TRUE = 1
} Status;
char type;
char datatype[30];

//清空输入缓存区
void clearInputBuffer()
{
    while (getchar() != '\n');
}

//初始化队列
void InitLQueue(LQueue* Q) {
    Q->front = Q->rear = NULL;
    Q->length = 0;
}

//判断队列是否为空
Status IsEmptyLQueue(const LQueue* Q)
{
    return(Q->length == 0)?TRUE:FALSE ;
}


//打印函数
void LPrint(LQueue* Q)
{
    if (IsEmptyLQueue(Q)) {
        printf("队列为空\n");
        return;
    }
    printf("队列中元素为：");
    Node* current = Q->front;
    while (current != NULL) {
        printf("%s->", (char*)current->data);
        current = current->next;
    }
}
//确定队列长度
int LengthLQueue(LQueue* Q)
{   
    return Q->length;

}
//查看队头元素
Status GetHeadLQueue(LQueue* Q)
{
    if (IsEmptyLQueue(Q)) {
        printf("队列为空\n");
        return FALSE;
    }
    printf("队列中元素为：");
    Node* current = Q->front;
    printf("%s->", (char*)current->data);
    return TRUE;
}

//入队操作
Status EnLQueue(LQueue* Q, void* data, size_t size, DataType dataType)
{
    Node* newNode = (Node*)malloc(sizeof(Node));  //创建新结点
    if (!newNode) {
        printf("内存分配失败");
            return FALSE;
    }
    //让新结点尾指针置空
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
    printf("入队成功!");
    return TRUE;
}





//出队操作
Status DeLQueue(LQueue* Q)
{
    if (IsEmptyLQueue(Q)) {
        printf("队列为空\n");
        return FALSE;
    }
    Node* temp = Q->front;  //定义一个指针指向头指针
    Q->front = Q->front->next;//让头指针指向下个结点
    free(temp);               //释放当前结点
    if (Q->front == NULL)
    {
        Q->rear = NULL;
    }
    Q->length--; 
    return TRUE;
}
//清空队列
void ClearLQueue(LQueue* Q)
{
    //利用出队已达清空队列每个结点
    while (DeLQueue(Q))
    {
        continue;
    }
}

//销毁队列
void DestoryLQueue(LQueue* Q)
{
    if (IsEmptyLQueue(Q)) {
        printf("销毁成功");
        return;
    }
    //先释放所有结点，然后再让头指针和尾指针指向空
    ClearLQueue(Q);
    Q->front = Q->rear = NULL;
    printf("销毁成功");

}