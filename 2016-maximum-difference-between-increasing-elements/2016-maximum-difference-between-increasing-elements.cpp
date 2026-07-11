class Solution {
public:
    int maximumDifference(vector<int>& nums) {

        int ans = -1;
        int minelem = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] > minelem) {
                ans = max(ans, nums[i] - minelem);
            } else {
                minelem = nums[i];
            }

        }

        return ans;
    }
};