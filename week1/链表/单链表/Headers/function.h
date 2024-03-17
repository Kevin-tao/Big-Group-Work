#pragma once
#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof (struct Node)

//��ʼ����
void welcome() {
	printf("��ܰ��ʾ��������������ʾ�밴enter��\n");
	printf("****��㿴������****\n");
	printf("****1.����������****\n");
	printf("****2.�����½��****\n");
	printf("****3.�����ض�ֵ****\n");
	printf("****4.ɾ���ض����**\n");
	printf("****5.��ӡ������**\n");
	printf("****6.���������е�**\n");
	printf("****7.�ж�����ɻ�**\n");
	printf("****8.��ת����******\n");
	printf("****9.�˳�����******\n");
	

}

//��������
void clear()
{   
	system("cls");
	system("pause");
	system("cls");
}
//����һ���ṹ��
struct Node {
	int num;         // �ṹ�������
	struct Node* next; //���ָ��
};

//��������
struct Node* creat() {
	int n;//������
	int i = 0;//���ڱ�������
	struct Node* head=(struct Node*)malloc(LEN);  //ͷ���
	struct Node* current=NULL;//�����¿ռ�
	struct Node* prev=head;   //���������ָ��
	head->next = NULL;
	printf("��������Ҫ�����������ȣ�һ����������\n");
	scanf_s("%d", &n);
	while (i < n) {
		i++;
		current = (struct Node*)malloc(LEN);
		printf("��������Ҫ��������ĵ�һ������\n");
		scanf_s("%d", &current->num);
		current->next = NULL;
		prev->next = current;
		prev= current;
	}
	printf("�����ɹ�\n");
	return(head);

}

//�õ������Ⱥ���
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


//��ӡ������
int print(struct Node* head)
{
	if (head == NULL) {
		printf("������δ��������ӡʧ��");
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
			printf("��%d����㣺%d\n", index, p->num);
		}
		return 1;
	}



}


//����������(�����㣩
void run(struct Node* head, int x, int num) {
	struct Node* p = head;
	struct Node* current = NULL;
	int index = 0;

	//��Ҫ�������ǰһ�����λ��
	while (index < x) {
		p = p->next;
		index++;
	}
	current = (struct Node*)malloc(LEN);//�����µĿռ�
	current->num = num;
	current->next = p->next;
	p->next = current;
}


//����������(ɾ����㣩
void ran(struct Node* head, int x) {
	struct Node* p = head;
	struct Node* current = NULL;
	struct Node* prev = NULL;
	int index = 0;

	//��Ҫɾ������ǰһ�����λ��
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


//�����½��
int insert(struct Node* head)
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
		int len=length(head); //�õ�������

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
		} while (x >len);
		printf("������������ݣ�");
		scanf_s("%d",&num);
		system("cls");
		//��ʼ������
		run(head, x - 1,num);
		printf("����ɹ�������");
		print(head);
			return 1;
	}


}


//�����ض�ֵ���
int search(struct Node*head)
{
	if (head == NULL) {
		printf("������δ����������ʧ��\n");
		system("pause");
		system("cls");
		return 0;
	}
	else {
		struct Node* current = head;//���ʵ�����
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
		printf("��ѯ�ɹ�!!!");
		print(head);
		system("cls");
		return 1;

	}

}


//ɾ���ض����
int del(struct Node* head) {
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
		ran(head, x );
		printf("ɾ���ɹ�������");
		print(head);
		system("pause");
		system("cls");
		return 1;
	}
}



//�ҵ�������е�
int mid(struct Node* head)
{
	if (head == NULL) {
		printf("������δ��������ӡʧ��");
		system("pause");
		system("cls");
		return 0;
	}
	else {
		int len = length(head);//�õ�������
		int x = 0;// ��������
		struct Node* current = head->next;
		if (len % 2 != 0) {
			while (x < len / 2) {
				x++;
				current = current->next;
			}
			//��ӡ�����е�
			printf("�����е�Ϊ�����%d��λ�ã�������Ϊ%d", x+1, current->num);
		}
		else {
			while (x < len / 2 - 1) {
				x++;
				current = current->next;
			}
			//��ӡ�����е�
			printf("�����е�Ϊ�����%d����㣺%d,�͵�%d��㣺%d", x + 1, current->num,x+2,current->next->num);
			system("pause");
			system("cls");
		}
		return 1;
	}

}


//�ж�����ɻ�������ָ�뷨��
int judge(struct Node* head)
{   
	if (head == NULL) {
		printf("������δ��������ӡʧ��");
		system("pause");
		system("cls");
		return 0;
	}
	struct Node* fast=head->next;
	struct Node* slow=head;
	while (fast != NULL && fast->next != NULL) {
		if (slow == fast) {
			printf("������ɻ�");
			system("pause");
			system("cls");
			return 0;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	printf("�������ɻ�");
	system("pause");
	system("cls");
	return 0;
}


//��ת����
int  fan(struct Node* head) {
	if (head == NULL) {
		printf("������δ��������ӡʧ��");
		system("pause");
		system("cls");
		return 0;
	}
	struct Node* head1=NULL;//������ͷ���
	struct Node* p = head;
	struct Node* current = (struct Node*)malloc(LEN);//����������Ľ��
	struct Node* prev = NULL;// ��������ָ��
	int index = 0;
	head1 = current; //ʹ������ָ���һ�����
	while (p != NULL) {
		current->num = p->num;  //�����򴫵�
		if(index==0)
		current->next = NULL;
		index++;
		prev = current;
		current = (struct Node*)malloc(LEN);//�����½��
		current->next = prev;
		head1 = current;     //�ƶ�ͷ���
		p = p->next;	     //����ԭ�б�
	}
	//��ӡ��ת����
	print(head1);
	system("pause");
	system("cls");
	return 0;

}



