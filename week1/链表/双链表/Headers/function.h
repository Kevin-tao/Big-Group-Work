#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>



//开始界面
void welcome() {
	printf("温馨提示：程序运行无提示请按enter键\n");
	printf("****随便看看就行****\n");
	printf("****1.创建双链表****\n");
	printf("****2.插入新结点****\n");
	printf("****3.访问特定值****\n");
	printf("****4.删除特定结点**\n");
	printf("****5.打印链表函数**\n");
	printf("****6.退出界面******\n");


}

//清屏函数
void clear()
{
	system("cls");
	system("pause");
	system("cls");
}

//创建结构体
typedef struct ListNode
{
	int num;
	struct ListNode* prior; //指向前一个结点的指针
	struct ListNode* next;  //指向后一个结点的指针
}ListNode;

//顺向打印链表
int print1(ListNode* head)
{
	if (head == NULL) {
		printf("该链表还未创立，打印失败");
		system("pause");
		system("cls");
		return 0;
	}

	ListNode* p = head;
	int index = 0;
	while (p->next != NULL) {
		p = p->next;
		index++;
		printf("%d->", p->num);
	}
	return 0;
}
//逆向打印链表
int print2(ListNode* head)
{
	if (head == NULL) {
		printf("该链表还未创立，打印失败");
		system("pause");
		system("cls");
		return 0;
	}

	ListNode* p = head;
	int index = 0;
	while (p->prior!= NULL) {
		index++;
		printf("%d->", p->num);
		p = p->prior;
	}
	return 0;
}
//打印顺向和逆向链表
void print3(ListNode* head1, ListNode* head2)
{
	printf("顺向链表为：");
	print1(head1);  //顺向打印链表
	printf("\n逆向链表为：");
	print2(head2);//逆向打印链表
	printf("\n");
}

//创建链表
ListNode* creat()
{ 
	int n;//链表长度
	int i = 0;//用于遍历链表
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));//创立头结点
	ListNode* current = NULL;//开辟新空间
	ListNode* prev = head;   //遍历链表的指针
	head->prior = NULL;
	printf("请输入你要创建的链表长度（一个正整数）\n");
	scanf_s("%d", &n);
	while (i < n) {
		i++;
		current = (ListNode*)malloc(sizeof(ListNode));
		if (i == 1) {
			head->next = current;
			current->prior = head;
		}
		else {
			prev->next = current;
			current->prior = prev;
		}
		printf("请输入你要存于链表的的一个数字\n");
		scanf_s("%d", &current->num);
		current->next = NULL;
		prev= current;
	}
	system("cls");
	print3(head, current);
	system("pause");
	return head;
}

// 得到链表长度函数
int length(ListNode* head)
{
	ListNode* p = head;
	int i = 0;
	while (p->next != NULL) {
		i++;
		p = p->next;
	}
	return i;
}

//遍历链表函数(插入结点）
void run(ListNode* head, int x, int num) {
	ListNode* p = head;
	ListNode* current = NULL;
	int index = 0;

	//到要插入结点的后一个结点位置
	while (index < x) {
		p = p->next;
		index++;
	}
	current = (ListNode*)malloc(sizeof(ListNode));//开辟新的空间
	current->num = num;
	p->prior->next = current;
	current->prior = p->prior;
	current->next = p;
	p->prior = current;
}

//遍历链表函数(删除结点）
void ran(ListNode* head, int x) {
	ListNode* p = head;
	ListNode* current = NULL;
	ListNode* prev = NULL;
	int index = 0;

	//到要删除结点的前一个结点位置
	while (index < x) {
		prev = p;
		p = p->next;
		index++;
	}
	current = p;
	if (prev->next!= NULL) {
		prev->next = p->next;
		p->next->prior = prev;
	}
		
	else
		head = p->next;
	free(p);

}
//插入新结点
int insert(ListNode* head)
{
	if (head == NULL) {
		printf("该链表还未创立，插入失败");
		system("pause");
		system("cls");
		return 0;
	}
	else {
		int x = 0;       //接受用户输入的值
		int index = 0;   //判断出错
		int num;         //链表数据域
		int len = length(head); //得到链表长度

		//选择插入位置
		do {
			if (index == 0) {
				index++;
				printf("链表的长度为%d,请输入你要插入的位置:", len);
				scanf_s("%d", &x);
				system("cls");
			}
			else {
				printf("链表的长度为%d,您选的位置超过了链表长度，请重新选择", len);
				scanf_s("%d", &x);
				system("cls");
			}
		} while (x > len);
		printf("请输入你的数据：");
		scanf_s("%d", &num);
		system("cls");
		//开始插入结点
		run(head, x+1, num);
		printf("插入成功！！！");
		print1(head);
		system("pause");
		system("cls");
		return 1;
	}


}

//访问特定值结点
int search( ListNode* head)
{
	if (head == NULL) {
		printf("该链表还未创立，插入失败\n");
		system("pause");
		system("cls");
		return 0;
	}
	else {
		ListNode* current = head;//访问到链表
		int num;  //结点数据域
		int i = 0;//得到结点位置
		printf("请输入你要查找的值：");
		scanf_s("%d", &num);
		system("cls");
		while (current != NULL) {
			current = current->next;
			i++;
			if (num == current->num)
				printf("结点位置：%d", i);
		}
		printf("\n查询成功!!!\n");
		system("pause");
		system("cls");
		return 1;

	}

}
//删除特定结点
int del(ListNode* head) {
	if (head == NULL) {
		printf("该链表还未创立，删除失败");
		system("pause");
		system("cls");
		return 0;
	}
	else {
		int x = 0;       //接受用户输入的值
		int index = 0;   //判断出错
		int len = length(head); //得到链表长度

		//选择删除位置
		do {
			if (index == 0) {
				index++;
				printf("链表的长度为%d,请输入你要删除的位置:", len);
				scanf_s("%d", &x);
				system("cls");
			}
			else {
				printf("链表的长度为%d,您选的位置超过了链表长度，请重新选择", len);
				scanf_s("%d", &x);
				system("cls");
			}
		} while (x > len);
		//开始删除结点
		ran(head, x);
		printf("删除成功！！！\n");
		print1(head);
		system("pause");
		system("cls");
		return 1;
	}
}
