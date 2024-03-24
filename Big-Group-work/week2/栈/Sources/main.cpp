#include "function.h"
int main()
{
	Stack stack;   //����һ��ջ
	initstack(&stack);//��ʼ��ջ

	int choice;   
	//choice�����û�����Ϸ�ѡ�

	int int_Element;
	float float_Element;
	char char_Element;
	char string_Element[MAX_SIZE];
	void* Element[MAX_SIZE];
	//element���ڽ����û������ջ��Ԫ��
	

	char input1[MAX_SIZE];   //���ڽ����û���������
	char input2[MAX_SIZE];   //���ڽ����û����������Ԫ�ؽ��
	//do-whileѭ�����ɿ�ʼ����
	do {
		system("cls");
		welcome();
		//�ж��Ƿ�ɹ������û�������
		if (fgets(input1, sizeof(input1), stdin) == NULL)
			break;
		//�ж��û�����ѡ���Ƿ�Ϸ�
		if (sscanf_s(input1, "%d", &choice) != 1) {
			printf("�����ѡ��밴�س����������������ѡ��\n");
			clearInputBuffer();
			continue;
		}
		//�����û�ѡ��Ϸ���
		switch (choice)
		{
		case 1:
			clear();
			int n;
			printf("������Ҫ��ӵ�Ԫ�صĴ���\n");
			scanf("%d", &n);
			getchar();
			for (int i = 0; i < n; ) {
				i++;
				printf("������Ҫ��ӵ�Ԫ��\n");

				fgets(input2, sizeof(input2), stdin);
				input2[strcspn(input2, "\n")] = 0;
				//����ƥ����ָ�ʽ

				// ����ƥ��������ʽ
				if (sscanf_s(input2, "%d", &int_Element) == 1) {

					pushElement(&stack, &int_Element, sizeof(int), INT_TYPE);
				}

				// ����ƥ�両������ʽ
				else if (sscanf_s(input2, "%f", &float_Element) == 1) {
					pushElement(&stack, &float_Element, sizeof(float), FLOAT_TYPE);
				}

				// ����ƥ���ַ���ʽ
				else if (sscanf_s(input2, "%c", &char_Element) == 1) {
					pushElement(&stack, &char_Element, sizeof(char), CHAR_TYPE);
				}
				// ����ƥ���ַ�����ʽ
				else  {
					size_t len = strlen(input2) + 1; // �����ַ���������'\0'
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