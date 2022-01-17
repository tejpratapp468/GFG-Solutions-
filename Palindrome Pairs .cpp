class Solution{   
  public:
  //Time Complexity O(N*L*L)
  //Space Complexity O(N)
    // Function to check if a palindrome pair exists
    bool palindromepair(int N, string arr[]) {
        unordered_map<string, int> dict;
         // build dictionary
         for(int i = 0; i < N; i++) {
             string key = arr[i];
             dict[key] = i;
         }
         // edge case: if empty string "" exists, find all palindromes to become pairs ("", self)
         if(dict.find("")!=dict.end()){
             for(int i = 0; i < N; i++){
                 if(i == dict[""]) continue;
                 if(isPalindrome(arr[i])) return 1; // 1) if self is palindrome, here ans covers concatenate("", self) 
             }
         }

         for(int i = 0; i < N; i++) {
             int l=arr[i].size();
             for(int j = 0; j < l; j++) {
                 string left = arr[i].substr(0, j);
                 string lr=left;reverse(lr.begin(),lr.end()); //left reverse
                 string right = arr[i].substr(j);
                 string rr=right;reverse(rr.begin(),rr.end()); //right reverse

                 if(dict.find(lr) != dict.end() && isPalindrome(right) && dict[lr] != i) {
                     return 1;   // 2) when j = 0, left = "", right = self, so here covers concatenate(self, "")
                 }

                 if(dict.find(rr) != dict.end() && isPalindrome(left) && dict[rr] != i) {
                     return 1;
                 }
             }
         }

         return 0;        
     }

     bool isPalindrome(string& str){
         int i = 0;
         int j = str.size() - 1; 

         while(i < j) {
             if(str[i++] != str[j--]) return false;
         }

         return true;
     }

};
