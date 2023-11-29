#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

void nextgen(vector<vector<bool>>& grid, vector<vector<bool>>& newGrid);
void print(const vector<vector<bool>>& grid);

int main() {
    const int rows = 20, cols = 30;

    // Initializing with a random pattern
    vector<vector<bool>> grid(rows, vector<bool>(cols, false));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = (rand() % 100 < 20);
        }
    }

    // Simulating 50 iterations
    for (int iter = 0; iter < 50; iter++) {
        vector<vector<bool>> newGrid(grid);
        nextgen(grid, newGrid);
        print(newGrid);
        cout << endl;
        this_thread::sleep_for(0.5s);
    }

    return 0;
}

void nextgen(vector<vector<bool>>& grid, vector<vector<bool>>& newGrid) {
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int liveNeighbors = 0;

            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0) continue;
                    int newI = (i + k + rows) % rows;
                    int newJ = (j + l + cols) % cols;
                    if (grid[newI][newJ]) liveNeighbors++;
                }
            }

            if (grid[i][j] && (liveNeighbors < 2 || liveNeighbors > 3)) {
                newGrid[i][j] = false;
            } else if (!grid[i][j] && liveNeighbors == 3) {
                newGrid[i][j] = true;
            } else {
                newGrid[i][j] = grid[i][j];
            }
        }
    }
}

void print(const vector<vector<bool>>& grid) {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            if (cell) {
                cout << "X ";
            } else {
                cout << "O ";
            }
        }
        cout << endl;
    }
}