class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int n;
    int m;
    vector<vector<bool>> visited;
    vector<vector<int>> a;
    vector<int> ans;
    bool canVisit(int x, int y) {
        if(x >= n || x < 0) return false;
        if(y >= m || y < 0) return false;
        if(visited[x][y]) return false;
        return true;
    }
    void dfs(int x, int y, int dir) {
        cout << x << ' ' << y << endl;
        ans.push_back(a[x][y]);
        visited[x][y] = true;
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[(dir + i)%4];
            int ny = y + dy[(dir + i)%4];
            if(canVisit(nx, ny)) {
                dfs(nx, ny, dir + i);
                return;
            }
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        a = matrix;
        n = a.size();
        m = a[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        dfs(0, 0, 0);
        return ans;
    }
};