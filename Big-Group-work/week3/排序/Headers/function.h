#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 100  //长度
#define _CRT_SECURE_NO_WARNINGS 
//界面函数
void welcome()
{   
	printf("若无提示请按回车键\n");
	printf("1.生成测试数据\n");
	printf("2.归并排序\n"); 
	printf("3.插入排序\n");
	printf("4.快速排序\n");
	printf("5.计数排序\n");
	printf("6.基数计数排序\n");
	printf("7.退出程序\n");

}

//清屏函数
void clear()
{
	system("cls");
	system("pause");
	system("cls");
}

//清空输入缓存区
void clearInputBuffer()
{
	while (getchar() != '\n');
}

//生成测试数据函数
void creatdata(int n,const char*filename)
{
	//n为写入数据的个数，filename为文件指针
	
	//以写入方式打开文件
	FILE* file =fopen(filename,"w");
	if (file == NULL) {
		printf("文件打开失败\n");
		exit(1);
	}
    
	srand(time(NULL));

	//往文件中写入数据
	for (int i = 0; i < n; i++) {
		//生成n个0-9999的随机数并写入文件
		fprintf(file, "%d\n", rand() % 10000);
	}

	//关闭文件
	fclose(file);
}


//将排序好的数据放入txt文件函数
void putdata(int arr[], int n, const char* filename)
{
	FILE* file = fopen(filename, "w");
	if (file == NULL) {
		printf("文件打开失败\n");
		exit(1);
	}
	//往文件中写入数据
	for (int i = 0; i < n; i++) {

		fprintf(file, "%d\n", arr[i]);

	}
	//关闭文件
	fclose(file);
}

//读入测试数据函数

void readdata(int arr[], int n,const char* filename) {
	
	//记录生成数据集的次数
	static int  num = 1;
	
	//n为读入数据的个数，filename为文件指针，arr[]为读入数据后，存放数据的数组
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("文件打开失败\n");
		exit(1);
	}

	//开始读数据
	for (int i = 0; i < n; i++) {
		fscanf(file, "%d\n", &arr[i]);
	}
	//关闭文件
	fclose(file);
	
	
}

//插入排序
double Insertsort(int arr[], int n, const char* filename) {

	//n为读入数据的个数，filename为排序后把数据放入的文件的文件指针，arr[]为读入数据后，存放数据的数组
	
	//记录排序时长变量
	clock_t start, end;
	

	//开始计时
	start = clock();

	//开始排序
	for (int i = 1; i < n; i++) {

		//默认第0项为有序的序列，所以从第1项开始，所以序列中每个数据

		//从第0项到第i-1项排序
		for (int j = 0; j < i; j++) {
			
			if (arr[i] <= arr[j]) {
				int t = i-1;   //记录第i-1项位置
				int m = arr[i];//记录要插入数据的大小
				while (t >=j) {
					arr[t + 1] = arr[t];
					t--;
				}
				arr[j] = m;
			}
		}
	}

	end = clock();

	//返回算法时长
	return  (double)((end - start) / CLOCKS_PER_SEC);
}


//归并排序
void Mergesort(int arr[],  int l,int mid, int r)
{   

	//i，j,k分别为索引两个临时数组和原数组下标
	int i, j, k;

	//计算数组长度
	int n1 = mid - l + 1;
	int n2 = r - mid;

	// 定义指针数组，并在堆上动态分配内存
	int* arr1 = (int*)malloc(n1 * sizeof(int));
	int* arr2 = (int*)malloc(n2 * sizeof(int));

	
	// 错误检查
	if (arr1 == NULL || arr2 == NULL) {
		// 处理内存分配失败的情况
		// 可以返回错误代码或采取其他恢复措施
		printf("内存生成失败\n");
		return;
	}
	//存放左半部分
	for (i = 0; i < n1; i++) {
		arr1[i] = arr[i];
	}


	//存放右半部分
	for (j = 0; j < n2; j++) {
		arr2[j] = arr[mid+1+j];
	}


	//初始化索引下标
	i = 0;
	j = 0;
	k = l;

	//开始排序
	while (i < n1 && j < n2) {
		if (arr1[i] <= arr2[j]) {
			arr[k] = arr1[i];
			i++;
		}
		else {
			arr[k] = arr2[j];
			j++;
		}
		k++;
	}

	//将左半数组剩余部分放入原数组
	while (i < n1) {
		arr[k] = arr1[i];
		i++;
		k++;
	}

	//将右半数组剩余部分放入原数组
	while (j< n2) {
		arr[k] = arr2[j];
		j++;
		k++;
	}
	free(arr1);
	free(arr2);
}

