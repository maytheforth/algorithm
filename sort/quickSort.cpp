#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& nums, int start, int end)
{
   int privot = nums[end];
   int i = start;
   for(int j = start; j < end; j++)
   {
       if(nums[j] < privot)
       {
	  swap(nums[i],nums[j]);
	  i++;
       }	       
   }
   swap(nums[end],nums[i]);
   return i;   
}

void quickSort(vector<int>& nums,int start,int end)
{
   if(start >= end) return;	
   int privot = partition(nums ,start ,end);
   quickSort(nums, start , privot - 1);
   quickSort(nums, privot + 1 , end);

}

int main()
{ 
  vector<int> nums{3,14,15,9,26,5,3,12,34,56,23};
  quickSort(nums,0,nums.size() -1 );
  for(auto iter = nums.begin(); iter != nums.end(); iter++)
  {
     cout << *iter << " ";
  }
  return 0;
}
