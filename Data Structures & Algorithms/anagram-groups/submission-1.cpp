class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;

        for(int i=0;i<strs.size();i++){
            string key(26, 0);
            for(int j=0;j<strs[i].length();j++){
                key[strs[i][j]-'a']++;
            }
            mp[key].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto &a:mp){
            ans.push_back(a.second);
        }
        return ans;
    }
};
