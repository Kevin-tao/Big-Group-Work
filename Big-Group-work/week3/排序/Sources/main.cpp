#include "function.h"
int main()
{
	int choice;
	
	//choice�����û�����Ϸ�ѡ�

	int n = 0;//�ж��û��Ƿ�����������

	int n1 = 100000, n2 = 10000, n3 = 50000,n4=100;
	//��ͬ��������


	int arr1[100001];
	int arr2[10001];
	int arr3[50001];
	int arr4[101];


	char input1[MAX_SIZE];   //���ڽ����û���������
	//do-whileѭ�����ɿ�ʼ����2 

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
	switch (choice)
	{
		case 1:
			clear();
			printf("���������������\n");
			creatdata(n1, "test1");
			creatdata(n2, "test2");
			creatdata(n3, "test3");
			creatdata(n4, "test4");
			system("pause");
			system("cls");
			printf("���ɳɹ�\n");
			system("pause");
			system("cls");
			n = 1;
			break;
		case 2:
			if (n == 1) {
				printf("���ڶ�ȡ����.....");
				readdata(arr1, n1, "test1");
				readdata(arr2, n2, "test2");
				readdata(arr3, n3, "test3");
				readdata(arr4, n4, "test4");
				printf("��ȡ�ɹ�\n");
				system("pause");
				system("cls");
				printf("���ڼ�����......");

				//��¼����ʱ������
				clock_t start1, end1;

				//��ʼ��ʱ
				start1 = clock();

				merge(arr1, 0, n1);
				//����
				end1 = clock();
				double value1 = (double)((end1 - start1) / CLOCKS_PER_SEC);
				//��¼����ʱ������
				clock_t start2, end2;

				//��ʼ��ʱ
				start2 = clock();

				merge(arr2, 0, n2);
				//����
				end2 = clock();
				double value2 = (double)((end2 - start2) / CLOCKS_PER_SEC);
				//��¼����ʱ������
				clock_t start3, end3;

				//��ʼ��ʱ
				start3 = clock();

			merge(arr3, 0, n3);
				//����
				end3 = clock();
				double value3 = (double)((end3 - start3) / CLOCKS_PER_SEC);
				
				//��¼����ʱ������
				clock_t start4, end4;
				//��ʼ��ʱ
				start4 = clock();
				for (int i = 0; i < n4; i++) {
					merge(arr4, 0, n4);
				}
				end4 = clock();
				double value4 = (double)((end4 - start4) / CLOCKS_PER_SEC);
				system("cls");
				printf("�鲢����%d�����ݵĺ�ʱΪ��%lf\n", n1, value1);
				printf("�鲢����%d�����ݵĺ�ʱΪ��%lf\n", n2, value2);
				printf("�鲢����%d�����ݵĺ�ʱΪ��%lf\n", n3, value3);
				printf("�鲢����%d������100�εĺ�ʱΪ��%lf\n", n4, value4);
				putdata(arr1, n1, "testmerge1.finish");
				putdata(arr2, n2, "testmerge2.finish");
				putdata(arr3, n3, "testmerge3.finish");
				putdata(arr4, n4, "testmerge4.finish");
				system("pause");
				system("cls");
			}
			else {
				printf("���ݻ�δ���ɣ�������������\n");
				system("pause");
				system("cls");
			}
			break;
		case 3:
			if (n == 1) {
				printf("���ڶ�ȡ����.....");
				readdata(arr1, n1, "test1");
				readdata(arr2, n2, "test2");
				readdata(arr3, n3, "test3");
				readdata(arr4, n4, "test4");
				printf("��ȡ�ɹ�\n");
				system("pause");
				system("cls");
				printf("���ڼ�����......");
				double value1 = Insertsort(arr1, n1, "test1");
				double value2 = Insertsort(arr2, n2, "test1");
				double value3 = Insertsort(arr3, n3, "test1");

				//��¼����ʱ������
				clock_t start4, end4;
				//��ʼ��ʱ
				start4= clock();
				for (int i = 0; i < n4; i++) {
					merge(arr4, 0, n4);
				}
				end4 = clock();
				double value4 = (double)((end4 - start4) / CLOCKS_PER_SEC);
				system("cls");
				printf("��������%d�����ݵĺ�ʱΪ��%lf\n", n1, value1);
				printf("��������%d�����ݵĺ�ʱΪ��%lf\n", n2, value2);
				printf("��������%d�����ݵĺ�ʱΪ��%lf\n", n3, value3);
				printf("��������%d������100�εĺ�ʱΪ��%lf\n", n4, value4);
				putdata(arr1, n1, "testinsert1.finish");
				putdata(arr2, n2, "testinsert2.finish");
				putdata(arr3, n3, "testinsert3.finish");
				putdata(arr4, n4, "testinsert4.finish");
				system("pause");
				system("cls");
			}
			else {
				printf("���ݻ�δ���ɣ�������������\n");
				system("pause");
				system("cls");
			}
			break;
		case 4:
			if (n == 1) {
				printf("���ڶ�ȡ����.....");
				readdata(arr1, n1, "test1");
				readdata(arr2, n2, "test2");
				readdata(arr3, n3, "test3");
				readdata(arr4, n4, "test4");
				printf("��ȡ�ɹ�\n");
				system("pause");
				system("cls");
				printf("���ڼ�����......");
				
				//��¼����ʱ������
				clock_t start1, end1;
				
				//��ʼ��ʱ
				start1 = clock();

				QuickSort(arr1, 0, n1-1);
				//����
				end1 = clock();
				double value1 = (double)((end1 - start1) / CLOCKS_PER_SEC);
				//��¼����ʱ������
				clock_t start2, end2;

				//��ʼ��ʱ
				start2 = clock();

				QuickSort(arr2, 0, n2-1);
				//����
				end2 = clock();
				double value2 = (double)((end2 - start2) / CLOCKS_PER_SEC);
				//��¼����ʱ������
				clock_t start3, end3;

				//��ʼ��ʱ
				start3 = clock();

				QuickSort(arr3, 0, n3-1);
				//����
				end3 = clock();
				double value3 = (double)((end3 - start3) / CLOCKS_PER_SEC);

				//��¼����ʱ������
				clock_t start4, end4;
				//��ʼ��ʱ
				start4 = clock();
				for (int i = 0; i < n4; i++) {
					QuickSort(arr4, 0, n4);
				}
				end4 = clock();
				double value4 = (double)((end4 - start4) / CLOCKS_PER_SEC);
				system("cls");
				printf("��������%d�����ݵĺ�ʱΪ��%lf\n", n1,value1);
				printf("��������%d�����ݵĺ�ʱΪ��%lf\n", n2, value2);
				printf("��������%d�����ݵĺ�ʱΪ��%lf\n", n3, value3);
				printf("��������%d������100�εĺ�ʱΪ��%lf\n", n4, value4);
				putdata(arr1, n1, "testfast1.finish");
				putdata(arr2, n2, "testfast2.finish");
				putdata(arr3, n3, "testfast3.finish");
				putdata(arr4, n4, "testfast4.finish");
				system("pause");
				system("cls");
			}
			else {
				printf("���ݻ�δ���ɣ�������������\n");
				system("pause");
				system("cls");
			}
			break;
		case 5:
			if (n == 1) {
				printf("���ڶ�ȡ����.....");
				readdata(arr1, n1, "test1");
				readdata(arr2, n2, "test2");
				readdata(arr3, n3, "test3");
				readdata(arr4, n4, "test4");
				printf("��ȡ�ɹ�\n");
				system("pause");
				system("cls");
				printf("���ڼ�����......");
				double value1 = CountSort(arr1, n1);
				double value2 = CountSort(arr2, n2);
				double value3 = CountSort(arr3, n3);

				//��¼����ʱ������
				clock_t start4, end4;
				//��ʼ��ʱ
				start4 = clock();
				for (int i = 0; i < n4; i++) {
					QuickSort(arr4, 0, n4);
				}
				end4 = clock();
				double value4 = (double)((end4 - start4) / CLOCKS_PER_SEC);
				system("cls");
				printf("��������%d�����ݵĺ�ʱΪ��%lf\n", n1, value1);
				printf("��������%d�����ݵĺ�ʱΪ��%lf\n", n2, value2);
				printf("��������%d�����ݵĺ�ʱΪ��%lf\n", n3, value3);
				printf("��������%d������100�εĺ�ʱΪ��%lf\n", n4, value4);
				putdata(arr1, n1, "test1count.finish");
				putdata(arr2, n2, "test2count.finish");
				putdata(arr3, n3, "test3count.finish");
				putdata(arr4, n4, "test4count.finish");
				system("pause");
				system("cls");
			}
			else {
				printf("���ݻ�δ���ɣ�������������\n");
				system("pause");
				system("cls");
			}
			break;
		case 6:
			if (n == 1) {
				printf("���ڶ�ȡ����.....");
				readdata(arr1, n1, "test1");
				readdata(arr2, n2, "test2");
				readdata(arr3, n3, "test3");
				readdata(arr4, n4, "test4");
				printf("��ȡ�ɹ�\n");
				system("pause");
				system("cls");
				printf("���ڼ�����......");
				double value1 = RadixCountSort(arr1, n1);
				double value2 = RadixCountSort(arr2, n2);
				double value3 = RadixCountSort(arr3, n3);
				//��¼����ʱ������
				clock_t start4, end4;
				//��ʼ��ʱ
				start4 = clock();
				for (int i = 0; i < n4; i++) {
					QuickSort(arr4, 0, n4);
				}
				end4 = clock();
				double value4 = (double)((end4 - start4) / CLOCKS_PER_SEC);
				system("cls");
				printf("������������%d�����ݵĺ�ʱΪ��%lf\n", n1, value1);
				printf("������������%d�����ݵĺ�ʱΪ��%lf\n", n2, value2);
				printf("������������%d�����ݵĺ�ʱΪ��%lf\n", n3, value3);
				printf("������������%d������100�εĺ�ʱΪ��%lf\n", n4, value4);
				putdata(arr1, n1, "test1Radixcount.finish");
				putdata(arr2, n2, "test2Radixcount.finish");
				putdata(arr3, n3, "test3Radixcount.finish");
				putdata(arr4, n4, "test4Radixcount.finish");
				system("pause");
				system("cls");
			}
			else {
				printf("���ݻ�δ���ɣ�������������\n");
				system("pause");
				system("cls");
			}
			break;
		case 7:
			system("cls");
			printf("���ѳɹ��˳�ϵͳ\n");
			break;
		default:
			printf("��������������������\n");
			system("pause");
			system("cls");
			break;

	}


 } while (choice != 7);
	return 0;
}