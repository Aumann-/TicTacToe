#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

const int ROW = 3, COLUMN = 3;

char board[ROW][COLUMN];

//initialize board
void setBoard();
//draw board to screen
void drawBoard();
//make a move
void Move();
//Not implemented
void checkWin();
void Done();

//don't care that this is bad practice
char currentSym = 'X';
int moves = 0;

int main()
{
	srand(time(NULL));
	setBoard();
	drawBoard();
	
	//go til board is full
	while (moves < (ROW*COLUMN))
	{
		Move();
		drawBoard();
	}
	
	return 0;
}

void setBoard()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			board[i][j] = '*';
		}
	}
	
	
}

void drawBoard()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			cout << " | " << board[i][j];
		}
		cout << " |" << endl;
	}
	cout << endl;
}

void Move()
{
	//made static to prevent too much overhead;
	static int row = rand() % ROW;
	static int col = rand() % COLUMN;	
	
	while (board[row][col] != '*')
	{
		row = rand() % ROW;
		col = rand() % COLUMN;
	}
	
	board[row][col] = currentSym;
	moves++;
	
	//change symbol for next turn
	if (currentSym == 'X')
		currentSym = 'O';
	else
		currentSym = 'X';
}