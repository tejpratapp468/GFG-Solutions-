
class Solution{
  public:
  //Time Complexity O(n) ,n=number of elements in array
  //Space Complexity O(n)
    //Function to return list containing all the pairs having both
    //negative and positive values of a number in the array.
    vector <int> findPairs(int arr[], int n) 
    {
        // code here
        vector<int> ans;
        unordered_map<int,int> avail;
        for(int i=0;i<n;i++) {
            int val=arr[i];
            if(avail.count(-val)>0){
                int x=abs(val);
              ans.push_back(-x); ans.push_back(x);
            }
            else avail[val]++;
        }
      
        return ans;
    }
};
