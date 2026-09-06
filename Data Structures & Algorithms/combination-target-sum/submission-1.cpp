class Solution {
public:
    
    vector<vector<int>>ans;
    
    void dfs(vector<int>& nums,vector<int>&sum, int target,int idx){
        //pruning
        if(target<0 || idx>=nums.size())return;
        //base case
        if(target==0){
            ans.push_back(sum);
            return;
        }
        //recursive
        sum.push_back(nums[idx]);
        dfs(nums,sum,target-nums[idx],idx);
        sum.pop_back();
        dfs(nums,sum,target,idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int>sum;
        dfs(nums,sum,target,0);
        return ans;
    }
};
