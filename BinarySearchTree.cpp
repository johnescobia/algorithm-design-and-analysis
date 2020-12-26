// Binary tree node
class TNode  
{  
    public: 
    std::string data;  
    TNode* left;  
    TNode* right;  
};  
  
TNode* newNode(std::string data);  
  
// A function that constructs Balanced Binary Search Tree from a sorted vector of strings
TNode* sortedArrayToBST(std::vector<std::string> &arr, int start, int end)  
{  
    // Base Case
    if (start > end)  
		return NULL;  
  
    // Get the middle element and make it root
    int mid = (start + end)/2;  
    TNode *root = newNode(arr[mid]);  
  
    // Recursively construct the left subtree and make it left child of root
    root->left = sortedArrayToBST(arr, start, mid - 1);  
  
    // Recursively construct the right subtree and make it right child of root
    root->right = sortedArrayToBST(arr, mid + 1, end);  
  
    return root;  
}  
  
// Helper function that allocates a new node with the given data and NULL left and right pointers.
TNode* newNode(std::string data)  
{  
    TNode* node = new TNode(); 
    node->data = data;  
    node->left = NULL;  
    node->right = NULL;  
  
    return node;  
}  

bool search(TNode* node, std::string key) 
{
	if(node == NULL)
		return false;
		
    if(node->data == key)         // Key is present at root
		return true;
	
    if(node->data < key)          // Key is greater than or equal to root's key 
		search(node->right, key); 
    else
		search(node->left, key);  // Key is smaller than root's key 
    
    return false;
}
