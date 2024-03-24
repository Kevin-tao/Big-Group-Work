#include "function.h"
int main()
{   

	OpearandStack opearandstack; //声明一个操作符栈
	OpearatorStack opearatorstack;//声明一个操作数栈
	
	//初始化栈
	initstack1(&opearatorstack);
	initstack2(&opearandstack);

	//用户输入项
	char input[MAX_SIZE]; 

	//利用死循环实现
	while(1) {
		welcome();
		printf("\n            请输入你想要计算的式子>>");
		scanf("%s", input);
		float result=evaluate(input, &opearandstack, &opearatorstack, 0, strlen(input) - 1);
		
		printf("\n            计算结果为%f\n", result);
		system("pause");
		system("cls");
	}
	


	return 0;
}