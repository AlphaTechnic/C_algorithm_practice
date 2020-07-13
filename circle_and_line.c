#include <stdio.h>
#include <math.h>     // fabs와 sqrt를 사용하기 위함 
#define BOUND 0.001   // 상수 BOUND를 0.001로 설정하여 BOUND보다 작은 값이라면, 그 값을 0으로 취급하려고 한다. 

int getval(float *a, float *b, float *cx, float *cy, float *r);
int get_meetingpts(float a, float b, float cx, float cy, float r);

int main(){
	float a, b, cx, cy, r;
	
	getval(&a, &b, &cx, &cy, &r);
	get_meetingpts(a, b, cx, cy, r);
	
	return 0;
} 

int getval(float *a, float *b, float *cx, float *cy, float *r){
	printf("직선의 함수식을 입력하기 바랍니다.\n");
	printf("y = ax + b\n");
	printf("기울기 a = ");
	scanf("%f", a);
	printf("교차점 b = ");
	scanf("%f", b);
	
	printf("\n원의 함수식을 입력하기 바랍니다.\n");
	printf("(x - cx)^2 + (y - cy)^2 = r^2\n");
	printf("cx = ");
	scanf("%f", cx);
	printf("cy = ");
	scanf("%f", cy);
	printf("반지름 r = ");
	scanf("%f", r);
	
	return 0; 
}

int get_meetingpts(float a, float b, float cx, float cy, float r){
	/*  직선 y = ax+b와 원의 방정식 (x - cx)^2 + (y - cy)^2 = r^2에서
	y를 소거하면서 연립시켜 만든 새로운 방정식
	a1x^2+b1x+c1 = 0을 만들 때, x의 계수 a1, b1, c1은 아래와같이 만들어진다.
	위 방정식의 근을 근의공식을 통해 구하면, 교점의 x좌표가 된다.*/ 	
	float a1 = a*a + 1;
	float b1 = 2*(-cx + a*(b-cy));
	float c1 = cx*cx + (b-cy)*(b-cy) - r*r;
	float D = b1*b1 - 4*a1*c1;  // 이차방정식의 판별식 D 
	
	float x1, y1, x2, y2;  // 교점 좌표의 성분들을 할당시킬 변수들  
	
	if (fabs(D)<BOUND){       // 설정한 상수 BOUND보다 작은 값은 0으로 취급한다. 판별식 D = 0인 경우의 조건문이라고 할 수 있다. 
		printf("직선 라인은 원에 접합니다.\n");
		
		x1 = (-b1) / (2*a1);
		y1 = a*x1 + b;
		
		if (fabs(x1)<BOUND){   
			x1 = 0;
		}
		if (fabs(y1)<BOUND){
			y1 = 0;
		}
		printf("(%6.3f, %6.3f)", x1, y1);
	}
	else if (D>0){
		printf("두 함수에는 두개의 교차점이 있습니다.\n");
		
		x1 = (-b1 - sqrt(D)) / (2.0*a1);
		y1 = a*x1 + b;
		x2 = (-b1 + sqrt(D)) / (2.0*a1);
		y2 = a*x2 + b;
		
		if (fabs(x1)<BOUND){
			x1 = 0;
		}
		if (fabs(y1)<BOUND){
			y1 = 0;
		}
		if (fabs(x2)<BOUND){
			x2 = 0;
		}
		if (fabs(y2)<BOUND){
			y2 = 0;
		}
		
		printf("(%6.3f, %6.3f), (%6.3f, %6.3f)", x1, y1, x2, y2);
	}
	else{
		printf("두 함수의 교차점이 없습니다.");
	}
	
	return 0;
}

