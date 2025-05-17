class Leaderboard {
public:
    multiset<int> scores;
    map<int,int> players;
    Leaderboard() { }
    
    void addScore(int playerId, int score) {
        if (!players.contains(playerId)) {
            scores.insert(score);
            players[playerId] = score;
            return;
        }
    
        auto scoreIt = scores.find(players[playerId]);
        scores.erase(scoreIt);
    
        int newScore = players[playerId] + score;
        scores.insert(newScore);
        players[playerId] = newScore;
    }
    
    int top(int K) {
        auto rit = scores.rbegin();
        int ret = 0;
        while(K--) {
            ret += *rit;
            rit++;
        }

        return ret;
    }
    
    void reset(int playerId) {
        auto scoreIt = scores.find(players[playerId]);
        scores.erase(scoreIt);
        players.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */