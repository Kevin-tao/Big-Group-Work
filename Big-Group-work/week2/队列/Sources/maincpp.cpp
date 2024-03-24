#include "function.h"
int main()
{
	LQueue queue;
	InitLQueue(&queue);



	int choice;
	//choice用于用户输入合法选项，

	char string_Element[MAX_SIZE];
	void* Element[MAX_SIZE];
	//element用于接受用户添加入栈的元素


	char input1[MAX_SIZE];   //用于接受用户的输入结果
	char input2[MAX_SIZE];   //用于接受用户的输入添加元素结果
	char input3[MAX_SIZE];
		char input4[MAX_SIZE];
	//do-while循环生成开始界面
	do {
		system("cls");
		welcome();
		//判断是否成功读入用户的输入
		if (fgets(input1, sizeof(input1), stdin) == NULL)
			break;
		//判断用户输入选项是否合法
		if (sscanf_s(input1, "%d", &choice) != 1) {
			printf("错误的选项，请按回车键并重新输入你的选项\n");
			clearInputBuffer();
			continue;
		}
		//读入用户选项合法后
		switch (choice)
		{
		case 1:
			system("cls");
			printf("队列长度为%d\n", LengthLQueue(&queue));
			system("pause");
			break;
		case 2:
			system("cls");
			GetHeadLQueue(&queue);
			system("pause");
			break;
		case 3:
			system("cls");
			int n1;
			printf("输入你要入队的元素的次数\n");
			scanf("%d", &n1);
			getchar();
			for (int i = 0; i < n1; ) {
				i++;
				printf("输入你要添加的元素\n");
				fgets(input2, sizeof(input2), stdin);
				input2[strcspn(input2, "\n")] = 0;

				size_t len = strlen(input2) + 1; // 包括字符串结束符'\0'
				char* temp_string = (char*)malloc(len);
				strcpy(temp_string, input2);
				EnLQueue(&queue, temp_string, len, STRING_TYPE);
			}
			system("pause");
			break;
		case 4:
			system("cls");
			{int n2,n3;
			int i = 0;
			n3 = LengthLQueue(&queue);
			do {
				if (i == 0) {
					printf("输入你要出队的结点的次数\n");
					scanf("%d", &n2);
				}

				if(i>0) {
					system("cls");
					printf("出队的结点数大于队列长度，请输入你要出队的结点的次数\n");
					scanf("%d", &n2);
				}
				i++;
			} while (n2 >= n3);
			printf("输入成功");
			i = 0;
			while (i < n2) {
				DeLQueue(&queue);
				i++;
			}
			printf("\n出队成功\n");
			getchar();
			LPrint(&queue);
			}
			system("pause");
			break;
		case 5:
			system("cls");
			DestoryLQueue(&queue);
			system("pause");
			break;
		case 6:
			system("cls");
			ClearLQueue(&queue);
			system("pause");
			break;
		case 7:
			system("cls");
			LPrint(&queue);
			system("pause");
			break;
		case 8:
			system("cls");
			printf("退出成功");
			system("pause");
			break;
			
		}


		

	} while (choice != 8);

	return 0;
}