//Time Complexity O(n) n=number of nodes in bst
//Space Complexity O(h) , h=heightoftree, best case(balanced bst) h=logn, worst case(skewed bst)h=n

//method 1: passing address of greaterSum address in helper function

void helper(Node* root, int& greaterSum){
    if(root==NULL) return;
    helper(root->right,greaterSum);
    root->data+=greaterSum;
    greaterSum=root->data;
    helper(root->left,greaterSum);
}
// modify the BST and return its root
Node* modify(Node *root)
{
    // Your code here
    int greaterSum=0;
    helper(root,greaterSum);
    return root;
}



//method 2: taking greaterSumas global variable
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
    greaterSum=0;
    helper(root);
    return root;
}
