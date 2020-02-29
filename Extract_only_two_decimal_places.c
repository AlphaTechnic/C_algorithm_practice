#include <stdio.h>
int main(){
	float f;
	int i;
	
	printf("실수를 입력하세요 : ");
	scanf("%f", &f);
	
	i = (int)(f*100) % 100;  // 12.3456 -> 1234.56 -> 1234 -> 34
	
	if (i > 0){
		printf("i = %d\n", i);
	}
	else if (i == 0){
		printf("00");
	}
	else{
		printf("i = %d\n", -i);
	}
	
	return 0; 
} 
