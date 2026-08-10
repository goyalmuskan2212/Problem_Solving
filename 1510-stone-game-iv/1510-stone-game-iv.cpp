class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<char> win(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int s = 1; s * s <= i; ++s) {
                if (!win[i - s * s]) {
                    win[i] = 1;
                    break;
                }
            }
        }
        return win[n];
    }
};