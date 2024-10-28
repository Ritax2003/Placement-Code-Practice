// User function template for C++
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_map<int,int>mp;
        for(auto x:arr){
            mp[x]++;
        }
        
        for(int i=0;i<arr.size();i++){
            if((mp.find(target-arr[i])!=mp.end()) and target-arr[i]!=arr[i]){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--) {
        int x;
        cin >> x;
        cin.ignore(); // To discard any leftover newline characters

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.twoSum(arr, x);
        cout << (ans ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
