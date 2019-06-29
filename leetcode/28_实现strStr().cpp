class Solution {
public:
    bool compare(string haystack,string needle,int i ,int size)
    {
       for(int j = 0; j < size; j++)
       {
          if(haystack[i + j] != needle[j])
            return false;
       }
       return true;
    }
    int strStr(string haystack, string needle) {
        if(!needle.size())  return 0;
        if(!haystack.size()) return -1;
        map<char,int> keyset;
        for(auto iter = needle.begin(); iter != needle.end(); iter++)
        {
           auto keyiter = keyset.find(*iter);
           if(keyiter == keyset.end())
              keyset.insert(make_pair(*iter,iter - needle.begin()));
           else
              keyset[*iter] = iter - needle.begin();
        }

        int nsize = needle.size();
        int hsize = haystack.size();
        
        int i = 0;
        while( i < hsize + 1 - nsize )
        {
           if(compare(haystack,needle,i,nsize))
             return i;
           else
           {
               if ( i + nsize >= hsize)
                 return -1;
               else
               {
                   char ch = haystack[i + nsize];
                   auto iter = keyset.find(ch);
                   if(iter == keyset.end())  // 没找到
                   {
                       i = i + nsize + 1;
                   }
                   else
                   {
                       i = i + nsize - iter->second;
                   }
               }
           }
       }
       return -1;
    }
};