/*    
#include <bits/stdc++.h>
using namespace std;
 
string direction = "DLRU";
int dr[4] = {1, 0, 0, -1};
int dc[4] = {0, -1, 1, 0};
 
bool isValid(int r, int c, int n, vector<vector<int>>& maze)
{
    return r >= 0 && c >= 0 && r < n && c < n && maze[r][c];
}
 
void findPath(int r, int c, vector<vector<int>>& maze, int n, vector<string>& ans, string& currentPath)
{
    if (r == n - 1 && c == n - 1)
    {
        ans.push_back(currentPath);
        return;
    }
 
    maze[r][c] = 0;
 
    for (int i = 0; i < 4; i++)
    {
        int nextr = r + dr[i];
        int nextc = c + dc[i];
        if (isValid(nextr, nextc, n, maze))
        {
            currentPath += direction[i];
            findPath(nextr, nextc, maze, n, ans, currentPath);
            currentPath.pop_back();
        }
    }
    maze[r][c] = 1;
}
 
int main()
{
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};
 
    int n = maze.size();
    vector<string> result;
    string currentPath = "";
 
    findPath(0, 0, maze, n, result, currentPath);
 
    if (result.size() == 0)
        cout << -1;
    else
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
    cout << endl;
 
    return 0;
} */
#include <bits/stdc++.h>
using namespace std;
#define N 4

int ld[30] = { 0 };
int rd[30] = { 0 };
int cl[30] = { 0 };

void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << " " << (board[i][j] == 1 ? "Q" : ".");
        cout << endl;
    }
    cout << endl;
}

bool solveNQUtil(int board[N][N], int col)
{
    if (col >= N) {
        // If all queens are placed, print the solution
        printSolution(board);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if ((ld[i - col + N - 1] != 1 && rd[i + col] != 1) && cl[i] != 1) {
            board[i][col] = 1;
            ld[i - col + N - 1] = rd[i + col] = cl[i] = 1;

            res =  solveNQUtil(board, col + 1) || res;

            board[i][col] = 0; // BACKTRACK
            ld[i - col + N - 1] = rd[i + col] = cl[i] = 0;
        }
    }

    return res;
}

bool solveNQ()
{
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };

    if (!solveNQUtil(board, 0)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    return true;
}

int main()
{
    solveNQ();
    return 0;
}