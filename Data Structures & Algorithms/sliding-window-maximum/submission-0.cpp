class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        multiset<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
            if(s.size()>k){
                s.erase(s.find(nums[i-k]));
            }
            if(i>=k-1){
                ans.push_back(*s.rbegin());
            }
        }
        return ans;   
    }
};
