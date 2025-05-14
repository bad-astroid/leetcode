class Solution {
public:
    int n, m, k;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    vector<vector<int>> grid;
    vector<vector<vector<int>>> level;
    struct node {
        int x;
        int y;
        int r;
        node(int _x, int _y, int _r) {
            x = _x;
            y = _y;
            r = _r;
        }
    };
    int bfs(int srcX, int srcY, int k) {
        queue<node> q;
        q.push(node(srcX, srcY, k));
        level[srcX][srcY][k] = 0;
        while(!q.empty()) {
            auto at = q.front();
            q.pop();

            if(at.x == n - 1 && at.y == m - 1) {
                return level[at.x][at.y][at.r];
            }

            for(int i = 0; i < 4; ++i) {
                int newX = at.x + dx[i];
                int newY = at.y + dy[i];

                if(newX < 0 || newX >= n) continue;
                if(newY < 0 || newY >= m) continue;

                if(grid[newX][newY] == 1) {
                    if(at.r > 0) {
                        // cout << at.x << ' ' << at.y << ' ' << at.r << endl;
                        if(level[newX][newY][at.r - 1] != -1) continue;
                        level[newX][newY][at.r - 1] = level[at.x][at.y][at.r] + 1;
                        q.push(node(newX, newY, at.r - 1));
                    }
    
                    continue;
                }

                if(level[newX][newY][at.r] != -1) continue;
                level[newX][newY][at.r] = level[at.x][at.y][at.r] + 1;
                q.push(node(newX, newY, at.r));
            }
        }

        return -1;
    }
    int shortestPath(vector<vector<int>>& _grid, int _k) {
        n = _grid.size();
        m = _grid[0].size();
        k = _k;
        grid = _grid;
        level.assign(n, vector<vector<int>> (m, vector<int> (k + 1, -1)));
        return bfs(0, 0, k);
    }
};