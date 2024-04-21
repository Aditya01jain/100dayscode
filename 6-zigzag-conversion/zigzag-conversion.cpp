class Solution {
 public:
 string convert(string s, int numRows) {
    if (numRows == 1 || numRows >= s.length()) {
        return s;
    }
    vector<string> rows(numRows, "");
    int index = 0;
    bool goingDown = false;
    for (char c : s) {
        rows[index] += c;
        if (index == 0 || index == numRows - 1) {
            goingDown = !goingDown;
        }
        index += goingDown ? 1 : -1;
    }
    string result;
    for (string row : rows) {
        result += row;
    }
    return result;
}
};
