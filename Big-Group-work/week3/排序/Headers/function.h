#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 100  //����
#define _CRT_SECURE_NO_WARNINGS 
//���溯��
void welcome()
{   
	printf("������ʾ�밴�س���\n");
	printf("1.���ɲ�������\n");
	printf("2.�鲢����\n"); 
	printf("3.��������\n");
	printf("4.��������\n");
	printf("5.��������\n");
	printf("6.������������\n");
	printf("7.�˳�����\n");

}

//��������
void clear()
{
	system("cls");
	system("pause");
	system("cls");
}

//������뻺����
void clearInputBuffer()
{
	while (getchar() != '\n');
}

//���ɲ������ݺ���
void creatdata(int n,const char*filename)
{
	//nΪд�����ݵĸ�����filenameΪ�ļ�ָ��
	
	//��д�뷽ʽ���ļ�
	FILE* file =fopen(filename,"w");
	if (file == NULL) {
		printf("�ļ���ʧ��\n");
		exit(1);
	}
    
	srand(time(NULL));

	//���ļ���д������
	for (int i = 0; i < n; i++) {
		//����n��0-9999���������д���ļ�
		fprintf(file, "%d\n", rand() % 10000);
	}

	//�ر��ļ�
	fclose(file);
}


//������õ����ݷ���txt�ļ�����
void putdata(int arr[], int n, const char* filename)
{
	FILE* file = fopen(filename, "w");
	if (file == NULL) {
		printf("�ļ���ʧ��\n");
		exit(1);
	}
	//���ļ���д������
	for (int i = 0; i < n; i++) {

		fprintf(file, "%d\n", arr[i]);

	}
	//�ر��ļ�
	fclose(file);
}

//����������ݺ���

void readdata(int arr[], int n,const char* filename) {
	
	//��¼�������ݼ��Ĵ���
	static int  num = 1;
	
	//nΪ�������ݵĸ�����filenameΪ�ļ�ָ�룬arr[]Ϊ�������ݺ󣬴�����ݵ�����
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("�ļ���ʧ��\n");
		exit(1);
	}

	//��ʼ������
	for (int i = 0; i < n; i++) {
		fscanf(file, "%d\n", &arr[i]);
	}
	//�ر��ļ�
	fclose(file);
	
	
}

//��������
double Insertsort(int arr[], int n, const char* filename) {

	//nΪ�������ݵĸ�����filenameΪ���������ݷ�����ļ����ļ�ָ�룬arr[]Ϊ�������ݺ󣬴�����ݵ�����
	
	//��¼����ʱ������
	clock_t start, end;
	

	//��ʼ��ʱ
	start = clock();

	//��ʼ����
	for (int i = 1; i < n; i++) {

		//Ĭ�ϵ�0��Ϊ��������У����Դӵ�1�ʼ������������ÿ������

		//�ӵ�0���i-1������
		for (int j = 0; j < i; j++) {
			
			if (arr[i] <= arr[j]) {
				int t = i-1;   //��¼��i-1��λ��
				int m = arr[i];//��¼Ҫ�������ݵĴ�С
				while (t >=j) {
					arr[t + 1] = arr[t];
					t--;
				}
				arr[j] = m;
			}
		}
	}

	end = clock();

	//�����㷨ʱ��
	return  (double)((end - start) / CLOCKS_PER_SEC);
}


//�鲢����
void Mergesort(int arr[],  int l,int mid, int r)
{   

	//i��j,k�ֱ�Ϊ����������ʱ�����ԭ�����±�
	int i, j, k;

	//�������鳤��
	int n1 = mid - l + 1;
	int n2 = r - mid;

	// ����ָ�����飬���ڶ��϶�̬�����ڴ�
	int* arr1 = (int*)malloc(n1 * sizeof(int));
	int* arr2 = (int*)malloc(n2 * sizeof(int));

	
	// ������
	if (arr1 == NULL || arr2 == NULL) {
		// �����ڴ����ʧ�ܵ����
		// ���Է��ش��������ȡ�����ָ���ʩ
		printf("�ڴ�����ʧ��\n");
		return;
	}
	//�����벿��
	for (i = 0; i < n1; i++) {
		arr1[i] = arr[i];
	}


	//����Ұ벿��
	for (j = 0; j < n2; j++) {
		arr2[j] = arr[mid+1+j];
	}


	//��ʼ�������±�
	i = 0;
	j = 0;
	k = l;

	//��ʼ����
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

	//���������ʣ�ಿ�ַ���ԭ����
	while (i < n1) {
		arr[k] = arr1[i];
		i++;
		k++;
	}

	//���Ұ�����ʣ�ಿ�ַ���ԭ����
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
	//lΪ��߽磬rΪ�б߽�
	if (l < r) {
		//����Ϊ����
		int mid = (r -l) / 2+l;

		//�ݹ����벿�ֽ�������
		merge(arr, l, mid);

		//�ݹ���Ұ벿�ֽ�������
		merge(arr, mid+1,r);

	Mergesort(arr, l, mid, r);
	}

	
}
//��ӡ����
void print(int arr[],int n)
{   

	printf("����������Ϊ��\n");
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
}

