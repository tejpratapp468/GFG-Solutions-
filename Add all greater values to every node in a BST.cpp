//Time Complexity O(n) n=number of nodes in bst
//Space Complexity O(h) , h=heightoftree, best case(balanced bst) h=logn, worst case(skewed bst)h=n
int greaterSum=0;
void helper(Node* root){
    if(root==NULL) return;
    helper(root->right);
    root->data+=greaterSum; //root->data=root->data+greaterSum
    greaterSum=root->data;
    helper(root->left);
}
// modify the BST and return its root
Node* modify(Node *root)
{
    // Your code here
    //int greaterSum=0;
    helper(root);
    return root;
}
