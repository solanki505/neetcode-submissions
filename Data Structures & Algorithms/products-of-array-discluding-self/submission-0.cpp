class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l=1,cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                cnt++;
            }
            else l*=nums[i];
        }
        if(cnt>1){
            vector<int>ans(nums.size(),0);
            return ans;
        }
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i] && cnt==0)ans[i]=l/nums[i];
            else if(nums[i] && cnt==1)ans[i]=0;
            else ans[i]=l;
        }
        return ans;
    }
};