//��������
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[low]; // ѡ���һ��Ԫ����Ϊ��׼ֵ
	int left = low + 1;  //left�����ұ�pivot���ֵ

	int right = high;//right�����ұ�pivotС��ֵ

	while (true) {

		//ʹleft���ڱ�pivot���ֵ�±꣬ʹright���ڱ�pivotС��ֵ�±�
		while (left <= right && arr[left] < pivot) left++;
		while (left <= right && arr[right] > pivot) right--;


		if (left >= right) break;
		//����
		swap(&arr[left], &arr[right]);
		left++;
		right--;
	}
	swap(&arr[low], &arr[right]);
	return right;
}


//�ݹ�����Ի�׼ֵ�ֳ�������
void QuickSort(int arr[], int low, int high)
{
	if (low >= high) return;
	int pivot_index = partition(arr, low, high);
	QuickSort(arr, low, pivot_index - 1);
	QuickSort(arr, pivot_index + 1, high);
}

//��������
double CountSort(int arr[], int n)
{
	int max = 0, min = 0;   //��¼�����Сֵ
	clock_t start, end;
//��ʼ��ʱ
	start = clock();
	for (int i = 0; i < n; i++) {
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	int count = max - min + 1;  //���ٿռ������

	//����һ��ͳ�Ƹ�Ԫ�ش���������
	int* arrcount = (int*)malloc(count*sizeof(int) );

	//��ʼ������ȫΪ0
	memset(arrcount, 0, count * sizeof(int));

	//��ʼ����
	for (int i = 0; i < n; i++) {
		arrcount[arr[i] - min]++;
	}

	//��ʼ����
	for (int i = 0,j=0; i < count; i++) {
		
		//���������Ϊ0����
		while (arrcount[i]--) {
			arr[j] = i + min;
			j++;
		}
	}
	free(arrcount);
	//������ʱ
	end = clock();

	return(double)((end - start) / CLOCKS_PER_SEC);
}


//������������
double RadixCountSort(int arr[], int n)
{
	clock_t start, end;
	//��ʼ��ʱ
	start = clock();

	int buffet[10] = { 0 };                                     //Ͱ���飬���ڼ�¼��ֵĳλ��ֵΪ0-9����ֵ�ĸ���
	int* buff = (int*)malloc(n * sizeof(int));                  //���ڴ����ֵ������
	int max = arr[0];  //Ѱ�������
	for (int i = 1; i < n; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	int count = 0; //���ڼ����������λ��
	while (max > 0) {
		count++;
		max /= 10;
	}

	int base = 1; //���û�ֵ

	//��ʼ����
	for (int i = 0; i <count; i++) {

		//��¼��ֵĳλ��ֵΪ�ֱ�Ϊ0-9����ֵ�ĸ���
		for (int j = 0; j < n; j++) {
			buffet[(arr[j] / base) % 10]++;
		}

		//���Եõ�ÿ��ͰԪ�����������±�
		for (int j = 1; j < 10; j++) {
			buffet[j] += buffet[j - 1];
		}

		//����ͰԪ�ص�ֵ��arrԪ�ش���buff��
		for (int j = n-1; j >=0; j--) {
			buff[buffet[(arr[j] / base) % 10] - 1] = arr[j];
			buffet[(arr[j] / base) % 10]--;
		}


		//���½�buff��Ԫ�ش���arr��
		for (int j = 0; j < n; j++) {
			arr[j] = buff[j];
		}

		//����ͰԪ��
		for (int j = 0; j < 10; j++) {
			buffet[j] = 0;
		}
		base *= 10;
	}
	//������ʱ
	end = clock();

	return(double)((end - start) / CLOCKS_PER_SEC);
}