class Solution {
public:
    int minOperations(string s) {
        int flip1=0;
        int flip2=0;
        for(int i=0;i<s.size();i++){
            char expected1 = (i % 2 == 0) ? '0' : '1';
            char expected2 = (i % 2 == 0) ? '1' : '0';
             if(s[i]!=expected1)
             flip1++;
              if(s[i]!=expected2)
              flip2++;
        }
        
        return min(flip1,flip2);
    }
};