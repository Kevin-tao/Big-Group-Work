#include "function.h"
int main()
{
	LQueue queue;
	InitLQueue(&queue);



	int choice;
	//choice�����û�����Ϸ�ѡ�

	char string_Element[MAX_SIZE];
	void* Element[MAX_SIZE];
	//element���ڽ����û������ջ��Ԫ��


	char input1[MAX_SIZE];   //���ڽ����û���������
	char input2[MAX_SIZE];   //���ڽ����û����������Ԫ�ؽ��
	char input3[MAX_SIZE];
		char input4[MAX_SIZE];
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
			system("cls");
			printf("���г���Ϊ%d\n", LengthLQueue(&queue));
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
			printf("������Ҫ��ӵ�Ԫ�صĴ���\n");
			scanf("%d", &n1);
			getchar();
			for (int i = 0; i < n1; ) {
				i++;
				printf("������Ҫ��ӵ�Ԫ��\n");
				fgets(input2, sizeof(input2), stdin);
				input2[strcspn(input2, "\n")] = 0;

				size_t len = strlen(input2) + 1; // �����ַ���������'\0'
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
					printf("������Ҫ���ӵĽ��Ĵ���\n");
					scanf("%d", &n2);
				}

				if(i>0) {
					system("cls");
					printf("���ӵĽ�������ڶ��г��ȣ���������Ҫ���ӵĽ��Ĵ���\n");
					scanf("%d", &n2);
				}
				i++;
			} while (n2 >= n3);
			printf("����ɹ�");
			i = 0;
			while (i < n2) {
				DeLQueue(&queue);
				i++;
			}
			printf("\n���ӳɹ�\n");
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
			printf("�˳��ɹ�");
			system("pause");
			break;
			
		}


		

	} while (choice != 8);

	return 0;
}