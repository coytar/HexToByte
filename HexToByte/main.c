#include <stdlib.h>
#include <stdio.h>

char szResult[20] = "FA 0F 11 22\0";

void main() 
{
	int pid_data[4];
	HexToByte(pid_data);
	printf("%d %d %d %d\n", pid_data[0], pid_data[1], pid_data[2], pid_data[3]);
}

int HexToByte(int* pid_data)
{
	char *command;
	int i, j;
	int ret;

	// upper limit for "for loop"?
	for (i = 0, j = 0;; i++, j += 3) {
		if (szResult[j] != NULL && szResult[j + 1] != NULL)
		{
			pid_data[i] = convert(szResult[j]) * 16 + convert(szResult[j + 1]);
		}
		else
			return 0;
	}
	return 1;
}

int convert(char c) {
	if (c >= 'A' && c <= 'F') {
		return (c - 65) + 10;
	}
	else if (c >= 'a' && c <= 'f') {
		return (c - 97) + 10;
	}
	else if (c >= '0' && c <= '9') {
		return (c - 48);
	}
	return 0;
}

