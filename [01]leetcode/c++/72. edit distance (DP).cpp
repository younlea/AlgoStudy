 class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if(m * n == 0) 
            return m + n;
        
        int DP[m + 1][n + 1];
        for(int i = 0; i <= m; i++)
            DP[i][0] = i;
        for(int i = 0; i <= n; i++)
            DP[0][i] = i;
        
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
            {
                int top = DP[i - 1][j] + 1;
                int left = DP[i][j - 1] + 1;
                int top_left = DP[i-1][j-1];
                if(word1[i-1] != word2[j-1])
                    top_left++;
                DP[i][j] = min(top,min(left,top_left));
            }
        return DP[m][n];
    }
};

//https://www.youtube.com/watch?v=ZkgBinDx9Kg
//https://kkminseok.github.io/posts/leetcode_Edit_Distance/
