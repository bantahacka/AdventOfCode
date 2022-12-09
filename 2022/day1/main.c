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
	int i,j;
	FILE *fd;

	// Create "Key Value pair" struct. Use ints for both vars as we need to perform arithmetic on the values.
	struct kv_store
	{
		int key;
		int value;
	};

	struct kv_store kv[MAX_KV_LEN];
	struct kv_store kv_total[MAX_KV_LEN];
	struct kv_store temp;

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
			kv_total[elfno].key = elfno;
			kv_total[elfno].value = tmpbuf;
			tmpbuf = 0;
			elfno++;
			continue;
		}
	}

	// Sort kv_total by total calories in descending order. Print Element 0 and total of the first 3 elements.
	for(i=0; i < elfno; i++)
	{
		for(j=i+1; j < elfno; j++)
		{
			if(kv_total[i].value < kv_total[j].value)
			{
				temp=kv_total[i];
				kv_total[i] = kv_total[j];
				kv_total[j] = temp;
			}
		}
	}

	fprintf(stdout, "[*]The elf carrying the most calories is %d with %d.\n", kv_total[0].key, kv_total[0].value);
	fprintf(stdout, "[*]The 3 elves carrying the most weight are %d, %d and %d with a combined total of %d.\n", kv_total[0].key, kv_total[1].key, kv_total[2].key, (kv_total[0].value + kv_total[1].value + kv_total[2].value));
	return 0;
}
