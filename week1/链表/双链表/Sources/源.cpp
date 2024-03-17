#include "function.h"
int main() {
	 ListNode* p = NULL; //p用来存储链表头节点的地址
	char ch;       //ch用于接收选项
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
			printf("成功退出");
			break;
		}

	} while (ch != '6');


	return 0;
}