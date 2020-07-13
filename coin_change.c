#include <stdio.h>
int main(){
	int change;
	int numof500, numof100, numof50, numof10;
	
	printf("거스름돈 금액을 입력 바랍니다. ");
	scanf("%d", &change);
	change = change - change % 10;
	
	numof500 = change / 500;
	change = change - numof500 * 500;
	numof100 = change / 100;
	change = change - numof100 * 100; 
	numof50 = change / 50;
	change = change - numof50 * 50;
	numof10 = change / 10;
	
	printf("500원: %d개, 100원 : %d개, 50원 : %d개, 10원 : %d개.", 
			numof500, numof100, numof50, numof10);
			
	return 0;
}
