#include <Windows.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include "funcs.h"

int main(int numberOfArgs, char** args)
{
	FILE* file;
	
	for (int i = 0; i < numberOfArgs; i++)
	{
		if (stringCompare(args[i], "listen"))
		{
			if ((file = fopen(args[i + 1], "r")) == NULL)
			{
				printf("Can not read file!\n");
				return -1;
			}
			break;
		}
		else if ((stringCompare(args[i], "beep")))
		{
			Beep(atoi(args[i+1]), atoi(args[i+2]));
		}
		else if ((stringCompare(args[i], "help")))
		{
			printf("We have TWO commands:\n"
			"beep [frequency] [duration] - this function can makes the speaker sound with the specified parameters\n"
			"listen [name-of-file] - this function makes the system speaker sound with the specified parameters in the file\n"
			"Format of the file must be such as:\n"
			"[frequency] [duration]\n"
			"[...] [...]\n");
		}
	}

	int frequency = 0;
	int duration = 0;
	while (fscanf(file, "%d %d\n", &frequency, &duration) != EOF)
	{
		printf("Hertz - %d | Duration - %d\n", frequency, duration);
		Beep(frequency, duration);
	}
	fclose(file);
	return 0;
}