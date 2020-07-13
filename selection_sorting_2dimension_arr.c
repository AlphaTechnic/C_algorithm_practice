#include <stdio.h>

int PrintArr(int arr[][2], int numofrows);
int SelectionSort(int arr[][2], int numofrows);

int main(){
	int mark[10][2] = {{18, 90}, {237, 47}, {35, 105}, {5, 25}, 
	{76, 739}, {103, 26}, {189, 38}, {22, 110}, {156, 31}, {49, 245}};
	int numofrows = 10;
	
	printf("Original Table\n");
	PrintArr(mark, numofrows);
	
	SelectionSort(mark, numofrows);
	
	printf("\nAscending sorted table for the first column is as follows.\n");
	PrintArr(mark, numofrows);
	
	return 0;
		
}

int PrintArr(int arr[][2], int numofrows){
	int i;
	
	for (i = 0; i < numofrows; i++){
		printf("id number;%3d, mark %3d :\n", arr[i][0], arr[i][1]);
	}
	
	return 0;
}

int SelectionSort(int arr[][2], int numofrows){
	int cur_ind, min_ind, walk_ind;
	int temp;
	int i;
	
	for (cur_ind = 0; cur_ind < numofrows -1; cur_ind++){
		min_ind = cur_ind;
		walk_ind = cur_ind+1;
		for (walk_ind; walk_ind < numofrows; walk_ind++){
			if (arr[walk_ind][0] <= arr[min_ind][0]){
				min_ind = walk_ind;
			}
		}
		
		for (i = 0; i <= 1; i++){
			temp = arr[min_ind][i];
			arr[min_ind][i] = arr[cur_ind][i];
			arr[cur_ind][i] = temp;
		}
	}
	
	return 0;
}


