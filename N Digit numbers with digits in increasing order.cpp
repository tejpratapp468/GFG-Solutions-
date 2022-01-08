class Solution
{
public:
    //TC O(n!) = (9!)
    //SC O(q) = total number in ans, Upperbound for q=n!
    vector<int> ans;
    void helper(int start,int curr,int n){
        if(n==0){
            ans.push_back(curr);
            return;
        }
        for(int i=start;i<=9;i++){
            int num=curr*10+i;
            helper(i+1,num,n-1);
        }
    }
    vector<int> increasingNumbers(int n)
    {
        int curr=0;
        if(n==1){
            for(int i=0;i<=9;i++) ans.push_back(i);
            return ans;
        }
        helper(1,curr,n);
        return ans;
        // Write Your Code here
    }
};
