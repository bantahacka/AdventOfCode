#include <stdlib.h>
#include <stdio.h>
#define IN_FILE "input.txt"
#define MAX_LINE_LEN 5
#define PL_A line[0]
#define PL_B line[2]
 int main(int argc, char *argv[])
 {
	 char line[MAX_LINE_LEN];
	 int tmp_a, tmp_b, total_a, total_b= 0;
	 FILE *fp = fopen(IN_FILE, "r");
	 printf("[*]AOC Day 2: Rock Paper Scissors - Part 2\n");
	 while(fgets(line, MAX_LINE_LEN, fp) != NULL)
	 {
		 PL_A == 'A' ? (tmp_a = 1, total_a += 1) : PL_A == 'B' ? (tmp_a = 2, total_a += 2) : (tmp_a = 3, total_a += 3);
		 PL_B == 'X' ? (total_b += 0) : PL_B == 'Y' ? (total_b += (3 + tmp_a)) : (total_b += 6);
		 if(PL_B == 'X')
		 {
			 switch(PL_A)
			 {
			 case 'A':
				 total_b += 3;
				 break;
			 case 'B':
				 total_b += 1;
				 break;
			 case 'C':
				 total_b += 2;
				 break;
			 }
		 }
		 if(PL_B == 'Z')
		 {
			 switch(PL_A)
			 {
			 case 'A':
				 total_b += 2;
				 break;
			 case 'B':
				 total_b += 3;
				 break;
			 case 'C':
				 total_b += 1;
				 break;
			 }
		 }
	 }
	 fprintf(stdout, "[*]Player A Final Score: %d\n[*]Player B Final Score: %d\n[*]Player %c Wins\n", total_a, total_b, (total_a > total_b) ? 'A' : 'B');
	 return 0;
 }
