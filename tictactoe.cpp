#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

const int ROW = 3, COLUMN = 3;

char board[ROW][COLUMN];

void setBoard();
void drawBoard();
void Move();
void checkWin();
void Done();

char currentSym = 'X';
int moves = 0;

int main()
{
	srand(time(NULL));
	setBoard();
	drawBoard();
	
	
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
	static int row = rand() % ROW;
	static int col = rand() % COLUMN;
	
	
	
	while (board[row][col] != '*')
	{
		row = rand() % ROW;
		col = rand() % COLUMN;
	}
	board[row][col] = currentSym;
	moves++;
	
	
	if (currentSym == 'X')
		currentSym = 'O';
	else
		currentSym = 'X';
}