class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        if(A.size() < 2)  return 0;
        vector b(A.size(),0);
        for(int i = A.size() -1 ; i >= 0; i--)
        {
          int tmp = A[i] - i;
           if(i == A.size() - 1)
              b[i] = tmp;
           else if (tmp > b[i + 1])
           {
               b[i] = tmp;
           }
           else
               b[i] = b[i + 1];
        }
        
        int max;
        for(int i = 0; i < A.size() - 1; i++)
        {
           int tmp = A[i] + i  + b[i + 1];
           if(i == 0)
              max = tmp;
           else if(tmp > max)
              max = tmp;
        }
        return max;
    }
};
