class Solution
{
  public:
  //O(m+n) Linear time
  //SC O(H), H=height of tree in best case H=logn for balanced tree , in worst case H=N in skewed tree
    void preorder(Node* root,string& s)
    {
        if(!root)
        {
            s+='a';return;
        }
        s+=to_string(root->data);
        preorder(root->left,s);
        preorder(root->right,s);
    }

    void inorder(Node* root,string& s)
    {
        if(!root)
        {
            s+='a';return;
        }
        inorder(root->left,s);
        s+=to_string(root->data);
        inorder(root->right,s);
    }
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) 
    {
        // Your code here
        if(!S) return 1;
        if(!T) return 0;
        string in1="",in2="";
        inorder(T,in1);
        inorder(S,in2);
       // cout<<in1<<" "<<in2<<endl;
        if(in1.find(in2)==-1) return 0;
       
        string pre1="",pre2="";
        preorder(T,pre1);
        preorder(S,pre2);
       // cout<<pre1<<" "<<pre2<<endl;
        if(pre1.find(pre2)==-1) return 0;
        return 1;
    }
};
