class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        s.erase(beginWord);
        while(!q.empty()){
            pair<string,int> temp = q.front();
            q.pop();
            string word = temp.first;
            int step = temp.second;
            if(word==endWord) return step;
            for(int i=0;i<word.size();i++){
                int ch = word[i];
                for(char j= 'a';j<='z';j++){
                    word[i]=j;
                    if(s.find(word)!=s.end()){
                        s.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i]=ch;
            }
        }
        return 0;
    }
};