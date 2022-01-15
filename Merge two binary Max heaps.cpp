//method 1

class Solution{
    public:
    //TC O((n+m)*log(n+m))
    //SC O(n+m)
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
       vector<int> ans(n+m);
       int k=0;
       for(int x:a) ans[k++]=x;
       for(int x:b) ans[k++]=x;
       sort(ans.rbegin(),ans.rend());
       return ans;
    }
};

//method 2 standard merging
class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        int i=0,j=0;
        vector<int> ans(n+m);
        int k=0;
        while(i<n && j<m){
            if(a[i]>b[j]) {
                ans[k]=a[i]; i++;
            }
            else{
                ans[k]=b[j];j++;
            }
            k++;
        }
        
        while(i<n) { //if i<n
            ans[k]=a[i]; i++,k++;
        }
        while(j<m){
            ans[k]=b[j]; j++,k++;
        }
      
        return ans;
    }
};
