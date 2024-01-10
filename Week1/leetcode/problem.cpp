#include <vector>
#include <algorithm>

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_area_ = 0;
        double max_diagonal_ = 0;

        for (auto& el : dimensions) {

            double diagonal_ = sqrt(el[0] * el[0] + el[1] * el[1]);
            if (diagonal_ > max_diagonal_) {
                max_diagonal_ = diagonal_;
                max_area_ = el[0] * el[1];
            } else if (diagonal_ == max_diagonal_) {
                max_area_ = max(max_area_, el[0] * el[1]);
            }
        }
        return max_area_;
    }
};
