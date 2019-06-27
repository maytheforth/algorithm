class Solution {
public:
    void part(vector<vector<int>>& answer,vector<int> store, int pos, vector<int>& nums)
    {
        answer.push_back(store);
        if(pos == nums.size())
        {
           return;
        }
        for(int i = pos; i < nums.size(); i++)
        {
           store.push_back(nums[i]);
           part(answer,store, i + 1 , nums);
           store.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> answer;
         if(nums.size() == 0) return answer;
         vector<int> store;
         part(answer,store,0,nums);
        return answer;
    }
};
