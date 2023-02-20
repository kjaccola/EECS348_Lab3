/*
 * Program2.c
 *
 *  Created on: Feb 14, 2023
 *      Author: kjaccola
 */
#include <stdio.h>


int input;
int score = 2;
int total;
int main(){
while(score>1){
	printf("Enter 0 or 1 to STOP\n");
	printf("Enter the NFL score: \n");
	scanf("%d",&score);
	if(score==0 || score ==1){
		break;
	}

	printf("Possible scoring combinations:\n");
	for(int t = 0; t <= score/6; t++){
		for(int f = 0; f <= score/3; f++){
			for(int s = 0; s<=score/2; s++){
				for(int td2 = 0; td2<= score/8;td2++){
					for(int td1 = 0; td1<= score/7; td1++){
						total = (6*t)+(3*f)+(2*s)+(8*td2)+(7*td1);
						if(total==score){
							printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2, td1, t, f,s);
						}

					}
				}
			}
		}
	}
	printf("\n");

}
}
