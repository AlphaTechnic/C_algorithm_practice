#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int ran, ran0to6;
	printf("-1, 2, 5, 8, 11, 14, 17 숫자 집합으로부터 난수를 만드는 프로그램 입니다.\n");
	
	srand(time(NULL));
	ran = rand();
	
	ran0to6 = ran%7;
	printf("%d", ran0to6*3 -1);
	
	return 0; 
}
