class Solution {
    struct Node {
        int next[26];
        int word = -1;                       // index of the word ending here, -1 if none
        Node() { fill(next, next + 26, -1); }
    };
    vector<Node> trie;
    vector<string> words;
    vector<string> found;

    void dfs(vector<vector<char>>& board, int r, int c, int node) {
        char ch = board[r][c];
        if (ch == '#') return;                           // already used on this path
        int nxt = trie[node].next[ch - 'a'];
        if (nxt == -1) return;                           // no word continues this way

        if (trie[nxt].word != -1) {
            found.push_back(words[trie[nxt].word]);
            trie[nxt].word = -1;                         // don't add the same word twice
        }

        board[r][c] = '#';                               // mark as used
        if (r > 0) dfs(board, r - 1, c, nxt);
        if (r + 1 < (int)board.size()) dfs(board, r + 1, c, nxt);
        if (c > 0) dfs(board, r, c - 1, nxt);
        if (c + 1 < (int)board[0].size()) dfs(board, r, c + 1, nxt);
        board[r][c] = ch;                                // undo
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& w) {
        words = w;
        trie.assign(1, Node());                          // node 0 is the root
        for (int i = 0; i < (int)words.size(); i++) {    // build the trie
            int cur = 0;
            for (char ch : words[i]) {
                int k = ch - 'a';
                if (trie[cur].next[k] == -1) {
                    trie[cur].next[k] = trie.size();
                    trie.push_back(Node());
                }
                cur = trie[cur].next[k];
            }
            trie[cur].word = i;
        }

        found.clear();
        for (int r = 0; r < (int)board.size(); r++)
            for (int c = 0; c < (int)board[0].size(); c++)
                dfs(board, r, c, 0);
        return found;
    }
};