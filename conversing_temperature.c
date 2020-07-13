#include <stdio.h>

int getCel (float* Cel);
int Cel2Fah (float* Cel, float* Fah);
int printFah (float Fah);

int getFah (float* Fah);
int Fah2Cel (float* Cel, float* Fah);
int printCel (float Cel);

int main(){
	float Cel, Fah;
	
	getCel(&Cel);
	Cel2Fah(&Cel, &Fah);
	printFah (Fah);
	
	getFah(&Fah);
	Fah2Cel(&Fah, &Cel);
	printCel(Cel);
	
	return 0;
}

int getCel (float* Cel){
	printf("섭씨 온도를 입력하시기 바랍니다 : ");
	scanf("%f", Cel);
	
	return 0;
}

int Cel2Fah (float* Cel, float* Fah){
	*Fah = (9 * (*Cel) / 5) + 32;
	
	return 0; 
}

int printFah (float Fah){
	printf("화씨 온도는 %5.2f 입니다.\n\n", Fah);
	
	return 0;
} 
//////////////////////////////////////////////////////
//
int getFah (float* Fah){
	printf("화씨 온도를 입력하시기 바랍니다 : ");
	scanf("%f", Fah);
	
	return 0; 
}

int Fah2Cel (float* Cel, float* Fah){
	*Cel = 5 * (*Fah - 32) / 9;
		
	return 0; 
}

int printCel (float Cel){
	printf("섭씨 온도는 %5.2f 입니다.\n", Cel);
	
	return 0;
} 
