#include <stdio.h>

int main(){
	int a;
	int b;
	int r;
	int *pa = &a;
	int *pb = &b;
	int *pr = &r;
	
	printf("Enter the first number : ");
	scanf("%d", pa);
	printf("Enter the second number : ");
	scanf("%d", pb);
	
	*pr = *pa + *pb;
	printf("\n%d + %d is %d\n", *pa, *pb, *pa + *pb);
	*pr = *pa - *pb;
	printf("%d - %d is %d\n", *pa, *pb, *pa - *pb);
	*pr = *pa * *pb;
	printf("%d * %d is %d\n", *pa, *pb, *pa*(*pb));
	*pr = *pa / *pb;
	printf("%d / %d is %d\n", *pa, *pb, *pa / *pb);
	*pr = *pa % *pb;
	printf("%d %% %d is %d", *pa, *pb, *pa % *pb);
	
	return 0;
}
