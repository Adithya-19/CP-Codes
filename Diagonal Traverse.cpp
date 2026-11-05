/*
- Problem: Diagonal Traverse
- Source: Leetcode
- Credit: Idea from daulat_309's solution
- Approach: We go through the elements, which if are in the same diagonal order, have the sum of their coordinates to have same modulus by 2.
- Language: C++
- Time Complexity: O(MxN) 
- Space Complexity: O(1) {and O(K) for printing the output}
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector <int> result(m*n);
        int row=0, col=0;

        for (int i=0;i<m*n;i++){
            result[i]=mat[row][col];
            if ((row+col)%2==0){ // Here we go in a Left-Up manner
                if (col==m-1){
                    row++;
                }
                else if (row==0){
                    col++;
                }
                else{
                    row--;
                    col++;
                }
            }

            else{ // Here we go in a Right-Down manner
                if (row==n-1){
                    col++;
                }
                else if (col==0){
                    row++;
                }
                else{
                    col--;
                    row++;
                }
            }
        }

        return result;
    }

int main(){
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res=findDiagonalOrder(matrix);

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
