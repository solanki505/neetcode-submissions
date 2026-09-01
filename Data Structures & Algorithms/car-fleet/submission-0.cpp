class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>>arr(n);
        for(int i=0;i<n;i++){
            arr[i]={position[i],speed[i]};
        }
        sort(arr.rbegin(),arr.rend());
        stack<double>st;
        int cnt=0;
        for(int i=0;i<n;i++){
            double time=(target-arr[i].first)/double(arr[i].second);
            if(st.empty()|| st.top()<time){
                st.push(time);
                cnt++;
            }
        }
        return cnt;
    }
};
