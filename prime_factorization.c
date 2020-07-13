#include <stdio.h>
#include <stdlib.h>      // exit를 사용하기 위해 
#include <math.h>        // sqrt를 사용하기 위해 

int getnum(int *num);           // 사용자로부터 num값을 입력 받음  
int factorize(int num);         // 정수를 인자로 받아, 소인수분해 한 결과를 printf하고, 소인수의 개수를 return하는 함수 
int isprime(int num);           // 정수를 인자로 받아, 그 정수가 소수인지 합성수인지 여부를 판단하는 함수  

int main(){
	int num;
	
	getnum(&num);
	factorize(num);
	isprime(num);
	
	return 0;
}

int getnum(int *num){
		
	printf("Input an positive integer : ");
	scanf("%d", num);
	if (*num != 0){
		printf("%d = ", *num);
	} 
	
	if (*num == 0){
		printf("\n End of program");
		exit(100);
	}
	else if (*num <2){
		while(1){
			printf("\nIt is a invalid number !\n\n");
			printf("Input an positive integer : ");
	        scanf("%d", num);
			if (*num >= 2){                  // 2이상인 정수 값을 입력해야만, while문을 빠져나오게 된다. 
				break;
			}		
		}
	}			
	return 0;	
}

int factorize(int num){
	int i;              // for문에서 사용할 변수 
	int num_storage;    // 정수를 임시로 저장하는 변수
	int primefactor;    // 소인수 
	int power;          // 지수(해당 소인수의 개수) 
	int count = 0;      // 소인수의 개수를 세는 변수 
	
	
	
	for (i = 2; i<=num; i++){
		power = 0;
		primefactor = i;
		num_storage = num;
		/*  아래 while문을 통과하면서 num값은 변화하게 된다. 그런데 
		while문을 빠져나온 뒤, 그 다음 문장 if조건문에서의 점검은 
		'변화를 주기 전 num값'으로 점검해야만 하는 문제가 있었다.
		그래서 변화를 주기 전의 num값을 임시로 저장하는 변수인 
		num_storage를 설정하였다.*/       
		
		while(num%i==0){
			power += 1;
			count += 1; 
			num = num / i;
		}
		
		if(num_storage % i == 0){
			if (power==1){                   // power가 1인 경우, power를 출력하지 않기 위한 조건문 
				if (num == 1){
					printf("%d", primefactor);
					break;
				}
				else{
					printf("%d*", primefactor);
				}
			}								
			else{                            // power가 1이 아니라면, power를 함께 출력해준다. 
				if (num == 1){
					printf("%d^%d", primefactor, power);
					break;
				}
				else{
					printf("%d^%d*", primefactor, power);
				}
			}
		}
	
	}
	return count;                         // 소인수의 개수를 반환 
}

int isprime(int num){                     
	int isprime = 1;
	int i;
	
	/*인자로 주어지는 num이 커지는 경우, 실행시간이 길어지게 되어, 다음의 명제를 이용하였다.
	"주어진 자연수 N이 소수이기 위한 필요 충분조건은 
	N이 N의 제곱근보다 크지 않은 어떤 소수로도 나눠지지 않는다."
	위 명제를 이용하면, 주어지는 인자 num보다 1 작은 수까지 방문하지 않고, 
	더 작은 수인 root(num)까지 방문하는 코드를 작성할 수 있게되어, 실행시간을 단축시킬 수 있다. 
	제곱근을 구하기 위하여, sqrt를 사용하였다.*/
	for (i = 2; i<=(int)sqrt(num); i++){   
		if (num%i==0){
			isprime = 0;            // 인자로 주어지는 정수가 그 정수보다 작은 어떤 수로 나누어 떨어지는 경우, 소수이냐(isprime?) 에 대한 질문에 아니오(0)라고 답한다. 
			break;
		}
	}
	
	switch(isprime){
		case 0:
			printf("\nIt is a composite number !");
			break;
		case 1:
			printf("\nIt is a prime number !");
			break;
	}
	return 0;
}
