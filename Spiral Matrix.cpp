/*
- Problem: Spiral Matrix
- Source: Leetcode
- Approach: Setting up 4 variables, each of which would define the boundary of a smaller matrix, and successovely shrinking their size
- Language: C++
- Time Complexity: O(K) {K is MxN where MxN is the order of the matrix} 
- Space Complexity: O(1) {and O(K) for printing the output}
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Initializing the boundaries of the matrix
        int top=0;
        int bottom=matrix.size()-1;
        int left=0;
        int right=matrix[0].size()-1;

        vector<int> res;

        while (top<=bottom && left<=right) { // This runs until the boundaries overlap with each other
            for (int i=left;i<=right; i++){ 
                res.push_back(matrix[top][i]);
            }

            top++; //We push the top boundary downwards to avoid repeating the same row again

            for (int i=top;i<=bottom; i++){
                res.push_back(matrix[i][right]);
            }

            right--; //We push the right boundary leftwards to avoid repeating the same column again

            if (top<=bottom) { //We run this, to check if the pushing of boundaries from the prior loop made the boundaries overlap or cross each other
                for (int i=right;i>=left; i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left<=right) {
                for (int i=bottom;i>=top; i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
    return res;
}

int main(){
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    vector<int> res=spiralOrder(matrix);

    cout<<"[";

    for (int i=0;i<res.size();i++){
        cout<<res[i];
        if (i!=res.size()-1){
            cout<<", ";
        }
    }

    cout<<"]";
    return 0;
}
