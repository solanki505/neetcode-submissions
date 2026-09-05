class Solution {
public:
    
    void rec(vector<int>& nums,vector<vector<int>>& ans,vector<int>& subset,int i){
        if(i>=nums.size()){ans.push_back(subset);return;}
            subset.push_back(nums[i]);
            rec(nums,ans,subset,i+1);
            subset.pop_back();
            rec(nums,ans,subset,i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        rec(nums,res,subset,0);
        return res;
    }
};
