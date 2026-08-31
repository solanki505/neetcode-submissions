class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        vector<int> dict_t(128, 0);
        for (char c : t) {
            dict_t[c]++;
        }
        int required = 0;
        for (int count : dict_t) {
            if (count > 0) required++;
        }
        int l=0,r=0;
        int formed=0;
        vector<int>window_counts(128, 0);
        int min_len=-1;
        int min_start=0;
        while (r<s.length()) {
            char c=s[r];
            window_counts[c]++;
            if (dict_t[c] > 0 && window_counts[c] == dict_t[c]) {
                formed++;
            }
            while (l <= r && formed == required) {
                if (min_len == -1 || r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    min_start = l;
                }
                char left_char = s[l];
                window_counts[left_char]--;
                if (dict_t[left_char] > 0 && window_counts[left_char] < dict_t[left_char]) {
                    formed--;
                }
                l++;
            }
            r++;
        }

        return min_len == -1 ? "" : s.substr(min_start, min_len);
    }
};

