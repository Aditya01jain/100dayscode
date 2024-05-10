
class Solution {
public:
    bool isValid(std::string word) {
        // Define sets for vowels and consonants
        std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        std::unordered_set<char> consonants;

        // Initialize consonants set with all English letters excluding vowels
        for (char c = 'a'; c <= 'z'; ++c) {
            if (vowels.count(c) == 0) {
                consonants.insert(c);
                consonants.insert(toupper(c)); // Also add uppercase consonants
            }
        }

        // Initialize flags for vowel and consonant presence
        bool hasVowel = false;
        bool hasConsonant = false;

        // Iterate through the characters of the word
        for (char c : word) {
            if (!isalnum(c)) // Check if the character is alphanumeric
                return false; // If not, return false

            if (vowels.count(tolower(c))) {
                hasVowel = true;
            } else if (consonants.count(tolower(c))) {
                hasConsonant = true;
            }
        }

        // Check if the word satisfies all conditions
        return word.length() >= 3 && hasVowel && hasConsonant;
    }
};