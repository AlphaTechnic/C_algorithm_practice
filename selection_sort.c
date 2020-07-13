#include <stdio.h>

void selectionSort(int list[], int last);

int main(){
	int list[5] = {5,2,1,3,4};
	int i;
	
	selectionSort(list, 5);
	
	for(i=0; i<=4; i++){
		printf("list[%d] = %d ", list[i], i);	
	}
}

void selectionSort(int list[], int last){
	int smallest;
	int tempData;
	int current;
	int walk;
	
	for (current = 0; current<last; current++){
		smallest = current;
		for(walk = current+1; walk <= last; walk++){
			if (list[walk]<list[smallest]){
				smallest = walk;
			}
		}
		
		tempData = list[current];
		list[current] = list[smallest];
		list[smallest] = tempData;
	}
	
	return;
}
