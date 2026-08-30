class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>a(128,-1);
        int ans=0,l=0;
        for(int i=0;i<s.length();i++){
            if(a[s[i]]!=-1){
                
                l=max(l,a[s[i]]+1);
            }
            a[s[i]]=i;
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};
