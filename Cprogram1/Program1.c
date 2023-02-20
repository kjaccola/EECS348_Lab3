/*
 * Program1.c
 *
 *  Created on: Feb 13, 2023
 *      Author: kjaccola
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *monthNames[]= {"January","February","March","April","May","June","July","August", "September","October","November","December"};
float monthNums[12];



int main(){
char userinput[12];
FILE* textfile;
char line[12];
printf("Input the name of the file to be read: \n");
scanf("%s", &userinput);
textfile = fopen(userinput, "r");
int num = 0;
while(fgets(line, 12, textfile)){
	monthNums[num]= atof(line);
	num ++;
}
fclose(textfile);
printTotals();
salesSummary();
moving();
sorted();
}
void printTotals(){
printf("Monthly Sales Report for 2022:\n\n");
printf("%-15s%-15s \n\n","Month","Sales");
for(int i = 0; i<12; i++){
	printf("%-15s$%-15.2f \n",monthNames[i], monthNums[i]);
}
printf("\n\n");
}
void salesSummary(){
int minmonthnum = 0;
int maxmonthnum = 0;
float totals = monthNums[0];
for(int i = 1; i<12; i++){
	if(monthNums[minmonthnum]> monthNums[i])minmonthnum= i;
	if(monthNums[maxmonthnum]< monthNums[i])maxmonthnum =i;
	totals = totals +monthNums[i];
}
float average = totals/12;
printf("Sales Summary: \n\n");
printf("%-15s$%-10.2f(%-5s%c\n","Minimum Sales:",monthNums[minmonthnum], monthNames[minmonthnum],')');
printf("%-15s$%-10.2f(%-5s%c\n","Maximum Sales:", monthNums[maxmonthnum], monthNames[maxmonthnum],')');
printf("%-15s$%-15.2f\n", "Average Sales:",average);
printf("\n\n");
}
void moving(){
	printf("Six-Month Moving Average Report:\n\n");
	int start = 0;
	int end = 5;
	float averages[7];
	int num = 0;
	while(end<12){
		float curTotal = 0;
		for(int begin = start; begin<=end;begin++){
			curTotal = curTotal +monthNums[begin];
		}
		averages[num]= curTotal/6;
		num++;
		start++;
		end++;
	}
	for(int i = 0; i<7; i++){
		printf("%-10s%-2c%-10s$%-15.2f\n", monthNames[i],'-', monthNames[i+5], averages[i]);
	}
	printf("\n\n");

}
void sorted(){
	printf(" Sales Report (Highest to Lowest):\n\n");
	printf("%-10s%-10s\n\n","Month","Sales");

	for(int i = 0; i< 12; i++){
		int max = 0;
		for(int j = 0; j<12; j++){
			if (monthNums[j]> monthNums[max])max = j;
		}
		printf("%-10s $%-10.2f\n", monthNames[max], monthNums[max]);
		monthNums[max]= 0;
	}
}
