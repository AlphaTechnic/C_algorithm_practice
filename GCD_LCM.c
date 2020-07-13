#include <stdio.h>

void calGcdLcm (int num1, int num2, int* gcd, int* lcm);
int main(){
	int gcd, lcm;
	int num1, num2;
	
	printf("Enter the 1st number : ");
	scanf("%d", &num1);
	printf("Enter the 2nd number : ");
	scanf("%d", &num2);
	
	calGcdLcm(num1, num2, &gcd, &lcm);
	
	printf("\n\nGCD of %d and %d is %d\n", num1, num2, gcd);
	printf("LCM of %d and %d is %d", num1, num2, lcm);
	
	return 0;
}

void calGcdLcm (int num1, int num2, int* gcd, int* lcm){
	int r;
	int num1box = num1;
	int num2box = num2;

	while(1){
		r = num1 % num2;
		if (r == 0){
			break;
		}
		num1 = num2;
		num2 = r;
	}
	
	*gcd = num2;
	*lcm = num1box*num2box / *gcd;
	
	return;
}
