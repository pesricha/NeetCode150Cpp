#include<bits/stdc++.h>
using namespace std;

// Memoized Solution / Top Down 
class Solution {
public:

    int minD(string word1, string word2, int index1, int index2, vector<vector<int>> &vec)
    {

        if(index1 < 0) return index2+1;
        if(index2 < 0) return index1+1;
        
        if(vec[index1][index2] !=-1) return vec[index1][index2];
        if(word1[index1] == word2[index2])
        {
            return vec[index1][index2] = 0 + minD(word1, word2, index1-1, index2-1, vec);
        }

        else 
        {
           int replaced = 1 + minD(word1, word2, index1 - 1, index2 - 1, vec);
           int deleted = 1+ minD(word1, word2, index1 - 1, index2, vec);
           int inserted = 1+ minD(word1, word2, index1, index2-1, vec);
           return vec[index1][index2] = min(replaced,min(deleted,inserted));
        }
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> vec(word1.size(), vector<int> (word2.size(), -1));
        return minD(word1, word2, word1.size()-1, word2.size()-1, vec);
    }
};

