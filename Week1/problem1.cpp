#include <iostream>
using namespace std;

int main() {
    
    int t;
    cin >> t;

    while (t--) {
        
        int num_, value1_, value2_;

        cin >> num_ >> value1_ >> value2_;

        // Calculate the number of leaves eaten per day

        int leavesPerDay = value2_ / 3;

        // Calculate remaining apples after accounting for leaves
        int x_left, leaves1_;

        if (value1_ >= leavesPerDay) {
            x_left = value1_ - leavesPerDay;
            leaves1_ = leavesPerDay;
        } else {
            x_left = 0;
            leaves1_ = value1_;
        }

        // Calculate additional leaves eaten per day
        int leaves2_ = x_left / 2;

        // Check if the total leaves eaten is sufficient to cover all leaves
        if (leaves2_ + leaves1_ >= num_) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
