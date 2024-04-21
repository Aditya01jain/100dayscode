class Solution {
 public:
string convert(std::string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) {
            return s;
        }
        int index = 0;
        string ans = "";
        vector<string> rows(numRows, "");
        bool down = false;
        for (char c : s) {
            rows[index] += c;
            if (index == 0 || index == numRows - 1) {
                down = !down;
            }
            index += down ? 1 : -1;
        }
        for (const auto &row : rows) {
            ans += row;
        }
        return ans;
    }
};
