class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.length() == 1){
            return s;
        }

        int len = s.length();
        int mid = len / 2;

        sort(s.begin(), s.begin() + mid);

        for (int i = 0; i < mid; ++i) {
            s[len - 1 - i] = s[i];
        }

        return s;
    }
};