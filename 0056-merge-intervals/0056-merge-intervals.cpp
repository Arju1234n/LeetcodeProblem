class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();

        vector<vector<int>> ans;

        // Sort first
        sort(intervals.begin(), intervals.end());

        ans.push_back(intervals[0]);

        for(int i = 1; i < n; i++) {

            // Overlap
            if(ans.back()[1] >= intervals[i][0]) {

                ans.back()[1] =
                    max(ans.back()[1], intervals[i][1]);
            }

            // No overlap
            else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};