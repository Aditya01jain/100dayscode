

class Solution {
public:
   vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {

        vector<string> ans; 
        ans.push_back(words[0]); // Start with the first word
        int lastGroup = groups[0]; // Track the last group encountered
        for (int i = 1; i < words.size(); i++) {
            if (groups[i] != lastGroup) { // Check if the current group is different from the last group
                ans.push_back(words[i]); // Add the word to the result
                lastGroup = groups[i]; // Update the last group
            }
        }

        return ans; 
    }
};