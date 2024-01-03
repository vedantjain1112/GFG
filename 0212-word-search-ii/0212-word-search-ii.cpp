class TrieNode {
public:
    vector<TrieNode*> children;
    string word;

    TrieNode() : children(26), word("") {}
};

class Trie {
public:
    TrieNode* root;

    Trie() : root(new TrieNode()) {}

    void insert(string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children[ch - 'a']) {
                node->children[ch - 'a'] = new TrieNode();
            }
            node = node->children[ch - 'a'];
        }
        node->word = word;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (string& word : words) {
            trie.insert(word);
        }

        vector<string> result;
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                backtrack(board, i, j, trie.root, result);
            }
        }

        return result;
    }

    void backtrack(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        char ch = board[i][j];
        if (ch == '#' || !node->children[ch - 'a']) {
            return;
        }

        node = node->children[ch - 'a'];
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = "";  // Avoid duplicate results
        }

        board[i][j] = '#';  // Mark the cell as visited

        if (i > 0) backtrack(board, i - 1, j, node, result);
        if (i < board.size() - 1) backtrack(board, i + 1, j, node, result);
        if (j > 0) backtrack(board, i, j - 1, node, result);
        if (j < board[0].size() - 1) backtrack(board, i, j + 1, node, result);

        board[i][j] = ch;  // Reset the cell
    }
};