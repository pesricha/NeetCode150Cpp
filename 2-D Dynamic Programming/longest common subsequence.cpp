#include<bits/stdc++.h>
using namespace std;

// Memoized solution / Top Down approach

class Solution {
public:

    int LCS(string &text1, string &text2, int pos1, int pos2, vector<vector<int>> &arr){

        if(pos1 == -1 || pos2 == -1) return 0;
        
        if(arr[pos1][pos2] != -1) return arr[pos1][pos2];

        if(text1[pos1] == text2[pos2])
        {
            return arr[pos1][pos2] = 1 + LCS(text1, text2, pos1 - 1, pos2 - 1, arr);
        }

        else return arr[pos1][pos2] = max(LCS(text1, text2, pos1, pos2 - 1, arr), LCS(text1, text2, pos1 - 1, pos2, arr));

    }

    int longestCommonSubsequence(string text1, string text2) {
        int pos1 = text1.size() - 1;
        int pos2 = text2.size() - 1;
        vector<vector<int>> arr(pos1+1, vector<int>(pos2+1,-1));
        return LCS(text1, text2, pos1, pos2, arr);
    }
};


// Tabulated / Bottom Up Approach

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> table(m+1, vector<int>(n+1, 0));
        
        for(int i = 1; i <= m ; i++)
        {
            for (int j = 1 ; j <= n ; j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    table[i][j] = 1 + table[i-1][j-1];
                } 

                else
                {
                    table[i][j] = max(table[i-1][j], table[i][j-1]);
                }
            }
        }

        return table[m][n];
    } 
};