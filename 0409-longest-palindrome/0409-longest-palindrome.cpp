class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char, int> mp;

        // Count frequency
        for(char c : s){
            mp[c]++;
        }

        int length = 0;
        bool odd = false;

        for(auto it : mp){

            int freq = it.second;

            if(freq % 2 == 0){
                length += freq;
            }
            else{
                length += freq - 1;
                odd = true;
            }
        }

        // One odd character can be in center
        if(odd){
            length++;
        }

        return length;
    }
};