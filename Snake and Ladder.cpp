#include<stdio.h> // Declaration of Header files
#include<stdlib.h>
#include<math.h>
int y, m = 0, r, n = 0, p; // Global variables
int num_of_snake, num_of_ladder;
int snake_head[100];// Array of snake head positions
int snake_end[100]; // Array of snake end positions
int ladder_bottom[100]; // Array of ladder bottom positions
int ladder_head[100]; // Array of ladder head positions
void dice()// Generating random numbers
{
	y = rand() % 7;
	if (y == 0)
		y = y + 3;
}
void checkladder()// Check whether a ladder is present or not
{
	for (int i = 0; i < num_of_ladder; i++)
	{
		if (ladder_bottom[i] == m)
		{
			printf("\nCongrats!! you have got a ladder");
			m = ladder_head[i];
			break;
		}

	}

}
void checkladdercomp() // Check whether a ladder is present or not
{
	for (int i = 0; i < num_of_ladder; i++)
	{
		if (ladder_bottom[i] == n)
		{
			printf("\nComputer has got a ladder");
			n = ladder_head[i];
			break;
		}

	}
}
void checksnake() // Check whether a snake is present or not
{
	for (int i = 0; i < num_of_snake; i++)
	{
		if (snake_head[i] == m)
		{
			printf("\nOhh no, a snake bits you");
			m = snake_end[i];
			break;
		}
	}

}
void checksnakecomp() // Check whether a snake is present or not
{
	for (int i = 0; i < num_of_snake; i++)
	{
		if (snake_head[i] == n)
		{
			printf("\nHere is a snake");
			n = snake_end[i];
			break;
		}
	}

}
void comp()
{
	if (p == 1) // Play with computer
	{
		printf("\nComputer is rolling");
		dice();
		printf("\nDice shows the number %d", y);
		n = n + y;
		checkladdercomp();
		checksnakecomp();
		if (n > 100)
		{
			printf("\n No chance to move forward");
			n = n - y;
		}
		if (n == 100)
		{
			printf("\n\nComputer won the game");
		}
		printf("\nComputer's current position is %d\n\n", n);
	}
	if (p == 2) // Play with another player
	{
		printf("\nPlayer 2 is rolling\n");
		printf("Enter 0 to roll dice: ");
		scanf("%d", &r);
		if (r == 0)
		{
			dice();
			printf("\nDice shows the number %d", y);
			n = n + y;
			checkladdercomp();
			checksnakecomp();
			if (n > 100)
			{
				printf("\nNo chance to move forward");
				n = n - y;
			}
			if (n == 100)
			{
				printf ("\n\nHurrah !!!! Player2 won the game");

			}
		}
		printf("\nPlayer2 current position is %d\n\n", n);
	}
}


int main()
{
	printf("WELCOME TO THE SNAKE AND LADDER GAME\n\n"); // Snake ladder
	printf("Enter number of snakes\n");
	scanf("%d", &num_of_snake);
	printf("Enter number of ladders\n");
	scanf("%d",	&num_of_ladder);
	printf("Enter positions of snake head\n");
	for (int i = 0; i < num_of_snake; i++)
	{
		scanf("%d", &snake_head[i]);
	}
	printf("Enter positions of snake bottom\n");
	for (int i = 0; i < num_of_snake; i++)
	{
		scanf("%d", &snake_end[i]);
	}
	printf("Enter positions of ladder bottom\n");
	for (int i = 0; i < num_of_ladder; i++)
	{
		scanf("%d", &ladder_bottom[i]);
	}
	printf("Enter positions of ladder head\n");
	for (int i = 0; i < num_of_ladder; i++)
	{
		scanf("%d", &ladder_head[i]);
	}
	printf("Press 1. To play with computer\n");
	printf("Press 2. To play with another player\n");
	scanf("%d", &p);
	while (1)
	{
		printf("\nYou are rolling\n");
		printf("Enter 0 to roll dice: ");
		scanf("%d", &r);
		if (r == 0)
		{
			dice();
			printf("\nDice shows the number %d", y);
			m = m + y;
			checkladder();
			checksnake();
			if (m > 100)
			{
				printf("\nNo chance to move forward");
				m = m - y;
			}
			if (m == 100)
			{
				printf ("\n\nHurrah !!!! You won the game ");
				break;
			}
			printf("\nYour current position is %d\n\n", m);
			if (100 > n >= 0)
			{
				comp();
			}
			if (n == 100)
			{
				break;
			}
		}
	}
	return 0;
}
