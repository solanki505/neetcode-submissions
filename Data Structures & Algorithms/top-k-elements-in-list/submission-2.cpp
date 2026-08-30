
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& pair : count) {
            buckets[pair.second].push_back(pair.first);
        }
        vector<int> ans;
        for (int i = nums.size(); i >= 0; i--) {
            for (int num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};