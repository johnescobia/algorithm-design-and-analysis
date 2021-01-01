// Binary tree node
struct TNode  
{  
    std::string data;  
    TNode* left;  
    TNode* right;  
};  

// A function that allocates and returns a new node with the given data
TNode* newNode(std::string data)  
{  
    TNode* node = new TNode(); 
    node->data = data;  
    node->left = NULL;  
    node->right = NULL;  
  
    return node;  
}

// A function that constructs an AVL tree from a sorted vector of strings
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

// A function that searches element in the AVL tree
bool searchBST(TNode* node, std::string key, bool & check) 
{
	// Key is not found
	if(node == NULL) return check = false;
	
	// Key is found
    if(node->data == key) return check = true; 
	
    if(node->data < key)             // Key is greater than or equal to root's key
		searchBST(node->right, key, check);
    else
		searchBST(node->left, key, check);  // Key is smaller than root's key
		
	if(check) return true;
	else return false;
}
