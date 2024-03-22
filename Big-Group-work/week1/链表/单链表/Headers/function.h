#pragma once
#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof (struct Node)

//开始界面
void welcome() {
	printf("温馨提示：程序运行无提示请按enter键\n");
	printf("****随便看看就行****\n");
	printf("****1.创建单链表****\n");
	printf("****2.插入新结点****\n");
	printf("****3.访问特定值****\n");
	printf("****4.删除特定结点**\n");
	printf("****5.打印链表函数**\n");
	printf("****6.查找链表中点**\n");
	printf("****7.判断链表成环**\n");
	printf("****8.反转链表******\n");
	printf("****9.退出界面******\n");
	

}

//清屏函数
void clear()
{   
	system("cls");
	system("pause");
	system("cls");
}
//定义一个结构体
struct Node {
	int num;         // 结构体结点序号
	struct Node* next; //结点指针
};

//创建链表
struct Node* creat() {
	int n;//链表长度
	int i = 0;//用于遍历链表
	struct Node* head=(struct Node*)malloc(LEN);  //头结点
	struct Node* current=NULL;//开辟新空间
	struct Node* prev=head;   //遍历链表的指针
	head->next = NULL;
	printf("请输入你要创建的链表长度（一个正整数）\n");
	scanf_s("%d", &n);
	while (i < n) {
		i++;
		current = (struct Node*)malloc(LEN);
		printf("请输入你要存于链表的的一个数字\n");
		scanf_s("%d", &current->num);
		current->next = NULL;
		prev->next = current;
		prev= current;
	}
	printf("创建成功\n");
	return(head);

}

//得到链表长度函数
int length(struct Node* head)
{
	struct Node* p = head;
	int i = 0;
	while (p->next != NULL) {
		i++;
		p = p->next;
	}
	return i;
}


//打印链表函数
int print(struct Node* head)
{
	if (head == NULL) {
		printf("该链表还未创立，打印失败");
		system("pause");
		system("cls");
		return 0;
	}
	else {
		struct Node* p = head;
		int index = 0;
		while (p->next != NULL) {
			p = p->next;
			index++;
			printf("第%d个结点：%d\n", index, p->num);
		}
		return 1;
	}



}


//遍历链表函数(插入结点）
void run(struct Node* head, int x, int num) {
	struct Node* p = head;
	struct Node* current = NULL;
	int index = 0;

	//到要插入结点的前一个结点位置
	while (index < x) {
		p = p->next;
		index++;
	}
	current = (struct Node*)malloc(LEN);//开辟新的空间
	current->num = num;
	current->next = p->next;
	p->next = current;
}


//遍历链表函数(删除结点）
void ran(struct Node* head, int x) {
	struct Node* p = head;
	struct Node* current = NULL;
	struct Node* prev = NULL;
	int index = 0;

	//到要删除结点的前一个结点位置
	while (index < x) {
		prev= p;
		p = p->next;
		index++;
	}
	current = p;
	if (prev != NULL)
		prev->next = p->next;
	else
		head= p->next;
	free(p);

}


//插入新结点
int insert(struct Node* head)
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
		int len=length(head); //得到链表长度

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
		} while (x >len);
		printf("请输入你的数据：");
		scanf_s("%d",&num);
		system("cls");
		//开始插入结点
		run(head, x - 1,num);
		printf("插入成功！！！");
		print(head);
			return 1;
	}


}


//访问特定值结点
int search(struct Node*head)
{
	if (head == NULL) {
		printf("该链表还未创立，插入失败\n");
		system("pause");
		system("cls");
		return 0;
	}
	else {
		struct Node* current = head;//访问到链表
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
		printf("查询成功!!!");
		print(head);
		system("cls");
		return 1;

	}

}


//删除特定结点
int del(struct Node* head) {
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
		ran(head, x );
		printf("删除成功！！！");
		print(head);
		system("pause");
		system("cls");
		return 1;
	}
}



//找单链表的中点
int mid(struct Node* head)
{
	if (head == NULL) {
		printf("该链表还未创立，打印失败");
		system("pause");
		system("cls");
		return 0;
	}
	else {
		int len = length(head);//得到链表长度
		int x = 0;// 遍历链表
		struct Node* current = head->next;
		if (len % 2 != 0) {
			while (x < len / 2) {
				x++;
				current = current->next;
			}
			//打印链表中点
			printf("链表中点为链表第%d个位置，数据域为%d", x+1, current->num);
		}
		else {
			while (x < len / 2 - 1) {
				x++;
				current = current->next;
			}
			//打印链表中点
			printf("链表中点为链表第%d个结点：%d,和第%d结点：%d", x + 1, current->num,x+2,current->next->num);
			system("pause");
			system("cls");
		}
		return 1;
	}

}


//判断链表成环（快慢指针法）
int judge(struct Node* head)
{   
	if (head == NULL) {
		printf("该链表还未创立，打印失败");
		system("pause");
		system("cls");
		return 0;
	}
	struct Node* fast=head->next;
	struct Node* slow=head;
	while (fast != NULL && fast->next != NULL) {
		if (slow == fast) {
			printf("该链表成环");
			system("pause");
			system("cls");
			return 0;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	printf("该链表不成环");
	system("pause");
	system("cls");
	return 0;
}


//反转链表
int  fan(struct Node* head) {
	if (head == NULL) {
		printf("该链表还未创立，打印失败");
		system("pause");
		system("cls");
		return 0;
	}
	struct Node* head1=NULL;//新链表头结点
	struct Node* p = head;
	struct Node* current = (struct Node*)malloc(LEN);//开辟新链表的结点
	struct Node* prev = NULL;// 遍历链表指针
	int index = 0;
	head1 = current; //使新链表指向第一个结点
	while (p != NULL) {
		current->num = p->num;  //数据域传递
		if(index==0)
		current->next = NULL;
		index++;
		prev = current;
		current = (struct Node*)malloc(LEN);//开辟新结点
		current->next = prev;
		head1 = current;     //移动头结点
		p = p->next;	     //遍历原列表
	}
	//打印反转链表
	print(head1);
	system("pause");
	system("cls");
	return 0;

}



