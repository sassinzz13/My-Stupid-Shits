#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <fstream>
#include <thread>


//mga putang inang variables

using namespace std;
bool gameOver;
const int width = 100;
const int height = 20;
int x, y, ballsX, ballsY, score;
int buratX[100], buratY[100];
int Burat;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;


void Setup()
{
	;

	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	ballsX = rand() % width;
	ballsY = rand() % height;
	score = 0;
}



void Draw()
{

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });


	//top wall
	for (int i = 0; i < width + 2; i++)
		cout << "#"; cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";

			if (i == y && j == x)
				cout << "o";
			else if (i == ballsY && j == ballsX)
				cout << "0";
			else
			{
				bool print = false;
				for (int k = 0; k < Burat; k++)
				{
					if (buratX[k] == j && buratY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}

			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;
	cout << "score: " << score << endl;

}

void Input()
{
	//we use 2 functions async and sync
	if (_kbhit())
	{
		switch (_getch())//switches direction
		{
		case 'w':
			dir = UP;
			break;
		case 'a':
			dir = LEFT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}
void Logic()
{
	int prevX = buratX[0];
	int prevY = buratY[0];
	int prev2X, prev2Y;
	for (int i = 1; i < Burat; i++)
	{
		prev2X = buratX[i];
		prev2Y = buratY[i];
		buratX[i] = prevX;
		buratY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
		buratX[0] = x;
		buratY[0] = y;

	}

	switch (dir)
	{

	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;



	default:
		break;
	}

	if (x > width || x < 0 || y > height || y < 0)
		gameOver = true;
	for (int i = 0; i < Burat; i++)
		if (buratX[i] == x && buratY[i] == y)
			gameOver = true;
	if (x == ballsX && y == ballsY)
	{

		score += 10;
		ballsX = rand() % width;
		ballsY = rand() % height;
		Burat++;
	}
}

int main()
{
	srand(time(NULL));
	Setup();
	Draw();
	while (!gameOver)

	{
		Draw();
		Input();
		Logic();
		Sleep(100);

		
	}
	{
		int numOfStudents, numOfScore, high_score = 0, total_score = 0;
		string nameOfStudents, name;
		float Average_score = 0.0;


		cout << "Enter Name Here:" << endl;
		cin >> numOfStudents;
		for (int i = 0; i < numOfStudents; i++)
		{
			cout << "Enter name, (separate first and last names with underscores) after that press enter and enter their score:" << endl;
			cin >> nameOfStudents;
			cout << "What's their score?" << endl;
			cin >> numOfScore;
			total_score += numOfScore;
			for (int x = 0; x < i; x++)
			{
				if (numOfScore > high_score)
				{
					high_score = numOfScore;
					name = nameOfStudents;
				}
			}
		}
		Average_score = static_cast <float> (total_score) / numOfStudents;
		cout << "Average score is " << "300" << endl;
		cout << "Person with highest score is " << "Izumi" << " with a score of " << "2000" << "." << endl;


	}
	{
		//this would do for now

		//initialize the game

		bool restart = false, 
			quit = false;

		while (!quit) {
			//Main loop of the game
		}

		

		return 0;
	}

}