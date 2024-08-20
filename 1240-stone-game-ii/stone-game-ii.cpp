class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> mem(n, vector<int>(n, -1));
        vector<int> suffix(n); 
        suffix[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) suffix[i] = suffix[i + 1] + piles[i];
        return stoneGameII(suffix, 0, 1, mem);
    }
private:
int stoneGameII(vector<int>& suffix, int i, int M, vector<vector<int>>& mem) {
        if (i + 2 * M >= suffix.size()) return suffix[i];
        if (mem[i][M] != -1) return mem[i][M];
        int opponent = suffix[i];
        for (int X = 1; X <= 2 * M; ++X)
            opponent = min(opponent, stoneGameII(suffix, i + X, max(M, X), mem));
        return mem[i][M] = suffix[i] - opponent;
    }
};