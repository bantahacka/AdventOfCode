#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define IN_FILE "input.txt"
#define MAX_LINE_LEN 30720
#define MAX_KV_LEN 30720

int main(int argc, char *argv[])
{
	// Variable declaration
	char line[MAX_LINE_LEN];
	int counter = 0;
	int elfno = 0;
	int tmpbuf = 0;
	int i;
	FILE *fd;

	// Create "Key Value pair" struct. Use ints for both vars as we need to perform arithmetic on the values.
	struct kv_store
	{
		int key;
		int value;
	};

	struct kv_store kv[MAX_KV_LEN];
	struct kv_store kv_total[MAX_KV_LEN];

	printf("[*]AOC Day 1: Calorie Counting\n");

	// Open file
	fd = fopen(IN_FILE, "r");
	if (fd == NULL)
	{
		// File does not exist. Exit
		fprintf(stdout, "\n[*]%s not found in current working directory.", IN_FILE);
		return -1;
	}

	// Iterate through file line by line. Place lines into kv[n].value with kv[n].key as the elf number (elfno). Continue until an empty line is found.
	while(fgets(line, MAX_LINE_LEN, fd) != NULL)
	{
		if(strlen(line) == 1)
		{
			elfno ++;
			continue;
		}
		else
		{
			kv[counter].key = elfno;
			sscanf(line, "%d", &kv[counter].value);
			//fprintf(stdout, "%d + %d\n", kv[counter].key, kv[counter].value);
			counter++;
			continue;
		}
	}

	// Upon EOF, we can iterate through kv. Reset elfno to 0 and start iterating. If elfno for next value in kv hasn't changed, add value to kv_total[elfno].value. If it does change, move on to the next efls values.
	elfno = 0;
	for(i=0;i < counter;i++)
	{
		tmpbuf += kv[i].value;
		if(kv[i+1].key == elfno)
		{
			continue;
		}
		else
		{
			//fprintf(stdout, "NoElf: %d %d\n", kv[i].key, elfno);
			kv_total[elfno].key = elfno;
			kv_total[elfno].value = tmpbuf;

			tmpbuf = 0;
			elfno++;
			continue;
		}
	}

	// Once complete, iterate through kv_total and find the largest number, print to screen.
	tmpbuf = kv_total[0].value;
	for(i=0; i < elfno; i++)
	{
		if(kv_total[i].value == 0)
		{
			continue;
		}
		else
		{
			if(kv_total[i].value > tmpbuf)
			{
				tmpbuf = kv_total[i].value;
				counter = i;
			}
			continue;
		}
	}

	fprintf(stdout, "[*]The elf carrying the most calories is %d with %d", counter, tmpbuf);

	return 0;
}
