#include <iostream>
#include <cmath>

using namespace std;

const int N = 4;
int maximum_flags = 0;

bool isSafe(int grid[], int row, int col) {
    for (int i = 0; i < row; i++) {
        if ((grid[i] == col) || ((abs(grid[i] - col)) == (abs(i - row)))) {
            return false;
        }
    }
    return true;
}

void placeFlags(int grid[], int row, int flagsPlaced) {
    if (row == N) {
        maximum_flags = max(maximum_flags, flagsPlaced);
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(grid, row, col)) {
            grid[row] = col;
            placeFlags(grid, row + 1, flagsPlaced + 1);
            grid[row] = -1;
        }
    }
    placeFlags(grid, row + 1, flagsPlaced);
}

int main() {
    int grid[N];
    for (int i = 0; i < N; i++) {
        grid[i] = -1;
    }
    placeFlags(grid, 0, 0);
    cout << "Maximum number of flags that can be placed: " << maximum_flags << endl;
    return 0;
}