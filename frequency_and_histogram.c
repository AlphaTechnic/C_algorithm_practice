#include <stdio.h>
#include <stdlib.h>

#define MAX_ELMNTS 100
#define ANLYS_RNG 20

int getData (int data[], int size, int range);
int printData (int data[], int size, int lineSize);
void makeFrequency(int nums[], int last, int frequency[], int range);
void makeHistogram(int freq[], int range);

int main(){
	int size;
	int nums[MAX_ELMNTS];
	int frequency[ANLYS_RNG];
	
	size = getData(nums, MAX_ELMNTS, ANLYS_RNG);
	printData(nums, size, 10);
	
	makeFrequency(nums, size, frequency, ANLYS_RNG);
	makeHistogram(frequency, ANLYS_RNG);
	
	return 0;
}

int getData (int data[], int size, int range){
	int dataIn;
	int loader = 0;
	FILE* fpData;
	
	range--;
	if (!(fpData = fopen("C:\\Users\\juho3\\Desktop\\test\\P08-07.txt", "r"))){
		printf("Error opening file\a\a\n");
		exit(100);
	}
	while(loader<size &&
			fscanf(fpData, "%d", &dataIn) != EOF){
		if(dataIn >= 0 && dataIn <= range){
			data[loader++] = dataIn;
		}
		else{
			printf("\nData point %d invalid. Ignored. \n", dataIn);
		}			
	}
	if (loader == size){
		printf("\nToo much data. Process what read.\n");	
	}
	return loader;
}

int printData (int data[], int size, int lineSize){
	int numPrinted = 0;
	int i;
	
	printf("\n\n");
	for(i = 0; i<size ; i++){
		numPrinted++;
		printf("%3d", data[i]);
		if (numPrinted >= lineSize){
			printf("\n");
			numPrinted = 0;
		}
	}
	
	printf("\n\n");
	return 0;
}

void makeFrequency(int nums[], int last, int frequency[], int range){
	int f;
	int i;
	for (f = 0; f<range; f++){
		frequency [f] = 0;
	}
	for (i = 0; i<last; i++){
		frequency[nums [i]]++;
	}
	return;
}

void makeHistogram(int freq[], int range){
	int i, j;
	
	for (i = 0; i<range; i++){
		printf("%2d %2d ", i, freq[i]);
		for (j = 1; j<=freq[i]; j++){
			printf("*");
		}
		printf("\n");
	}
	return;
	
}

