/*
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Return the index of the celebrity, if there is no celebrity return -1.
Note: Follow 0 based indexing.
Follow Up: Can you optimize it to O(N)
*/
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        vector<int> knows(n+1,0);
        vector<int> known(n+1,0);
        for(int i=0;i<M.size();i++){
            for(int j=0;j<M[0].size();j++){
                if(M[i][j]!=0) known[j]++;
                if(M[i][j]!=0) knows[i]++;
            }
        }
        int ans = -1;
         for(int i=0;i<M.size();i++){
            if(knows[i] == 0 && known[i] == M.size()-1)
                ans = i;
        }

        return ans;
    }
};
