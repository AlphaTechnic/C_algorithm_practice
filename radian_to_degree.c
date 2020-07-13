#include  <stdio.h>

int main(){
	const float pi = 3.141592;
	const float rad_1 = 57.295779;
	float rad;
	float deg;
	
	printf("Enter the angle in radians: ");
	scanf("%f", &rad);
	
	deg = 180 * rad/pi;
	
	printf("%5.3f radians is %6.3f degree", rad, deg);
	
	return 0;
}
