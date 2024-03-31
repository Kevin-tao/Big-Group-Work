#include "function.h"
int main()
{
	int choice;
	
	//choice用于用户输入合法选项，

	int n = 0;//判断用户是否已输入数据

	int n1 = 100000, n2 = 10000, n3 = 50000,n4=100;
	//不同大数据量


	int arr1[100001];
	int arr2[10001];
	int arr3[50001];
	int arr4[101];


	char input1[MAX_SIZE];   //用于接受用户的输入结果
	//do-while循环生成开始界面2 

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
	switch (choice)
	{
		case 1:
			clear();
			printf("正在生成随机数据\n");
			creatdata(n1, "test1");
			creatdata(n2, "test2");
			creatdata(n3, "test3");
			creatdata(n4, "test4");
			system("pause");
			system("cls");
			printf("生成成功\n");
			system("pause");
			system("cls");
			n = 1;
			break;
		case 2:
			if (n == 1) {
				printf("正在读取数据.....");
				readdata(arr1, n1, "test1");
				readdata(arr2, n2, "test2");
				readdata(arr3, n3, "test3");
				readdata(arr4, n4, "test4");
				printf("读取成功\n");
				system("pause");
				system("cls");
				printf("正在计算中......");

				//记录排序时长变量
				clock_t start1, end1;

				//开始计时
				start1 = clock();

				merge(arr1, 0, n1);
				//结束
				end1 = clock();
				double value1 = (double)((end1 - start1) / CLOCKS_PER_SEC);
				//记录排序时长变量
				clock_t start2, end2;

				//开始计时
				start2 = clock();

				merge(arr2, 0, n2);
				//结束
				end2 = clock();
				double value2 = (double)((end2 - start2) / CLOCKS_PER_SEC);
				//记录排序时长变量
				clock_t start3, end3;

				//开始计时
				start3 = clock();

			merge(arr3, 0, n3);
				//结束
				end3 = clock();
				double value3 = (double)((end3 - start3) / CLOCKS_PER_SEC);
				
				//记录排序时长变量
				clock_t start4, end4;
				//开始计时
				start4 = clock();
				for (int i = 0; i < n4; i++) {
					merge(arr4, 0, n4);
				}
				end4 = clock();
				double value4 = (double)((end4 - start4) / CLOCKS_PER_SEC);
				system("cls");
				printf("归并排序%d个数据的耗时为：%lf\n", n1, value1);
				printf("归并排序%d个数据的耗时为：%lf\n", n2, value2);
				printf("归并排序%d个数据的耗时为：%lf\n", n3, value3);
				printf("归并排序%d个数据100次的耗时为：%lf\n", n4, value4);
				putdata(arr1, n1, "testmerge1.finish");
				putdata(arr2, n2, "testmerge2.finish");
				putdata(arr3, n3, "testmerge3.finish");
				putdata(arr4, n4, "testmerge4.finish");
				system("pause");
				system("cls");
			}
			else {
				printf("数据还未生成，请先生成数据\n");
				system("pause");
				system("cls");
			}
			break;
		case 3:
			if (n == 1) {
				printf("正在读取数据.....");
				readdata(arr1, n1, "test1");
				readdata(arr2, n2, "test2");
				readdata(arr3, n3, "test3");
				readdata(arr4, n4, "test4");
				printf("读取成功\n");
				system("pause");
				system("cls");
				printf("正在计算中......");
				double value1 = Insertsort(arr1, n1, "test1");
				double value2 = Insertsort(arr2, n2, "test1");
				double value3 = Insertsort(arr3, n3, "test1");

				//记录排序时长变量
				clock_t start4, end4;
				//开始计时
				start4= clock();
				for (int i = 0; i < n4; i++) {
					merge(arr4, 0, n4);
				}
				end4 = clock();
				double value4 = (double)((end4 - start4) / CLOCKS_PER_SEC);
				system("cls");
				printf("插入排序%d个数据的耗时为：%lf\n", n1, value1);
				printf("插入排序%d个数据的耗时为：%lf\n", n2, value2);
				printf("插入排序%d个数据的耗时为：%lf\n", n3, value3);
				printf("插入排序%d个数据100次的耗时为：%lf\n", n4, value4);
				putdata(arr1, n1, "testinsert1.finish");
				putdata(arr2, n2, "testinsert2.finish");
				putdata(arr3, n3, "testinsert3.finish");
				putdata(arr4, n4, "testinsert4.finish");
				system("pause");
				system("cls");
			}
			else {
				printf("数据还未生成，请先生成数据\n");
				system("pause");
				system("cls");
			}
			break;
		case 4:
			if (n == 1) {
				printf("正在读取数据.....");
				readdata(arr1, n1, "test1");
				readdata(arr2, n2, "test2");
				readdata(arr3, n3, "test3");
				readdata(arr4, n4, "test4");
				printf("读取成功\n");
				system("pause");
				system("cls");
				printf("正在计算中......");
				
				//记录排序时长变量
				clock_t start1, end1;
				
				//开始计时
				start1 = clock();

				QuickSort(arr1, 0, n1-1);
				//结束
				end1 = clock();
				double value1 = (double)((end1 - start1) / CLOCKS_PER_SEC);
				//记录排序时长变量
				clock_t start2, end2;

				//开始计时
				start2 = clock();

				QuickSort(arr2, 0, n2-1);
				//结束
				end2 = clock();
				double value2 = (double)((end2 - start2) / CLOCKS_PER_SEC);
				//记录排序时长变量
				clock_t start3, end3;

				//开始计时
				start3 = clock();

				QuickSort(arr3, 0, n3-1);
				//结束
				end3 = clock();
				double value3 = (double)((end3 - start3) / CLOCKS_PER_SEC);

				//记录排序时长变量
				clock_t start4, end4;
				//开始计时
				start4 = clock();
				for (int i = 0; i < n4; i++) {
					QuickSort(arr4, 0, n4);
				}
				end4 = clock();
				double value4 = (double)((end4 - start4) / CLOCKS_PER_SEC);
				system("cls");
				printf("快速排序%d个数据的耗时为：%lf\n", n1,value1);
				printf("快速排序%d个数据的耗时为：%lf\n", n2, value2);
				printf("快速排序%d个数据的耗时为：%lf\n", n3, value3);
				printf("快速排序%d个数据100次的耗时为：%lf\n", n4, value4);
				putdata(arr1, n1, "testfast1.finish");
				putdata(arr2, n2, "testfast2.finish");
				putdata(arr3, n3, "testfast3.finish");
				putdata(arr4, n4, "testfast4.finish");
				system("pause");
				system("cls");
			}
			else {
				printf("数据还未生成，请先生成数据\n");
				system("pause");
				system("cls");
			}
			break;
		case 5:
			if (n == 1) {
				printf("正在读取数据.....");
				readdata(arr1, n1, "test1");
				readdata(arr2, n2, "test2");
				readdata(arr3, n3, "test3");
				readdata(arr4, n4, "test4");
				printf("读取成功\n");
				system("pause");
				system("cls");
				printf("正在计算中......");
				double value1 = CountSort(arr1, n1);
				double value2 = CountSort(arr2, n2);
				double value3 = CountSort(arr3, n3);

				//记录排序时长变量
				clock_t start4, end4;
				//开始计时
				start4 = clock();
				for (int i = 0; i < n4; i++) {
					QuickSort(arr4, 0, n4);
				}
				end4 = clock();
				double value4 = (double)((end4 - start4) / CLOCKS_PER_SEC);
				system("cls");
				printf("计数排序%d个数据的耗时为：%lf\n", n1, value1);
				printf("计数排序%d个数据的耗时为：%lf\n", n2, value2);
				printf("计数排序%d个数据的耗时为：%lf\n", n3, value3);
				printf("计数排序%d个数据100次的耗时为：%lf\n", n4, value4);
				putdata(arr1, n1, "test1count.finish");
				putdata(arr2, n2, "test2count.finish");
				putdata(arr3, n3, "test3count.finish");
				putdata(arr4, n4, "test4count.finish");
				system("pause");
				system("cls");
			}
			else {
				printf("数据还未生成，请先生成数据\n");
				system("pause");
				system("cls");
			}
			break;
		case 6:
			if (n == 1) {
				printf("正在读取数据.....");
				readdata(arr1, n1, "test1");
				readdata(arr2, n2, "test2");
				readdata(arr3, n3, "test3");
				readdata(arr4, n4, "test4");
				printf("读取成功\n");
				system("pause");
				system("cls");
				printf("正在计算中......");
				double value1 = RadixCountSort(arr1, n1);
				double value2 = RadixCountSort(arr2, n2);
				double value3 = RadixCountSort(arr3, n3);
				//记录排序时长变量
				clock_t start4, end4;
				//开始计时
				start4 = clock();
				for (int i = 0; i < n4; i++) {
					QuickSort(arr4, 0, n4);
				}
				end4 = clock();
				double value4 = (double)((end4 - start4) / CLOCKS_PER_SEC);
				system("cls");
				printf("基数计数排序%d个数据的耗时为：%lf\n", n1, value1);
				printf("基数计数排序%d个数据的耗时为：%lf\n", n2, value2);
				printf("基数计数排序%d个数据的耗时为：%lf\n", n3, value3);
				printf("基数计数排序%d个数据100次的耗时为：%lf\n", n4, value4);
				putdata(arr1, n1, "test1Radixcount.finish");
				putdata(arr2, n2, "test2Radixcount.finish");
				putdata(arr3, n3, "test3Radixcount.finish");
				putdata(arr4, n4, "test4Radixcount.finish");
				system("pause");
				system("cls");
			}
			else {
				printf("数据还未生成，请先生成数据\n");
				system("pause");
				system("cls");
			}
			break;
		case 7:
			system("cls");
			printf("你已成功退出系统\n");
			break;
		default:
			printf("你的输入错误，请重新输入\n");
			system("pause");
			system("cls");
			break;

	}


 } while (choice != 7);
	return 0;
}