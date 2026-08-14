class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxLength = 0;
        int start = 0;
        vector<int> charCount(26, 0);

        for (int i = 0; i < s.size(); i++) {
            charCount[s[i] - 'a']++;

            while (charCount[s[i] - 'a'] > 2) {
                charCount[s[start] - 'a']--;
                start++;
            }

            maxLength = max(maxLength, i - start + 1);
        }

        return maxLength;
    }
};