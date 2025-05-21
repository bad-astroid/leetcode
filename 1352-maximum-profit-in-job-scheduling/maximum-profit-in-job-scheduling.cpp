class Solution {
public:
    struct Job{
        int start;
        int finish;
        int val;

        Job(int _start, int _finish, int _val) {
            start = _start;
            finish = _finish;
            val = _val;
        }
    
        bool operator<(const Job& other) const {
            return finish < other.finish;
        }
    };

    int findEarliestJob(const vector<Job>& jobs, int i) {
        int lo = 0, hi = i - 1, j = 0;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(jobs[i].start >= jobs[mid].finish) {
                j = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return j;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Job> jobs(1, Job(-1,-1,0));
        for(int i = 0; i < n; ++i) {
            jobs.push_back(Job(startTime[i], endTime[i], profit[i]));
        }
        sort(jobs.begin(), jobs.end());

        vector<int> ans(n+1);
        for(int i = 1; i <= n; ++i) {
            int j = findEarliestJob(jobs, i);
            ans[i] = max(ans[i-1], ans[j] + jobs[i].val);
        }
        return ans[n];
    }
};