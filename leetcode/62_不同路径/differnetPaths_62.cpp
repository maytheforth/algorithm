/*
问题描述: 一个机器人位于m*n网格的左上角，机器人每次只能向下
或向右移动一步，机器人试图到达网格的右下角，问总共有多少条不
同的路径。
*/
class Solution {
public:
    int combination(int m,int n)
    {
       int table[200][101] = {0};
       for(int i = 0; i <= 100 ; i++)
       {
           table[i][0] = 1;
           table[i][i] = 1;
       }
        
       if(n == 0) return table[m][0];
        
       for(int j = 1; j <=n ; j++)
       {
         for(int i = 1; i <=m ; i++)
         {
             table[i][j] = table[i-1][j] + table[i - 1][j - 1];
         }
       }
       return table[m][n];
    }
    int uniquePaths(int m, int n) {
        int min = (m < n)?(m-1):(n-1);
        return combination(m+n-2,min);
    }
};
