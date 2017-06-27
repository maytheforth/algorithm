#include<iostream>
#include<string>
#include<vector>
using namespace std;
int isInVector(string s,vector<string>& wordDict)
{
   int i;
   for(i = 0 ; i < wordDict.size();i++)
   {
      if(s.compare(wordDict[i]) == 0)
        return 1;
   }
   return 0;
}

bool wordBreak(string s, vector<string>& wordDict)
{
    int length = s.length();
    int* a = new int[length];
    int i;
    for(i = 0; i < length; i++)
      a[i]=0;

    i = 0;
    while(i < length)
    {
       int j;
       for(j = 0;j < i;j++)
       {
          if(a[j] == 1)
          {
            string substring = s.substr(j + 1,i - j);
            if(isInVector(substring,wordDict))
            {
              a[i] = 1;
              break;
            }
          }
       }
       string substring2 = s.substr(0,i + 1);
       if(isInVector(substring2,wordDict))
        a[i] = 1;

      i++;
    }

    int answer = a[length - 1];
    delete[] a;
    return (answer == 1)?true:false;
}

int main()
{
  vector<string> wordDict;
  wordDict.push_back("leety");
  wordDict.push_back("code");
  string s = "leetcode";
  cout<<wordBreak(s,wordDict)<<endl;
  return 0;
}
