class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;

        for(int i = 0; i < s.size(); i++) {

            int curr = value(s[i]);

            if(i + 1 < s.size() && curr < value(s[i + 1])) {
                ans -= curr;
            }
            else {
                ans += curr;
            }
        }

        return ans;
    }

    int value(char ch) {

        if(ch == 'I') return 1;
        if(ch == 'V') return 5;
        if(ch == 'X') return 10;
        if(ch == 'L') return 50;
        if(ch == 'C') return 100;
        if(ch == 'D') return 500;
        return 1000;
    }
};