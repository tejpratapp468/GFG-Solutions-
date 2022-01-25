class Solution {
  public:
  //TC O(n*log(r-l)
  //SC O(1)
    int leastWeightCapacity(int a[], int n, int d) {
        // code here
        int sum=0,mx=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            mx=max(mx,a[i]);
        }
        int l=mx ,r=sum;
        int ans=sum;
        while(l<=r){
            int mid=(l+r)/2;
            int daysTaken=1,curr=0;
            for(int i=0;i<n;i++){
                if(curr+a[i]>mid){
                    daysTaken++;
                    curr=a[i];
                }
                else curr+=a[i];
            }
            if(daysTaken>d){
                l=mid+1;
            }
            else {
                ans=mid;r=mid-1;
            }
        }
        return ans;
    }
};
