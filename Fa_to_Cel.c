#include <stdio.h>
int main(){
	float Fa, Cel;
	
	printf("화씨 온도를 입력하시오:");
	scanf("%f", &Fa);
	printf("입력한 화씨온도 = %-10.1f\n", Fa);
	
	Cel = (Fa-32) * 5 / 9;
	
	printf("변환된 섭씨온도 = %-10.1f", Cel);
	
	return 0;
}
