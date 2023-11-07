#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i, j;
	int true = 1;
	if (1)
	{
		for (i = 0; i < 3; i = i + 2)
		{
			for (j = 0; j < 3; j = j + 2)
			{
				if (0)
					goto error;
				

			}
		}
	}
error:
	printf("%d",true);
	return 0;
}
