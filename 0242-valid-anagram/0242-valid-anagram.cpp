class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size()) {
            return false;
        }

        int freq[26] = {0};

        // Count characters of s
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Remove characters of t
        for (char c : t) {
            freq[c - 'a']--;
        }

        // Check all frequencies
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                return false;
            }
        }

        return true;
    }
};