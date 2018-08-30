#include "funcs.h"

BOOL stringCompare(char* str1, char* str2)
{
	for (int i = 0; *(str1 + i) != '\0'; i++)
	{
		if (*(str1 + i) != *(str2 + i))
			return FALSE;
	}
	return TRUE;
}