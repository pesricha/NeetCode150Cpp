#include<bits/stdc++.h>
using namespace std;

// Memoized solution / Top Down approach

class Solution {
public:

    int botMove(int &m, int &n, int curr_m, int curr_n, vector<vector<int>> &arr)
    {
        if(curr_m == m-1 && curr_n == n-1) return 1;

        if(arr[curr_m][curr_n] != 0) return arr[curr_m][curr_n];

        if(curr_m == m-1 ) return 1;
        if(curr_n == n-1)  return 1;

        return arr[curr_m][curr_n] = botMove(m, n, curr_m + 1, curr_n, arr) + botMove(m, n, curr_m, curr_n + 1, arr);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> arr(m, vector<int>(n,0));
        return botMove(m, n, 0, 0, arr);
    }
};

// Tabulation / Bottom Up approach

class Solution {
public:

    int uniquePaths(int m, int n) {
            
            vector<vector<int>> table(m, vector<int> (n, 0));
            for(int i = 0 ; i < n ; i++)
            {
                table[m-1][i] = 1;
            }

            for(int i = 0 ; i < m ; i++)
            {
                table[i][n-1] = 1;
            }

            for(int i = m-2; i >= 0 ; i--)
            {
                for(int j = n-2; j >= 0 ; j--)
                {
                    table[i][j] = table[i][j+1] + table[i+1][j];
                }
            }

            return table[0][0];
        }
};

