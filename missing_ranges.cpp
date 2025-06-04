#include<iostream> 
#include<vector> 

using namespace std; 

class Solution{
public: 
     vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper){
       vector<vector<int>> res; 
       int n = nums.size(); 

       if(n==0){
         res.push_back({lower,upper}); 
         return res; 
       }
       if(nums[0]>lower) res.push_back({lower,nums[0]-1}); 

       for(int i=1; i<n; ++i){
         if(nums[i] != nums[i-1]+1){
           res.push_back({nums[i-1]+1, nums[i]-1}); 
         }
       }
       if(nums[n-1]!=upper){
         res.push_back({nums[n-1]+1, upper});
       }
       return res; 
     }
};
int main(){
  vector<int> nums = {0,1,3,50,75}; 
  int lower = 0; 
  int upper = 99; 
  Solution sol; 
  vector<vector<int>> res= sol.findMissingRanges(nums, lower, upper); 
  for(auto vec: res){
    cout << "[" ; 
    for(int n:vec) {
      cout << n << ", " ; 
    }
    cout << "] " << endl ; 
  }
  return 0; 
}
