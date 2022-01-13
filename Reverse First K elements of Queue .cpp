Time Complexity: O(n)
Space Cmplexity: O(k)
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    int n=q.size();
    stack<int> s;
    int d=k;
    while(d--){
        int f=q.front();q.pop();
        s.push(f);
    }
    while(s.size()>0){
        int top=s.top(); s.pop();
        q.push(top);
    }
    for(int i=1;i<=n-k;i++){
        int f=q.front();q.pop();
        q.push(f);
    }
    return q;
}
