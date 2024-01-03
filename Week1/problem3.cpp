#include <iostream>
#include <vector>
using namespace std;

void printPermutation(int num_, int value1_) {
    if (value1_ == 0) {
        for (int x = 1; x <= num_; x++) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    if (num_ - value1_ <= 1) {
        cout << "-1" << endl;
        return;
    }

    int a = num_ - 1 - value1_;
    value1_ = num_ + 1 - a;

    cout << value1_ << " ";

    int cnt = 1;

    for (int x = 1; x < num_; x++) {
        if (x == value1_) {
            cnt += 1;
        }
        cout << cnt << " ";
        cnt += 1;
    }

    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int num_, value1_;
        cin >> num_ >> value1_;

        printPermutation(num_, value1_);
    }

    return 0;
}
