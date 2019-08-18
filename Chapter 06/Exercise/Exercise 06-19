#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int dice1 = 0; // random number of dice 1
	int dice2 = 0; // ramdom number of dice 2
	int sum = 0; // sum of dice 1 anf dice 2
	int i = 0; // counter
	int frequency[13] = { 0 }; // track how many times each kind of sum appears 
	                           // contains information from [2] to [12]
	                           // array subscript stands for sum

	srand(time(NULL)); 

	for (i = 0; i < 36000; i++)
	{
		dice1 = (rand() % 6) + 1;
		dice2 = (rand() % 6) + 1;
		sum = dice1 + dice2;
		frequency[sum]++; // increment appropriate frequency counter 
	}

	for (i = 0; i < 11; i++)
	{
		printf("%6d",i+2);
	}

	printf("\n");

	for (i = 0; i < 11; i++)
	{
		printf("%6d", frequency[i + 2]);
	}

	return 0;
}
