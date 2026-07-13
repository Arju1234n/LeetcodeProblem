class Solution {
public:
    string sortSentence(string s) {

        vector<string> words(10);
        string temp = "";

        for (int i = 0; i <= s.size(); i++) {

            if (i == s.size() || s[i] == ' ') {

                int pos = temp.back() - '0';   // Last character is position
                temp.pop_back();               // Remove the digit

                words[pos] = temp;
                temp = "";
            }
            else {
                temp += s[i];
            }
        }

        string ans = "";

        for (int i = 1; i < 10; i++) {
            if (words[i] != "") {

                if (!ans.empty())
                    ans += " ";

                ans += words[i];
            }
        }

        return ans;
    }
};