class Solution {
public:
    bool isPalindrome(string s) {
        string clean = "";

        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s[i])) {
                clean += tolower(s[i]);
            }
        }

        int l = 0;
        int r = clean.size() - 1;

        while (l < r) {
            if (clean[l] != clean[r]) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};