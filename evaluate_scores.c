#include <stdio.h>

#define QUIZ_WEIGHT 30
#define MIDTERM_WEIGHT 40
#define FINAL_WEIGHT 30
#define QUIZ_MAX 400.0
#define MIDTERM_MAX 200.0
#define FINAL_MAX 100.0
	
int main(){
//Local Declarations
	int quiz1;
	int quiz2;
	int quiz3;
	int quiz4;
	int totalQuiz;
	int midTerm1;
	int midTerm2;
	int totalMidTerm;
	int final;
	
	float quizPercent;
	float midTermPercent;
	float finalPercent;
	float totalPercent;
	
//tatements
	printf("*************  Quiz 점수 입력  *************\n");
	printf("Enter the score for the 1st Quiz: ");
	scanf("%d", &quiz1);
	printf("Enter the score for the 2nd Quiz: ");
	scanf("%d", &quiz2);
	printf("Enter the score for the 3rd Quiz: ");
	scanf("%d", &quiz3);
	printf("Enter the score for the 4th Quiz: ");
	scanf("%d", &quiz4);
	
	printf("*************  Mid Term 점수 입력  *************\n");
	printf("Enter the score for the 1st MidTerm: ");
	scanf("%d", &midTerm1);
	printf("Enter the score for the 2nd MidTerm: ");
	scanf("%d", &midTerm2);
	
	printf("*************  final 점수 입력  *************\n");
	printf("Enter the score for the final: ");
	scanf("%d", &final);		
	
	totalQuiz = quiz1 + quiz2 + quiz3 + quiz4; 
	totalMidTerm = midTerm1 + midTerm2;
	
	quizPercent = (float)totalQuiz * QUIZ_WEIGHT / QUIZ_MAX;
	midTermPercent = (float)totalMidTerm * MIDTERM_WEIGHT / MIDTERM_MAX;
	finalPercent = (float)final * FINAL_WEIGHT / FINAL_MAX;
	
	totalPercent = quizPercent + midTermPercent + finalPercent;
	
	printf("1st Quiz %4d\n", quiz1);
	printf("2nd Quiz %4d\n", quiz2);
	printf("3rd Quiz %4d\n", quiz3);
	printf("4th Quiz %4d\n", quiz4);
	printf("Quiz 점수 합계 %4d\n\n", totalQuiz);
	
	printf("1st mid term %4d\n", midTerm1);
	printf("2nd mid term %4d\n", midTerm2);
	printf("중간고사 점수 합계 %4d\n\n", totalMidTerm);
	
	printf("기말고사 점수 %4d\n\n", final);
	
	printf("Quiz %6.1f%%\n", quizPercent);
	printf("Mid Term %6.1f%%\n", midTermPercent);
	printf("기말고사 %6.1f%%\n", finalPercent);
	printf("------------------------------------------\n");
	printf("최종 평균 점수 %6.1f%%\n", totalPercent);
	
	return 0;
}
