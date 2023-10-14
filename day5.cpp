#include <iostream>
#include <vector>
#include <string>

using namespace std;

int parseSquare(const string& square) {
    if (square == "Start") return 1;
    if (square == "End") return 100;
    if (square[0] == 'S') return -stoi(square.substr(2));
    if (square[0] == 'L') return stoi(square.substr(2));
    return stoi(square);
}

bool isValidPosition(int pos) {
    return pos >= 1 && pos <= 100;
}

pair<string, int> playGame(const vector<vector<int>>& board, const vector<int>& dieInputs) {
    int numSnakes = 0;
    int numLadders = 0;
    int position = 1;

    for (int die : dieInputs) {
        int newPosition = position + die;

        if (isValidPosition(newPosition)) {
            if (newPosition == 100) {
                return make_pair("Possible", numSnakes + 1);
            } else if (board[(newPosition - 1) / 10][(newPosition - 1) % 10] < 0) {
                numSnakes++;
            } else if (board[(newPosition - 1) / 10][(newPosition - 1) % 10] > 0) {
                numLadders++;
            }

            position = newPosition;
        } else {
            return make_pair("Not possible", numSnakes);
        }
    }

    return make_pair("Not possible", numSnakes);
}

int main() {
    vector<vector<int>> board(10, vector<int>(10));
    vector<int> dieInputs;

    cout << "Enter the Snake and Ladder board:" << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            string square;
            cin >> square;
            board[i][j] = parseSquare(square);
        }
    }

    cout << "Enter the die inputs (space-separated):" << endl;
    int die;
    while (cin >> die) {
        dieInputs.push_back(die);
    }

    pair<string, int> result = playGame(board, dieInputs);
    if (result.first == "Possible") {
        cout << "Possible " << result.second << endl;
    } else {
        cout << "Not possible " << result.second << endl;
    }

    return 0;
}
