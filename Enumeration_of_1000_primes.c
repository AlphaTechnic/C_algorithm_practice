#include <stdio.h>
int main(){
	int guess = 5;
	int prime[1000] = {2,3};
	int i;
	int index = 1;
	int check;
	
	printf ("%d번째 소수 : %d\n", 1, prime[0]);
	printf ("%d번째 소수 : %d\n", 2, prime[1]);
	
	for(;;){
		check = 0;
		for (i=0; i <= index; i++){
			if (guess % prime[i] != 0){
				check ++;
			}
			else{
				break;
			}
		}
		if (check ==  index + 1){
			index ++;
			prime[index] = guess;
			printf("%d번째 소수 : %d\n", index +1, guess);
			if (index == 999){
				break;
			}
		}
		guess += 2;
	}
	
	return 0;
}
