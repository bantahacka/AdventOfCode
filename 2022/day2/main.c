#include <stdlib.h>
#include <stdio.h>
#define IN_FILE "input.txt"
#define MAX_LINE_LEN 1024
#define PL_A line[0]
#define PL_B line[2]
#define DRAW tmp_a == tmp_b
#define ROCK_PAPER tmp_a == 1 && tmp_b == 2
#define PAPER_SCISSORS tmp_a == 2 && tmp_b == 3
#define SCISSORS_ROCK tmp_a == 3 && tmp_b == 1

 int main(int argc, char *argv[])
 {
	 char line[MAX_LINE_LEN];
	 int tmp_a, tmp_b, total_a, total_b = 0;
	 FILE *fp = fopen(IN_FILE, "r");
	 printf("[*]AOC Day 2: Rock Paper Scissors - Part 1\n");
	 while(fgets(line, MAX_LINE_LEN, fp) != NULL)
	 {
		 (PL_A == 'A') ? (tmp_a = 1, total_a += 1) : ((PL_A == 'B') ? (tmp_a = 2, total_a += 2) : (tmp_a = 3, total_a += 3));
		 (PL_B == 'X') ? (tmp_b = 1, total_b += 1) : ((PL_B == 'Y') ? (tmp_b = 2, total_b += 2) : (tmp_b = 3, total_b += 3));
		 (DRAW) ? (total_a += 3, total_b += 3) : (((ROCK_PAPER) || (PAPER_SCISSORS) || (SCISSORS_ROCK)) ? (total_b += 6) : (total_a += 6));
	 }
	 fprintf(stdout, "[*]Player A Final Score: %d\n[*]Player B Final Score: %d\n[*]Player %c Wins\n", total_a, total_b, (total_a > total_b) ? 'A' : 'B');
	 return 0;
 }
