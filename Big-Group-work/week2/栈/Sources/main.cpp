#include "function.h"
int main()
{
	Stack stack;   //声明一个栈
	initstack(&stack);//初始化栈

	int choice;   
	//choice用于用户输入合法选项，

	int int_Element;
	float float_Element;
	char char_Element;
	char string_Element[MAX_SIZE];
	void* Element[MAX_SIZE];
	//element用于接受用户添加入栈的元素
	

	char input1[MAX_SIZE];   //用于接受用户的输入结果
	char input2[MAX_SIZE];   //用于接受用户的输入添加元素结果
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
			clear();
			int n;
			printf("输入你要添加的元素的次数\n");
			scanf("%d", &n);
			getchar();
			for (int i = 0; i < n; ) {
				i++;
				printf("输入你要添加的元素\n");

				fgets(input2, sizeof(input2), stdin);
				input2[strcspn(input2, "\n")] = 0;
				//尝试匹配多种格式

				// 尝试匹配整数格式
				if (sscanf_s(input2, "%d", &int_Element) == 1) {

					pushElement(&stack, &int_Element, sizeof(int), INT_TYPE);
				}

				// 尝试匹配浮点数格式
				else if (sscanf_s(input2, "%f", &float_Element) == 1) {
					pushElement(&stack, &float_Element, sizeof(float), FLOAT_TYPE);
				}

				// 尝试匹配字符格式
				else if (sscanf_s(input2, "%c", &char_Element) == 1) {
					pushElement(&stack, &char_Element, sizeof(char), CHAR_TYPE);
				}
				// 尝试匹配字符串格式
				else  {
					size_t len = strlen(input2) + 1; // 包括字符串结束符'\0'
					char* temp_string = (char*)malloc(len);
					strcpy(temp_string, input2);
					pushElement(&stack, temp_string, len, STRING_TYPE);
				}
				
			}
			
			break;
		case 2:
			system("cls");
			move(&stack);
			system("pause");
			break;
		case 3:
			system("cls");
			get(&stack);
			system("pause");
			break;
		case 4:
			system("cls");
			len(&stack);
			system("pause");
			break;
		case 5:
			system("cls");
			printStackElements(&stack);
			system("pause");
			break;
		case 6:
			system("cls");
			freedom(&stack);
			system("pause");
			break;
		case 7:
			system("cls");
			empty(&stack);
			system("pause");
			break;
			
		}
			
	} while (choice != 8);

	return 0;
}