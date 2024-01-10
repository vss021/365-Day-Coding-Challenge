class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq_map;

        for (int num : nums1) {
            freq_map[num]++;
        }
        for (int num : nums2) {
            freq_map[num]++;
        }
        vector<int> count_V;

        for (auto& [num, count] : freq_map) {
            count_V.push_back(count);
        }

        sort(count_V.rbegin(), count_V.rend());

        int size_ = nums1.size();

        int mid_of_Vector = size_ / 2;

        int result_ = 0;
        
        for (int count : count_V) {
            if (mid_of_Vector >= count) {
                mid_of_Vector -= count;
                result_ += count;
            } else {
                result_ += mid_of_Vector;
                break;
            }
        }
        return result_;
    }
};
