class Solution{
    public:
    //TC O(n*(n+n))=O(n*n)
    //SC O(1)
    void clonestack(stack<int> st, stack<int>& cloned)
    {
        //code here
        int n=st.size();
        int done=0;
        while(done!=n-1){
            int top=st.top();st.pop(); 
            
            while(st.size()>done){
                int curr=st.top();st.pop();
                cloned.push(curr);
            }
            st.push(top);
            while(cloned.size()>0){
                int curr=cloned.top();cloned.pop();
                st.push(curr);
            }
            done++;
        }
        while(st.size()>0){
            int top=st.top();st.pop();
            cloned.push(top);
        }
    }
};
