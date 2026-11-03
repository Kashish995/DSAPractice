class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;

        int best = 1;
        for(int i = 0; i < n; i++) {
            if(best >= n - i) break;

            map <pair<int, int>, int>  cnt;

            int local = 0;
            for(int j = i + 1; j <n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = __gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;

                if(dx < 0 || (dx == 0 && dy < 0)) {
                    dx = -dx;
                    dy = -dy;

                }
                local = max(local, ++cnt[{dx, dy}]);
            }
            best = max(best, local + 1);
        }
        return best;
    }
};