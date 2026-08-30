class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>mp;

        for(int i=0;i<strs.size();i++){
            vector<int>b(26,0);
            for(int j=0;j<strs[i].length();j++){
                b[strs[i][j]-'a']++;
            }
            mp[b].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto a:mp){
            ans.push_back(a.second);
        }
        return ans;
    }
};
