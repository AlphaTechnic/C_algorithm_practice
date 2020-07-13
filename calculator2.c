#include <stdio.h>
#include <stdlib.h>

int getOption();
int getData (int* a, int* b);
int calc (int option, int a, int b);
float add(int a, int b);
float sub(int a, int b);
float mul(int a, int b);
float divide(int a, int b);
int printResult(int a, int b, int option, float result, char* stdname, int stdnum);

int main(){
	int option;
	int num1, num2;
	float result;
	int stdnum;
	char stdname[10];
	
	printf("성명:");
	scanf("%s", stdname);
	printf("학번:");
	scanf("%d", &stdnum);
	
	option = getOption();	
	getData(&num1, &num2);
	result = calc(option, num1, num2);
	
	printResult(num1, num2, option, result, stdname, stdnum);
	
	return 0;
}

int getOption(){
	int option;
	
	printf  ("\t**********************************");
	printf("\n\t*              MENU              *");
	printf("\n\t*                                *");
	printf("\n\t*  1. ADD                        *");
	printf("\n\t*  2. SUBTRACT                   *");
	printf("\n\t*  3. MULTIPLY                   *");
	printf("\n\t*  4. DIVIDE                     *");
	printf("\n\t*                                *");	
	printf("\n\t**********************************");
	
	printf("\n\nPlease type your choice ");
	printf("and key return: ");
	scanf("%d", &option);
	
	return option;
	
}

int getData (int* a, int* b){
	printf("Please enter two integer numbers: ");
	scanf("%d %d", a, b);
	
	return 0;
}

int calc (int option, int a, int b){
	float result;
	
	switch(option){
		case 1: 
			result = add(a, b);
			break;
		case 2:
			result = sub(a, b);
			break;
		case 3:
			result = mul(a, b);
			break;
		case 4:
			if (b == 0){
				printf("\n\a\aError: ");
				
				printf("division by zero ***\n");
				exit(100);
			}
			else{
				result = divide(a, b);
				break;
			}
		default:
			printf("\aOption not available\n");
			exit(101);
	}
	
	return result;
}

float add(int a, int b){
	return a+b;
}
float sub(int a, int b){
	return a-b;
}
float mul(int a, int b){
	return a*b;
}
float divide(int a, int b){
	return (float)a/b;
}

int printResult(int a, int b, int option, float result, char* stdname, int stdnum){
	char oper;
	
	switch (option){
		case 1:
			oper = '+';
			break;
		case 2:
			oper = '-';
			break;
		case 3:
			oper = '*';
			break;
		case 4:
			oper = '/';
			break;
	}
	
	printf("\nPrinted at 함수\n성명=%s,\t학번=%8d", stdname, stdnum);
	printf("%\n%2d %c %2d = %5.2f", a, oper, b, result);
	return 0;
}
