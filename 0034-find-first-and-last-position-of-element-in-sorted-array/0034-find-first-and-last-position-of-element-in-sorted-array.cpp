class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;

        int n = nums.size() - 1;
        int left = 0;
        int right = n;

        int first = -1;
        int last = -1;

        // First Occurrence
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                first = mid;
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        // Reset for second binary search
        left = 0;
        right = n;

        // Last Occurrence
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                last = mid;
                left = mid + 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        ans.push_back(first);
        ans.push_back(last);

        return ans;
    }
};