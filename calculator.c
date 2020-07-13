#include <stdio.h>

int getData (int* a, int* b);
int eval_add_sub_mul (int a, int b);
int eval_quot_div (int a, int b, int* quot, int* div);

int main(){
	int a, b;
	int q, r;
	
	getData(&a, &b);
	eval_add_sub_mul(a, b);
	
	eval_quot_div (a, b, &q, &r);
	printf("³ª´« ¸òÀÇ °ª:%4d %4d=%4d\n", a, b, q);
	printf("³ª¸ÓÁö °ªÀº :%4d %4d=%4d\n", a, b, r);
	
	return 0;
}

int getData (int* a, int* b){
	printf("Please enter two integer numbers: ");
	scanf("%d %d", a, b);
	
	return 0;
}

int eval_add_sub_mul (int a, int b){
	int add, sub, mul;
	
	add = a + b;
	sub = a - b;
	mul = a * b;
	
	printf("µ¡¼À °á°ú´Â :%4d %4d=%4d\n", a, b, add);
	printf("»¬¼À °á°ú´Â :%4d %4d=%4d\n", a, b, sub);
	printf("°ö¼À °á°ú´Â :%4d %4d=%4d\n", a, b, mul);
	
	return 0;
}

int eval_quot_div (int a, int b, int* q, int* r){
	*q = a / b;
	*r = a % b;	
}
