class Solution {
public:
    int reverse(int x)
    {
        unsigned int store = (unsigned int) x;
        if(x < 0)
          store = (~store) + 1;

        long long  answer = 0;
        int remain;
        while(store)
        {
          remain = store % 10;
          answer = answer * 10 + remain;
          store = store / 10;
        }

        if(x < 0 ) answer = -answer;

        if(x >= 0)
        {
          if((answer >> 31) != 0 )
            return 0;
          else
            return answer;
        }
        else
        {
          if(~(answer >> 31) != 0)
            return 0;
          else
            return answer;
        }
   }
};