#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define FILE_IN "input.txt"
#define RUCKLEN (int)strlen(line)

int main (int argc, char *argv[])
{
	// Declare variables
	int counter = 0;
	int ptotal = 0;
	int flag = 0;
	int i,j,k,l;
	char line[1024];
	char r1[1024];
	char r2[1024];
	char r3[1024];
	FILE *fp = fopen(FILE_IN, "r");

	while(fgets(line, 1024, fp) != NULL)
	{
		if(flag == 1)
		{
			memset(r1, '\0', 1024);
			memset(r2, '\0', 1024);
			memset(r3, '\0', 1024);
		}
		flag = 0;
		line[RUCKLEN -1] = '\0';
		if(counter == 0)
		{
			memcpy(r1, line, RUCKLEN);
			counter++;
			continue;
		}
		else if(counter == 1)
		{
			memcpy(r2, line, RUCKLEN);
			counter++;
			continue;
		}
		else if(counter == 2)
		{
			memcpy(r3, line, RUCKLEN);
			counter = 0;
			for(i = 0; i < strlen(r1); i++)
			{
				if(flag == 1)
				{
					break;
				}
				for(j = 0; j < strlen(r2); j++)
				{
					if(r1[i] == r2[j])
					{
						if(flag == 1)
						{
							break;
						}
						for(k = 0; k < strlen(r3); k++)
						{
							if(flag == 1)
							{
								break;
							}
							if((r3[k] == r1[i]) && (r3[k] == r2[j]))
							{
								flag = 1;
								fprintf(stdout, "Matching letter: %c on lines: %s, %s and %s\n", r3[k], r1, r2, r3);
								char ch = r3[k];
								l = (int) ch;
								if((l >= 65) && (l <= 90))
								{
									ptotal += (l - 38);
								}
								else if((l >= 97) && (l <= 122))
								{
									ptotal += (l - 96);
								}
								break;
							}
						}
					}
				}
			}
		}
	}
	// Print total at end
	printf("%d", ptotal);
	return 0;
}
