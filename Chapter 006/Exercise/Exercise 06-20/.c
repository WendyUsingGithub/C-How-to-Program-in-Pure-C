#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define GAMENUMBER 100000

int rollDice(); // Function prototype : Return a value of sum of two random dices 
int GameRecord(enum Status game, int array[2][22], int count); // Function prototype : call by reference and will change an array

enum Status { CONTINUE, WON, LOST }; // enumeration constants represent game status

int main()
{
	int result = 0; // result from function rollDice
	int i = 0; // counter
	int j = 0; // counter
	int goalPoint = 0; // when gamestatus is CONTINUE , record the result as goalPint for next roll
	int count = 1; // count how many turns it takes to end the game
	int woncount = 0; // increment when WON
	int lostcount = 0; //increment when LOST
	float avglength = 0.0; // to find the average length of the game
	int turnstoend[2][22] = { 0 }; // array arranged by how many turns it takes to end (include both WON[0][] and LOST[1][]) 
	float ratio[22]; // the ratio between WIN and LOST 
	enum Status game; // contains CONTINUE , WON , LOST

	srand(time(NULL));

	for (i = 0; i < GAMENUMBER; i++)
	{
		count = 1;
		result = rollDice();

		switch (result)
		{
			// throw 7 or 11 , WON at the first roll 
		case 7:
		case 11:
			game = WON;
			break;

			// throw 2 , 3 and 11 , LOST at the first roll 
		case 2:
		case 3:
		case 12:
			game = LOST;
			break;

			// game Contunue 
		default:
			game = CONTINUE;
			goalPoint = result;
			break;
		}

		while (game == CONTINUE)
		{
			count++;
			result = rollDice();

			// throw 7 , LOST
			if (result == 7)
			{
				game = LOST;
				break;
			}
			// throw the goal point , WON
			else if (result == goalPoint)
			{
				game = WON;
				break;
			}
			// game CONTINUE
			else
			{
				game = CONTINUE;
				goalPoint = result;
			}
		}

		avglength = avglength + count;

		// after each game finished ,  record the game WIN or LOST	
		// and classify by how many turns it takes to end the game and whether the game WON or LOST
		GameRecord(game, turnstoend, count);
	}

	for (i = 1; i < 22; i++)
	{
		ratio[i] = (float)turnstoend[0][i] / turnstoend[1][i];
		woncount += turnstoend[0][i];
		lostcount += turnstoend[1][i];
	}

	// woncount + lostcount should equal to GAMENUMBER
	if ((woncount + lostcount) != GAMENUMBER)
	{
		printf("Somethingwrong\n");
	}

	avglength = avglength / GAMENUMBER;

	printf("Total %d times\n", GAMENUMBER);
	printf("Won %d times\n", woncount);
	printf("Lost %d times\n\n", lostcount);
	printf("The average length of game Crap is %.2f\n\n", avglength);
	printf("Turns   ");

	for (i = 1; i < 22; i++)
	{
		ratio[i] = (float)turnstoend[0][i] / turnstoend[1][i];
	}

	for (i = 1; i < 21; i++)
	{
		printf("%6d", i);
	}

	printf("%6s", ">20");
	printf("\n");

	for (i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			printf("Won     ");
		}
		if (i == 1)
		{
			printf("Lost    ");
		}

		for (j = 1; j < 22; j++)
		{
			printf("%6d", turnstoend[i][j]);
		}
		printf("\n");
	}

	printf("Win/Lost");

	for (i = 1; i < 22; i++)
	{
		printf("%6.2f", ratio[i]);
	}

	printf("\n\n");
	printf("For the game end at the first roll , throw 7 or 11 wins , the chance of winning should be 2/36 + 6/36 = 8/36 = 0.22\n");
	printf("For the game end at the second roll , throw 4 , 5 , 6 , 8, 9 , 10 twice , the chance of winning should be\n");
	printf("(3/36)^2 + (4/36)^2 + (5/36)^2 + (5/36)^2 + (4/36)^2 + (3/36)^2 = 0.077\n");
	return 0;

}


// Return a value of sum of two random dices 
int rollDice()
{
	int dice1 = 0; // random number of dice 1
	int dice2 = 0; // ramdom number of dice 2
	int sum = 0; // sum of dice 1 anf dice 2
	int i = 0; // counter

	dice1 = (rand() % 6) + 1;
	dice2 = (rand() % 6) + 1;
	sum = dice1 + dice2;
	return sum;
}

// after each game finished , record the game WIN or LOST	
// and classify by how many turns it takes to end the game and whether the game WON or LOST
int GameRecord(enum Status game, int turnstoend[2][22], int count)
{
	if (count <= 20)
	{
		if (game == WON)
		{
			turnstoend[0][count]++;
		}
		if (game == LOST)
		{
			turnstoend[1][count]++;
		}
	}
	else
	{
		if (game == WON)
		{
			turnstoend[0][21]++;
		}
		if (game == LOST)
		{
			turnstoend[1][21]++;
		}
	}
	return 0;
}
