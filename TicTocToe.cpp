#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void displayBoard();
void playerTurn();
bool gameOver();
void clearBoard();
bool playAgain();

char winner;
char turn;
bool draw = false;
char board[3][3] = { { '1','2','3' },{ '4','5','6' },{ '7','8','9' } };

int main()
{
	bool gamerunning = true;
	bool repeat = true;
	cout << "---------------------**Welcome to Tic Toc Toe Game**--------------------\n";
	cout << "Player 1 [X] ------ Player 2 [O]\n";
	turn = 'X';


	//repeat the game until user selects n to quit
	while (repeat)
	{
		displayBoard();
		playerTurn();
		if (gameOver())
		{
			if (winner == 'X')
				cout << endl << endl << "Player 1 [X] Wins. Game Over!\n";
			else if (winner == 'O')
				cout << endl << endl << "Player 2 [O] Wins. Game Over!\n";
			else
				cout << endl << endl << "It's a draw! Game Over!\n";
			gamerunning = false;
		}

		if (gamerunning == false)
		{
			if (playAgain())
			{
				clearBoard();
				repeat = true;
				turn = 'X';
				gamerunning = true;
			}
			else
				repeat = false;
		}

	}
	system("pause");
	return 0;
}

void playerTurn()
{
	int choice;
	int row = 0, column = 0;

	if (turn == 'X')
	{
		winner = 'X';
		cout << "Player 1 turn [X]: ";
	}
	else if (turn == 'O')
	{
		winner = 'O';
		cout << "Player 2 turn [O]: ";
	}
	cin >> choice;

	switch (choice)
	{
	case 1: row = 0; column = 0; break;
	case 2: row = 0; column = 1; break;
	case 3: row = 0; column = 2; break;
	case 4: row = 1; column = 0; break;
	case 5: row = 1; column = 1; break;
	case 6: row = 1; column = 2; break;
	case 7: row = 2; column = 0; break;
	case 8: row = 2; column = 1; break;
	case 9: row = 2; column = 2; break;
	default:
		cout << "Error !!!  Unexpected move, Try again \n ";
		playerTurn();
	}

	if (turn == 'X' && board[row][column] != 'O')
	{
		board[row][column] = 'X';
		turn = 'O';
	}
	else if (turn == 'O' && board[row][column] != 'X')
	{
		board[row][column] = 'O';
		turn = 'X';
	}
	else
	{
		cout << "The cell you cho0se is used! Choose another one\n";
		playerTurn();
	}
}


void displayBoard()
{
	cout << endl;
	cout << "    |    | " << endl;
	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "____|____|____" << endl;
	cout << "    |    | " << endl;
	cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "____|____|____" << endl;
	cout << "    |    | " << endl;
	cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
	cout << "    |    | " << endl;
}


bool gameOver()
{

	//horizontal checking for x -win
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
		return true;
	else if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
		return true;
	else if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
		return true;
	//vertical checking for x -win
	else if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
		return true;
	else if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
		return true;
	else if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
		return true;

	//Diagonal checking for x -win
	else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
		return true;
	else if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')
		return true;

	//horizontal checking for O -win
	if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
		return true;
	else if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
		return true;
	else if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
		return true;
	//vertical checking for O -win
	else if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
		return true;
	else if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
		return true;
	else if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
		return true;

	//Diagonal checking for O -win
	else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
		return true;
	else if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')
		return true;
	else
		//otherwise no x or O not win
		return false;
}

void clearBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
}

bool playAgain()
{
	char again;
	cout << "Do you want to play again? (Y/N) ";
	cin >> again;
	if (again == 'Y' || again == 'y')
	{
		return true;
	}
	else
	{
		cout << "Thanks for playing! goodbye !!" << endl << endl;
		return false;
	}

}
