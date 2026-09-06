class Twitter {
private:
    int timeStamp;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int, int>>> tweets; // maps userId to {time, tweetId}

public:
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        // Max-heap stores: {time, tweetId, userId, index_in_tweets_vector}
        priority_queue<vector<int>> pq; 
        
        // Gather the user and everyone they follow
        vector<int> users = {userId};
        if (follows.count(userId)) {
            for (int followee : follows[userId]) {
                users.push_back(followee);
            }
        }
        
        // Push the most recent tweet from each user into the heap
        for (int u : users) {
            if (!tweets[u].empty()) {
                int lastIdx = tweets[u].size() - 1;
                pq.push({tweets[u][lastIdx].first, tweets[u][lastIdx].second, u, lastIdx - 1});
            }
        }
        
        // Extract up to 10 of the most recent tweets
        while (!pq.empty() && res.size() < 10) {
            auto curr = pq.top();
            pq.pop();
            
            res.push_back(curr[1]); // Add tweetId to result
            
            int u = curr[2];
            int nextIdx = curr[3];
            
            // If the user has older tweets, push the next one into the heap
            if (nextIdx >= 0) {
                pq.push({tweets[u][nextIdx].first, tweets[u][nextIdx].second, u, nextIdx - 1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            follows[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            follows[followerId].erase(followeeId);
        }
    }
};
