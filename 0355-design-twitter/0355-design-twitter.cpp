class Twitter {

private:
    map<int, map<int, int>> followers; // followerId -> (followeeId -> 0/1), 0
                                       // means unfollowed, 1 means followed
    vector<pair<int, int>>
        tweets; // (tweetId, userId), maintains the order of tweets, most recent
                // at the end of the vector

public:
    Twitter() {
        // Constructor
    }

    void postTweet(int userId, int tweetId) {
        tweets.push_back(
            {tweetId, userId}); // Add the tweet to the tweets vector, storing
                                // tweetId and userId
    }

    vector<int> getNewsFeed(int userId) {
        vector<int>
            newsFeed; // Result vector to store the 10 most recent tweet IDs
        for (int i = tweets.size() - 1; i >= 0 && newsFeed.size() < 10;
             i--) { // Iterate from the end of tweets vector to get most recent
                    // tweets, limit to 10 tweets
            int tweetUserId = tweets[i].second; // Get the userId of the tweet
            // Check if the tweet is by the user themselves or by a followed
            // user
            if (tweetUserId == userId ||
                (followers[userId][tweetUserId] == 1)) {
                newsFeed.push_back(tweets[i].first); // Add tweetId to newsFeed
            }
        }
        return newsFeed; // Return the news feed
    }

    void follow(int followerId, int followeeId) {
        followers[followerId][followeeId] =
            1; // Set followeeId as followed for followerId
    }

    void unfollow(int followerId, int followeeId) {
        followers[followerId][followeeId] =
            0; // Set followeeId as unfollowed for followerId
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */