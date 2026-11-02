class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size()) {
            return false;
        }

        int freq1[26] = {0};
        int freq2[26] = {0};

        // Step 1: Count frequency of s1
        for (char c : s1) {
            freq1[c - 'a']++;
        }

        int n = s1.size();

        // Step 2: Create first window
        for (int i = 0; i < n; i++) {
            freq2[s2[i] - 'a']++;
        }

        // Step 3: Compare first window
        if (equal(freq1, freq1 + 26, freq2)) {
            return true;
        }

        // Step 4: Slide the window
        for (int i = n; i < s2.size(); i++) {

            // Add new character
            freq2[s2[i] - 'a']++;

            // Remove old character
            freq2[s2[i - n] - 'a']--;

            // Compare frequencies
            if (equal(freq1, freq1 + 26, freq2)) {
                return true;
            }
        }

        return false;
    }
};