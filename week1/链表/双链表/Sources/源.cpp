#include "function.h"
int main() {
	 ListNode* p = NULL; //p�����洢����ͷ�ڵ�ĵ�ַ
	char ch;       //ch���ڽ���ѡ��
	do {
		welcome();
		ch = getchar();
		switch (ch) {
		case '1':
			clear();
			p = creat();
			system("cls");
			getchar();
			break;
		case '2':
			clear();
			insert(p);
			getchar();
			break;
		case '3':
			clear();
			search(p);
			getchar();
			break;
		case '4':
			clear();
			del(p);
			getchar();
			break;
		case '5':
			clear();
			print1(p);
			getchar();
			break;
		case '6':
			clear();
			printf("�ɹ��˳�");
			break;
		}

	} while (ch != '6');


	return 0;
}