void merge(int arr[], int l, int r)
{   
	if (l >= r) {
		return;
	}
	//l为左边界，r为有边界
	if (l < r) {
		//划分为两半
		int mid = (r -l) / 2+l;

		//递归对左半部分进行排序
		merge(arr, l, mid);

		//递归对右半部分进行排序
		merge(arr, mid+1,r);

	Mergesort(arr, l, mid, r);
	}

	
}
//打印函数
void print(int arr[],int n)
{   

	printf("排序后的数据为：\n");
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
}

//交换函数
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[low]; // 选择第一个元素作为基准值
	int left = low + 1;  //left用于找比pivot大的值

	int right = high;//right用于找比pivot小的值

	while (true) {

		//使left等于比pivot大的值下标，使right等于比pivot小的值下标
		while (left <= right && arr[left] < pivot) left++;
		while (left <= right && arr[right] > pivot) right--;


		if (left >= right) break;
		//交换
		swap(&arr[left], &arr[right]);
		left++;
		right--;
	}
	swap(&arr[low], &arr[right]);
	return right;
}


//递归调用以基准值分成两部分
void QuickSort(int arr[], int low, int high)
{
	if (low >= high) return;
	int pivot_index = partition(arr, low, high);
	QuickSort(arr, low, pivot_index - 1);
	QuickSort(arr, pivot_index + 1, high);
}

//计数排序
double CountSort(int arr[], int n)
{
	int max = 0, min = 0;   //记录最大最小值
	clock_t start, end;
//开始计时
	start = clock();
	for (int i = 0; i < n; i++) {
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	int count = max - min + 1;  //开辟空间的数量

	//创建一个统计各元素次数的数组
	int* arrcount = (int*)malloc(count*sizeof(int) );

	//初始化数组全为0
	memset(arrcount, 0, count * sizeof(int));

	//开始计数
	for (int i = 0; i < n; i++) {
		arrcount[arr[i] - min]++;
	}

	//开始排序
	for (int i = 0,j=0; i < count; i++) {
		
		//排序计数不为0的数
		while (arrcount[i]--) {
			arr[j] = i + min;
			j++;
		}
	}
	free(arrcount);
	//结束计时
	end = clock();

	return(double)((end - start) / CLOCKS_PER_SEC);
}


//基数计数排序
double RadixCountSort(int arr[], int n)
{
	clock_t start, end;
	//开始计时
	start = clock();

	int buffet[10] = { 0 };                                     //桶数组，用于记录数值某位上值为0-9的数值的个数
	int* buff = (int*)malloc(n * sizeof(int));                  //用于存放数值的数组
	int max = arr[0];  //寻找最大数
	for (int i = 1; i < n; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	int count = 0; //用于计算最大数的位数
	while (max > 0) {
		count++;
		max /= 10;
	}

	int base = 1; //设置基值

	//开始排序
	for (int i = 0; i <count; i++) {

		//记录数值某位上值为分别为0-9的数值的个数
		for (int j = 0; j < n; j++) {
			buffet[(arr[j] / base) % 10]++;
		}

		//可以得到每个桶元素在排序后的下标
		for (int j = 1; j < 10; j++) {
			buffet[j] += buffet[j - 1];
		}

		//根据桶元素的值将arr元素存入buff中
		for (int j = n-1; j >=0; j--) {
			buff[buffet[(arr[j] / base) % 10] - 1] = arr[j];
			buffet[(arr[j] / base) % 10]--;
		}


		//重新将buff中元素存入arr中
		for (int j = 0; j < n; j++) {
			arr[j] = buff[j];
		}

		//重置桶元素
		for (int j = 0; j < 10; j++) {
			buffet[j] = 0;
		}
		base *= 10;
	}
	//结束计时
	end = clock();

	return(double)((end - start) / CLOCKS_PER_SEC);
}