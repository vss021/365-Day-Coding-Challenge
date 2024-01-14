#include <iostream>
#include <vector>

using namespace std;

class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        // Your code here
        vector<int> ans;
        for(int i=1; i<M; i++){ 

            bool flag = true;

            for(int j=i-1; j>=0; j--){

            

                if(matrix[i][0] == matrix[j][0]){

                    flag = true;

                    for(int k=1; k<N; k++){

                        

                        if(matrix[i][k] != matrix[j][k]){

                            flag = false;

                            break;
                        }
                    }
                    if(flag == true ) break;
                }
                else flag = false;
            }
            if(flag == true ) ans.push_back(i);
        }

        return ans;
    } 
};


int main() {
    // Example matrix
    int M = 4; // Number of rows
    int N = 3; // Number of columns

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {1, 2, 3},
        {7, 8, 9}
    };

    // Creating an instance of the Solution class
    Solution solution;

    // Calling the repeatedRows function
    vector<int> result = solution.repeatedRows(matrix, M, N);

    // Displaying the result
    cout << "Rows with duplicates: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
