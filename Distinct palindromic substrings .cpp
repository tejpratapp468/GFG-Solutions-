
class Solution{
  public:
  //Time Complexity O(n*(n+n))=O(n*n)
  //Space Complexity O(n*n)
    int palindromeSubStrs(string s) {
       int n=s.size();
       unordered_set<string> st;
	   for(int i=0;i<n;i++)
	   st.insert(s.substr(i,1));
	   int left,right;
       for(int i=0;i<n-1;i++)
       {
           left=i,right=i+1;
           while(left>=0 && right<n) //checking for even length palindrome
           {
               if(s[left]==s[right])
               {
                   st.insert(s.substr(left,right-left+1));
                   left--,right++;
               }
               else break;
           }
           left=i-1;right=i+1;
           while(left>=0 && right<n) //checking for odd length palindrome
           {
               if(s[left]==s[right])
               {
                   st.insert(s.substr(left,right-left+1));
                   left--,right++;
               }
               else break;
           }
       }
       int ans=st.size();
       return ans;
    }
};
