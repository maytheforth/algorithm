class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(!nums.size()) return 0;
        int pos = 0;
        for(auto iter = nums.begin(); iter != nums.end(); iter++)
        {
            if(*iter != val)
            {
               nums[pos] = *iter;
               pos++;
            }
        }
        return pos;
    }
};
