class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int closest = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while(left < right) {

                int total = nums[i] + nums[left] + nums[right];

                // Update closest sum
                if(abs(target - total) < abs(target - closest)) {
                    closest = total;
                }

                if(total < target) {
                    left++;
                }
                else if(total > target) {
                    right--;
                }
                else {
                    return total;
                }
            }
        }

        return closest;
    }
};