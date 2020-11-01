#include <iostream>
#define N 4		//size of the grid

using namespace std;

bool solveMazeUtil(int maze[N][N],int x,int y,int sol[N][N]);//the maze and (x,y) for current position and the current solution array

bool valid(int x, int y);

void printSol(int sol[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << sol[i][j] << " ";
		cout << endl;
	}

}
void solveMaze(int maze[N][N], int x, int y)//x,y initial position
{
	//define the solution array as it's initaily is 0 bcs there is no path found yet
	int sol[N][N] = { {0,0,0,0},
					{0,0,0,0},
					{0,0,0,0},
					{0,0,0,0}
				 };

	
	if (solveMazeUtil(maze, x, y, sol) == true)
		printSol(sol);
	else
		cout << "there is no path" << endl;
}


bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
	//check if the current position valid or no
	if (valid(x, y) == false || maze[x][y] == 0)
		return false;
	//wining condition
	if (x == N - 1 && y == N - 1)
	{
		sol[x][y] = 1;
		return true;
	}
	sol[x][y] = 1;
	
	if (solveMazeUtil(maze, x + 1, y, sol)) { return true; }
	if (solveMazeUtil(maze, x, y + 1, sol))  { return true; }

	sol[x][y] = 0;
	return false;
}

bool valid(int x,int y)
{
	if (x >= 0 && x <N && y >= 0 && y < N)
		return true;
	return false;
}

int main()
{
	int maze[N][N] = { { 1, 0, 0, 0 },
					   { 1, 1, 0, 1 },
					   { 0, 1, 0, 0 },
					   { 1, 1, 1, 1 } 
				   };

	solveMaze(maze,0,0);

	cout << "-----------------------------------" << endl;

	int maze1[N][N] = { { 1, 0, 0, 0 },
					    { 1, 1, 0, 1 },
					    { 0, 0, 0, 0 },
					    { 1, 1, 1, 1 }
	};

	solveMaze(maze1, 0, 0);
}