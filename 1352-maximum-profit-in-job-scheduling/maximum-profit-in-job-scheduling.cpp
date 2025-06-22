class Solution {
public:
    struct Job {
        int left, right, profit;
        Job(int _left, int _right, int _profit) {
            left = _left;
            right = _right;
            profit = _profit;
        }

        bool operator< (Job &job) {
            return right < job.right;
        }
    };
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Job> jobs;
        jobs.push_back(Job(0, 0, 0));
        for(int i = 0; i < startTime.size(); ++i) {
            jobs.push_back(Job(startTime[i], endTime[i], profit[i]));
        }
        sort(jobs.begin(), jobs.end());
        map<int, int> dp;
        dp[0] = 0;
        for(int i = 1; i < jobs.size(); ++i) {
            auto it = dp.upper_bound(jobs[i].left);
            it--;

            dp[jobs[i].right] = max(jobs[i].profit + it->second, dp[jobs[i-1].right]);
        }

        return dp[jobs.back().right];
    }
};