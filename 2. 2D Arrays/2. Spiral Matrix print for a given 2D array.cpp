/*
Given an m x n matrix, return all elements of the matrix in spiral order.
Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row = matrix.size();
        int col = matrix[0].size();
        
        int total = row*col;
        int count =0;
        int startrow =0;
        int startcol =0;
        int endrow = row-1;
        int endcol = col-1;
        
        while(count<total){
            
            for(int i=startcol;i<=endcol;i++){    //first row forward left to right  -->
                res.push_back(matrix[startrow][i]);
                count++;
            }
            startrow++;
            
            for(int j= startrow;j<=endrow;j++){ // last col forward up to down    |
                res.push_back(matrix[j][endcol]);//                               |
                count++;//                                                        v
            }
            endcol--;
            
            if(endrow>=startrow){
            for(int i=endcol;i>=startcol;i--){ // last row reverse right to left  <---
                res.push_back(matrix[endrow][i]);                
                count++;
            }
        }
            endrow--;
            
        if(startcol<=endcol){
            for(int j = endrow;j>=startrow;j--){ //first col reverse down to up     ^
                res.push_back(matrix[j][startcol]); //                              |
                count++;         //                                                 |
            }
            startcol++;
        }
            
        }
        return res;
    }
};
