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
/* #include <bits/stdc++.h>
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
} */

// C++ program to implement wildcard
// pattern matching algorithm
#include <bits/stdc++.h>
using namespace std;

// Function that matches input str with
// given wildcard pattern
bool strmatch(char str[], char pattern[], int m, int n)
{
	// lookup table for storing results of
	// subproblems
	vector<bool> prev(m + 1, false), curr(m + 1, false);

	// empty pattern can match with empty string
	prev[0] = true;

	// fill the table in bottom-up fashion
	for (int i = 1; i <= n; i++) {

		bool flag = true;
		for (int ii = 1; ii < i; ii++) {
			if (pattern[ii - 1] != '*') {
				flag = false;
				break;
			}
		}
		curr[0] = flag; // for every row we are assigning
						// 0th column value.
		for (int j = 1; j <= m; j++) {
			// Two cases if we see a '*'
			// a) We ignore ‘*’ character and move
			// to next character in the pattern,
			//	 i.e., ‘*’ indicates an empty sequence.
			// b) '*' character matches with ith
			//	 character in input
			if (pattern[i - 1] == '*')
				curr[j] = curr[j - 1] || prev[j];

			// Current characters are considered as
			// matching in two cases
			// (a) current character of pattern is '?'
			// (b) characters actually match
			else if (pattern[i - 1] == '?'
					|| str[j - 1] == pattern[i - 1])
				curr[j] = prev[j - 1];

			// If characters don't match
			else
				curr[j] = false;
		}
		prev = curr;
	}

	return prev[m];
}

int main()
{
	char str[] = "baaabab";
	char pattern[] = "*****ba*****ab";
	// char pattern[] = "ba*****ab";
	// char pattern[] = "ba*ab";
	// char pattern[] = "a*ab";
	// char pattern[] = "a*****ab";
	// char pattern[] = "*a*****ab";
	// char pattern[] = "ba*ab****";
	// char pattern[] = "****";
	// char pattern[] = "*";
	// char pattern[] = "aa?ab";
	// char pattern[] = "b*b";
	// char pattern[] = "a*a";
	// char pattern[] = "baaabab";
	// char pattern[] = "?baaabab";
	// char pattern[] = "*baaaba*";

	if (strmatch(str, pattern, strlen(str),
				strlen(pattern)))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
