#include <iostream>
using namespace std;

const int N = 5;
bool solveMaze(int maze[N][N], int x, int y, int solution_array[N][N])
{
    if ((x == N - 1) && (y == N - 1) && (maze[x][y] == 1))
    {
        solution_array[x][y] = 1;
        return true;
    }

    if (((x >= 0) && (y >= 0) && (x < N) && (y < N) && (maze[x][y] == 1)))
    {
        solution_array[x][y] = 1;

        if (solveMaze(maze, x + 1, y, solution_array) || solveMaze(maze, x, y + 1, solution_array))
        {
            return true;
        }

        solution_array[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{
    int maze[N][N] = {{1, 0, 1, 0, 1},
                      {1, 1, 1, 1, 1},
                      {0, 1, 0, 1, 1},
                      {1, 0, 0, 1, 1},
                      {1, 1, 1, 0, 1}};

    int solution_array[N][N] = {0};

    if (solveMaze(maze, 0, 0, solution_array))
    {
        cout << "The lion has reached the meat...!" << endl
             << endl;
        cout << "Solution array:" << endl;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                cout << solution_array[i][j] << " ";
            }
            cout << endl;
        }
        cout << "-----------------------" << endl;
    }
    else
    {
        cout << "The lion could not reach the meat." << endl;
    }

    return 0;
}