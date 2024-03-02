#include <iostream>
#include <unordered_map>

using namespace std;

int firstElementKTime(int n, int k, int a[]) {
    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++) {
        mp[a[i]]++;

        if(mp[a[i]] == k)
            return a[i];
    }

    return -1;
}

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Enter k: ";
    cin >> k;
    int result = firstElementKTime(n, k, a);
    if(result != -1)
        cout << "The first element occurring " << k << " times is: " << result << endl;
    else
        cout << "No element occurs " << k << " times in the array." << endl;

    return 0;
}
