#include <stdio.h>

int getTime (long time[], int max_size);
void secToHours (long time, int* hours, int *minutes, int *seconds);

int main(){
	const int max_size = 10;
	long Time[10]= {0};
	int hours, minutes, seconds;
	int i;
	int numoftime;
	
	numoftime = getTime(Time, max_size);
	
	for (i =0; i < numoftime; i++){
		if (Time[i] !=0){
		secToHours(Time[i], &hours, &minutes, &seconds);
		printf("%4d = %2d:%02d:%02d\n", Time[i], hours, minutes, seconds);
		}
		else{
			break;
		}
	}
	printf("\n E N D    O F    P R O G R A M");
	
	return 0;	
}

int getTime (long time[], int max_size){
	int i;
	for (i = 0; i < max_size; i++){
		printf("변환할 시간을 입력하시기 바랍니다.");
		scanf("%d", &time[i]);
		if (time[i]==0){
			break;
		}
	}
	
	return i; 
}

void secToHours (long time, int* hours, int *minutes, int *seconds){
	long localTime;
	localTime = time;
	*seconds = localTime % 60;
	localTime = localTime / 60;
	*minutes = localTime % 60;
	*hours = localTime / 60;
}

