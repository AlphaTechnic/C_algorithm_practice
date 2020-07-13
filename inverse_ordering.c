#include <stdio.h>
#define ROW_SIZE 4
#define COL_SIZE 8

void print_data(int arr[][8], int arrSize);
void inverseOrder(int* arr, int arrSize);

int main(){
	int data[4][8] = {{838, 758, 113, 515, 51, 627, 10, 419}, 
					{212, 86, 749, 767, 84, 60, 225, 543}, 
					{89, 183, 137, 566, 966, 978, 495, 311}, 
					{367, 54, 31, 145, 882, 736, 524, 505}};
	int row_num;
	int escape = 0;  // 무한루프를 빠져나올 수 있는 조건을 만드는 변수 
	int scanf_result;  // scanf의 리턴값으로, 프로그램의 동작을 관리 
	
	printf("\tBefore Reorder\n");
	print_data(data, COL_SIZE);
	
	while(1){
		while(1){
			printf("\n\tEnter the row index (0-3) : ");
			scanf_result = scanf("%d", &row_num);
			
			if (scanf_result == EOF){ // 사용자가 ctrl+Z를 입력한 경우 
				escape = 1;
				break;
		}
			else if (scanf_result == 0){  // 사용자가 문자를 입력한 경우, 버퍼를 비운다.
				fflush(stdin);
				break;
			}
			else if (row_num >=0 && row_num < ROW_SIZE){  // 사용자가 정상적인 숫자(0-3)을 입력한 경우 
				break;
			}
	    }
		if (escape){
			break;
		}
		else if (scanf_result != 0){
			printf("\t %d_th row after inverse ordering\n", row_num);
			inverseOrder(*(data+row_num), COL_SIZE);
		}    		
	}
	
	printf("\tAfter reordering\n");
	print_data(data, COL_SIZE);
	
	return 0;
}

void print_data(int arr[][8], int arrSize){
	int* p;
	int i;
	
	for (i = 0; i<ROW_SIZE; i++){
		printf("\t");
		for (p = *(arr + i); p < *(arr+i) + arrSize; p++){
		printf(" %4d ", *p);
		}
		printf("\n");
	}
	return ;
}

void inverseOrder(int* arr, int arrSize){
	int* front_pt;
	int* rear_pt;
	int* p;
	int temp;

	for (front_pt = arr, rear_pt = arr + (arrSize - 1); 
		front_pt < rear_pt ; 
		front_pt ++, rear_pt--){
			
		temp = *front_pt;
		*front_pt = *(rear_pt);
		*(rear_pt) = temp;
	}
		
	for (p = arr; p < arr+arrSize; p++){
		printf("\t %4d ", *p);
	}
	printf("\n");
	return ;
}
