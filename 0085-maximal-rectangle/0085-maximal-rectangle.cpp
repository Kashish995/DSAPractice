class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size(),  n = matrix[0].size();
        vector<int> h(n + 1, 0);
        int best=0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
            h[j] = (matrix[i][j] == '1') ? h[j] + 1 : 0;

            stack<int> st;
            for(int j = 0; j <= n; j++) {
                while(!st.empty() && h[st.top()] >= h[j]) {
                    int height = h[st.top()];
                    st.pop();
                    int left = st.empty() ? -1 : st.top();
                    best = max(best, height * (j - left - 1));

                }
                st.push(j);

            }
        }
        return best;
    }
};