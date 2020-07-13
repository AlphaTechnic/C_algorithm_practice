#include <stdio.h>
#include <stdlib.h>

int* input_integer(int *arrSize);
int get_lineNo(int *lineNo);
void print_array(int *arr, int arrSize, int lineNo);
void sort_reorder(int *arr, int arrSize);

int main(){
	int arrSize;
	int *arr;
	int i;
	int lineNo;
	
	get_lineNo(&lineNo);
	arr = input_integer(&arrSize);
	
	printf("\n 입력한 정수 배열data :");
	print_array(arr, arrSize, lineNo);
	
	printf("\n 크기 순서에 따라 sort된 정수 배열 data :");
	sort_reorder(arr, arrSize);
	print_array(arr, arrSize, lineNo);
	
	free(arr);
	
	return 0;	
}

int get_lineNo(int *lineNo){
	do{
		printf("라인 당 출력하는 개수 : ");
		scanf("%d", lineNo);
		printf("\n");
	}while(*lineNo < 1);

	return 0;
}

int* input_integer(int *arrSize){
	int numofcolumn;
	int* pint;
	int* p;
	
	while(1){
		printf("입력할 정수 배열의 크기 = ? ");
		scanf("%d", arrSize);
		if (*arrSize > 0){
			break;
		}
		else{
			printf("\n");
		}
	}
	
	pint = (int*)malloc(*arrSize*sizeof(int));
	
	// malloc 실패시 
	if (pint == NULL){
		printf("Memory allocation error \n");
		exit(100);
	}
	
	for (p = pint; p < pint + *arrSize; p++){
		scanf("%d", p);
	}
	
	return pint;
}

void print_array(int *arr, int arrSize, int lineNo){
	int* p;
	int count = 0; // line 변경을 위한 카운트변수 
	
	for (p = arr; p < arr+arrSize; p++){
		if (count % lineNo == 0){
			printf("\n");
		}
		printf("%3d ", *p);
		count ++;
	}
	printf("\n");
	
	return ;
}

void sort_reorder(int *arr, int arrSize){
	int* cur_pt;
	int* max_pt;
	int* walk_pt;
	int temp;
	
	for (cur_pt = arr; cur_pt < arr + (arrSize-1); cur_pt++){
		max_pt = cur_pt;
		for (walk_pt = cur_pt+1; walk_pt < arr+arrSize; walk_pt++){
			if (*(walk_pt) > *(max_pt)){
				max_pt = walk_pt;
			}
		}
		temp = *(max_pt);
		*(max_pt) = *(cur_pt);
		*(cur_pt) = temp;
	}
	return ;
}
