#include<bits/stdc++.h>

using namespace std;


class Solution {
private:
    // Helper function to check if the current cell is within the board boundaries
    bool isSafe(int i, int j, int n, int m){
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    // DFS function to mark all connected 'O's starting from a boundary cell
    void DFS(int i, int j, vector<vector<char>>& board, vector<vector<int>>& directions, int n, int m) {
        // Base case: If the cell is out of bounds or not an 'O', return
        if(!isSafe(i, j, n, m) || board[i][j] != 'O') {
            return;
        }

        // Mark the current 'O' as 'F' (to denote it's part of a safe region)
        board[i][j] = 'F';

        // Explore all four directions
        for(auto& dir : directions) {
            int x = i + dir[0]; // Row movement
            int y = j + dir[1]; // Column movement

            DFS(x, y, board, directions, n, m); // Recursively apply DFS
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();    // Number of rows
        int m = board[0].size(); // Number of columns

        // Define the four possible directions (up, down, left, right)
        vector<vector<int>> directions = {
            {-1, 0}, // Up
            {0, -1}, {0, 1}, // Left and Right
            {1, 0}  // Down
        };

        // Step 1: Apply DFS for all boundary 'O's and mark them as safe ('F')
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Check boundary conditions (first row, last row, first column, last column)
                if (board[i][j] == 'O' && (i == 0 || i == n - 1 || j == 0 || j == m - 1)) {
                    DFS(i, j, board, directions, n, m); // Start DFS from boundary 'O'
                }
            }
        }

        // Step 2: Flip all 'O' to 'X' (surrounded regions) and all 'F' back to 'O' (safe regions)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; // Surrounded 'O' becomes 'X'
                } else if (board[i][j] == 'F') {
                    board[i][j] = 'O'; // Safe 'F' becomes 'O'
                }
            }
        }
    }
};