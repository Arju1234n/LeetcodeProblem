class Solution {
public:
    string addStrings(string num1, string num2) {

        int endFirst = num1.size() - 1;
        int endSecond = num2.size() - 1;

        int carry = 0;
        string ans = "";

        while (endFirst >= 0 || endSecond >= 0 || carry != 0) {

            int sum = carry;

            if (endFirst >= 0) {
                sum += num1[endFirst] - '0';
                endFirst--;
            }

            if (endSecond >= 0) {
                sum += num2[endSecond] - '0';
                endSecond--;
            }

            ans.push_back((sum % 10) + '0');

            carry = sum / 10;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};