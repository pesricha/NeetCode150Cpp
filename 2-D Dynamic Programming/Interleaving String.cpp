#include<bits/stdc++.h>
using namespace std;

// Recursion + Memoization

class Solution {
public:

    bool recurser(string &s1, string &s2, string &s3, int uno, int dos, int tres, vector<vector<int>> &table)
    {
        if(tres >= s3.size()) return true;

        if(table[uno][dos] != -1) return table[uno][dos];

        if(uno >= s1.size())
        {
            if (s2[dos] == s3[tres])
            {
                return table[uno][dos] = recurser(s1,s2,s3,uno,dos+1,tres+1,table);
            }
            else return table[uno][dos] =  false;
        }

        if(dos >= s2.size())
        {
            if(s1[uno] == s3[tres])
            {
                return table[uno][dos] = recurser(s1,s2,s3,uno+1, dos, tres+1, table);
            }
            else return table[uno][dos] = false;
        }

        if(s1[uno] == s3[tres] && s2[dos] == s3[tres])
        {
            return table[uno][dos] = recurser(s1, s2, s3, uno+1, dos, tres+1, table) || recurser(s1 ,s2, s3, uno, dos+1, tres + 1, table);
        }

        if(s1[uno] == s3[tres]) return table[uno][dos] = recurser(s1, s2, s3, uno+1, dos, tres+1, table);

        if (s2[dos] == s3[tres]) return table[uno][dos] = recurser(s1 ,s2, s3, uno, dos+1, tres + 1, table);

        return table[uno][dos] = false;


    }

    bool isInterleave(string s1, string s2, string s3) {
        
        vector<vector<int>> table(s1.size() + 1, vector<int> (s2.size() + 1, -1));

        if(s1.size() + s2.size() != s3.size()) return false;

        bool ans = recurser(s1, s2, s3, 0, 0 ,0, table);
        
        return ans;

    }
};