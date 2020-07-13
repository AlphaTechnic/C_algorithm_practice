#include <stdio.h>
#include <math.h>
#define BOUND 0.00001

int main(){
	double a, b, c;
	double root1, root2;
	double D;
	printf("이차방정식 계수 a, b, c를 입력하시오.");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	D = b*b - 4*a*c;
	
	if (fabs(D) <= BOUND){
		root1 = -b / (2.0*a);
		printf("중근 = %3.f\n", root1);
	}
	
	else if (D>0){
		D = sqrt(D);
		root1 = (-b+D) / (2.0*a);
		root2 = (-b-D) / (2.0*a);
		printf("2개의 근 = %.3lf, %.3lf\n", root1, root2);		
	}
	
	else printf("근이 없습니다.\nD=%.4f", D);
	
	return 0;
}
