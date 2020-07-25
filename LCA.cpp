void test(Node* root, vector <int> &v)
{
    if(root->left != NULL)
    {
        test(root->left, v);
    }
    v.push_back(root->data);
    if(root->right != NULL)
    {
        test(root->right, v);
    }
}
bool checkBST(Node* root) 
{
	vector <int> v;
    test(root, v);
    for(int i=1;i<v.size();i++)
    {
        if(v[i-1] >= v[i])
            return false;
    }
    return true;
}