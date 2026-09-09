class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";

        reverse(s.begin(), s.end());

        string word = "";

        for (int i = 0; i < n; i++) {

            // spaces skip
            while (i < n && s[i] == ' ') {
                i++;
            }

            // word collect
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // word reverse
            reverse(word.begin(), word.end());

            if (word.length() > 0) {
                if (ans.length() > 0) {
                    ans += " ";
                }

                ans += word;
                word = ""; // IMPORTANT
            }
        }

        return ans;
    }
};