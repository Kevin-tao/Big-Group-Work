#include "function.h"
int main()
{   

	OpearandStack opearandstack; //����һ��������ջ
	OpearatorStack opearatorstack;//����һ��������ջ
	
	//��ʼ��ջ
	initstack1(&opearatorstack);
	initstack2(&opearandstack);

	//�û�������
	char input[MAX_SIZE]; 

	//������ѭ��ʵ��
	while(1) {
		welcome();
		printf("\n            ����������Ҫ�����ʽ��>>");
		scanf("%s", input);
		float result=evaluate(input, &opearandstack, &opearatorstack, 0, strlen(input) - 1);
		
		printf("\n            ������Ϊ%f\n", result);
		system("pause");
		system("cls");
	}
	


	return 0;
}