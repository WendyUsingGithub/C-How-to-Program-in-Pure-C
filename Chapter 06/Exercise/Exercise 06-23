#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

int printArray(int array[SIZE][SIZE]); // print an array
int turtleWalking(enum Paint paintStatus, enum Direction absolutDirection, int floor[SIZE][SIZE], int* xPtr, int* yPtr, int steps); 
// fuction that allow turtle move and paint

enum Paint { NOPAINT = 1, DOPAINT = 2 }; // turtle can paint or not while walking
enum Direction { STRAIGHT = 0, RIGHT = 1, DOWNWARD = 2, LEFT = 3 }; // turtle can move in four directions

int main()
{
	int steps = 0; // in case 5 , turtle should move assigned steps
	int order = 0; // order from user that tells turtle what to do
	int direction = 0; // 0 : straight , 1 : right , 2 : downward , 3 : left
	int floor[SIZE][SIZE] = { 0 }; // turtle paint in this array
	int x = 0; // record the current x position of turtle
	int* xPtr = &x; // adress of x
	int y = 49; // record the current y position of turtle (turtle departure from lowe left corner)
	int* yPtr = &y; // adress of y
	enum Paint paintStatus = NOPAINT; // the initial state , turtle do NOPAINT
	enum Direction absoluteDirection = STRAIGHT; // the initial state , the turtle moves STRAIGHT forward

	while(1)
	{
		scanf_s("%d", &order); 
		
		if (order == 5)
		{
			scanf_s("%d", &steps);
		}

		switch (order)
		{
		// do not paint
		case 1:
			paintStatus = order;
			break;
        // paint
		case 2:
			paintStatus = order;
			break;
        // turn right
		case 3:
			direction += 1;
			direction %= 4;
			if (direction < 0)
			{
				direction = +4;
			}
			absoluteDirection = direction;
			break;
        // turn left
		case 4:
			direction -= 1;
			printf("after enter 4:%d\n", direction);
			direction = direction % 4;
			printf("after modulus : %d\n", direction);
			if (direction == -1 )
			{
				direction = 3;
			}
			absoluteDirection = direction;
			break;
		// move
		case 5:
			absoluteDirection = direction;
			turtleWalking(paintStatus, absoluteDirection, floor, xPtr, yPtr, steps);
			break;
        // print array
		case 6:
			printArray(floor);
			break;
        // end of data input
		case 9:
			return 0;
		}
	}
}

//Print an array
int printArray(int array[SIZE][SIZE])
{
	int i = 0;
	int j = 0;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (array[i][j] == 1)
			{
				printf("#");
			}
			if (array[i][j] == 0)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}

// If the order is move , there are two things to do , move the turtle , and if needed , paint the floor
int turtleWalking(enum Paint paintStatus, enum Direction absolutDirection, int floor[SIZE][SIZE], int* xPtr, int* yPtr, int steps)
{
	int i = 0;

	switch (absolutDirection)
	{		
	case STRAIGHT:
		if (paintStatus == DOPAINT)
		{
			for (i = 0; i < steps; i++)
			{
				floor[*yPtr - i][*xPtr] = 1; // the positive direction in array is different from our usual cordinate
			}
		}
		*yPtr -= steps;
		break;

	case RIGHT:
		if (paintStatus == DOPAINT)
		{
			for (i = 0; i < steps; i++)
			{
				floor[*yPtr][*xPtr + i] = 1;
			}
		}
		*xPtr += steps;
		break;

	case DOWNWARD:
		if (paintStatus == DOPAINT)
		{
			for (i = 0; i < steps; i++)
			{
				floor[*yPtr + i][*xPtr] = 1;
			}
		}
		*yPtr += steps;
		break;

	case LEFT:
		if (paintStatus == DOPAINT)
		{
			for (i = 0; i < steps; i++)
			{
				floor[*yPtr][*xPtr - i] = 1;
			}
		}
		*xPtr -= steps;		
		break;
	}
	return 0;
}
