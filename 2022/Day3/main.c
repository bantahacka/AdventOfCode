#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define FILE_IN "input.txt"
#define RUCKLEN (int)strlen(line)

int main (int argc, char *argv[])
{
	// Declare variables
	int flag,i, j, k,l, ptotal = 0;;
	char line[1024];
	FILE *fp = fopen(FILE_IN, "r");

	while(fgets(line, 1024, fp) != NULL)
	{
		flag=0;
		line[RUCKLEN -1] = '\0';
		for (i = 0; i < RUCKLEN / 2; i++)
		{
			char ch = line[i];
			j = (int)(ch);
			for(l = (RUCKLEN/2); l < RUCKLEN; l++)
			{
				if(flag==1)
				{
					break;
				}
				char chcmp = line[l];
				k = (int)(chcmp);
				if(j == k)
				{
					flag=1;
					if((j >= 65) && (j <= 90))
					{
						printf("MATCH FOUND! Line: %s. Char: %c at pos %d matches pos %d. Priority: %dz\n", line, line[i], i, l, (j-38));
						ptotal += (j - 38);
					}
					else if((j >= 97) && (j <= 122))
					{
						printf("MATCH FOUND! Line: %s. Char: %c at pos %d matches pos %d. Priority: %d\n", line, line[i], i, l, (j-96));
						ptotal += (j - 96);
					}
				}
			}
		}

	}
	// Print total at end
	printf("%d", ptotal);
	return 0;
}
