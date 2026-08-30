class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>arr;
        for(int i=0;i<nums.size();i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l=i+1,r=nums.size()-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]<0)l++;
                else if(nums[i]+nums[l]+nums[r]>0)r--;
                else {
                    arr.push_back({nums[i],nums[l],nums[r]});
                    l++;r--;
                    // Skip duplicates for the second element
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    // Skip duplicates for the third element
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
            }
        }
        return arr;
    }
};
