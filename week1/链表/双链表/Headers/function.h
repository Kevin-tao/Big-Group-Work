#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>



//��ʼ����
void welcome() {
	printf("��ܰ��ʾ��������������ʾ�밴enter��\n");
	printf("****��㿴������****\n");
	printf("****1.����˫����****\n");
	printf("****2.�����½��****\n");
	printf("****3.�����ض�ֵ****\n");
	printf("****4.ɾ���ض����**\n");
	printf("****5.��ӡ������**\n");
	printf("****6.�˳�����******\n");


}

//��������
void clear()
{
	system("cls");
	system("pause");
	system("cls");
}

//�����ṹ��
typedef struct ListNode
{
	int num;
	struct ListNode* prior; //ָ��ǰһ������ָ��
	struct ListNode* next;  //ָ���һ������ָ��
}ListNode;

//˳���ӡ����
int print1(ListNode* head)
{
	if (head == NULL) {
		printf("������δ��������ӡʧ��");
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
//�����ӡ����
int print2(ListNode* head)
{
	if (head == NULL) {
		printf("������δ��������ӡʧ��");
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
//��ӡ˳�����������
void print3(ListNode* head1, ListNode* head2)
{
	printf("˳������Ϊ��");
	print1(head1);  //˳���ӡ����
	printf("\n��������Ϊ��");
	print2(head2);//�����ӡ����
	printf("\n");
}

//��������
ListNode* creat()
{ 
	int n;//������
	int i = 0;//���ڱ�������
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));//����ͷ���
	ListNode* current = NULL;//�����¿ռ�
	ListNode* prev = head;   //���������ָ��
	head->prior = NULL;
	printf("��������Ҫ�����������ȣ�һ����������\n");
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
		printf("��������Ҫ��������ĵ�һ������\n");
		scanf_s("%d", &current->num);
		current->next = NULL;
		prev= current;
	}
	system("cls");
	print3(head, current);
	system("pause");
	return head;
}

// �õ������Ⱥ���
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

//����������(�����㣩
void run(ListNode* head, int x, int num) {
	ListNode* p = head;
	ListNode* current = NULL;
	int index = 0;

	//��Ҫ������ĺ�һ�����λ��
	while (index < x) {
		p = p->next;
		index++;
	}
	current = (ListNode*)malloc(sizeof(ListNode));//�����µĿռ�
	current->num = num;
	p->prior->next = current;
	current->prior = p->prior;
	current->next = p;
	p->prior = current;
}

//����������(ɾ����㣩
void ran(ListNode* head, int x) {
	ListNode* p = head;
	ListNode* current = NULL;
	ListNode* prev = NULL;
	int index = 0;

	//��Ҫɾ������ǰһ�����λ��
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
//�����½��
int insert(ListNode* head)
{
	if (head == NULL) {
		printf("������δ����������ʧ��");
		system("pause");
		system("cls");
		return 0;
	}
	else {
		int x = 0;       //�����û������ֵ
		int index = 0;   //�жϳ���
		int num;         //����������
		int len = length(head); //�õ�������

		//ѡ�����λ��
		do {
			if (index == 0) {
				index++;
				printf("����ĳ���Ϊ%d,��������Ҫ�����λ��:", len);
				scanf_s("%d", &x);
				system("cls");
			}
			else {
				printf("����ĳ���Ϊ%d,��ѡ��λ�ó����������ȣ�������ѡ��", len);
				scanf_s("%d", &x);
				system("cls");
			}
		} while (x > len);
		printf("������������ݣ�");
		scanf_s("%d", &num);
		system("cls");
		//��ʼ������
		run(head, x+1, num);
		printf("����ɹ�������");
		print1(head);
		system("pause");
		system("cls");
		return 1;
	}


}

//�����ض�ֵ���
int search( ListNode* head)
{
	if (head == NULL) {
		printf("������δ����������ʧ��\n");
		system("pause");
		system("cls");
		return 0;
	}
	else {
		ListNode* current = head;//���ʵ�����
		int num;  //���������
		int i = 0;//�õ����λ��
		printf("��������Ҫ���ҵ�ֵ��");
		scanf_s("%d", &num);
		system("cls");
		while (current != NULL) {
			current = current->next;
			i++;
			if (num == current->num)
				printf("���λ�ã�%d", i);
		}
		printf("\n��ѯ�ɹ�!!!\n");
		system("pause");
		system("cls");
		return 1;

	}

}
//ɾ���ض����
int del(ListNode* head) {
	if (head == NULL) {
		printf("������δ������ɾ��ʧ��");
		system("pause");
		system("cls");
		return 0;
	}
	else {
		int x = 0;       //�����û������ֵ
		int index = 0;   //�жϳ���
		int len = length(head); //�õ�������

		//ѡ��ɾ��λ��
		do {
			if (index == 0) {
				index++;
				printf("����ĳ���Ϊ%d,��������Ҫɾ����λ��:", len);
				scanf_s("%d", &x);
				system("cls");
			}
			else {
				printf("����ĳ���Ϊ%d,��ѡ��λ�ó����������ȣ�������ѡ��", len);
				scanf_s("%d", &x);
				system("cls");
			}
		} while (x > len);
		//��ʼɾ�����
		ran(head, x);
		printf("ɾ���ɹ�������\n");
		print1(head);
		system("pause");
		system("cls");
		return 1;
	}
}
