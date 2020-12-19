#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <algorithm>
#include "SearchData.cpp"

/* A Binary Tree node */
class TNode  
{  
    public: 
    std::string data;  
    TNode* left;  
    TNode* right;  
};  
  
TNode* newNode(std::string data);  
  
/* A function that constructs Balanced Binary Search Tree from a sorted vector of strings */
TNode* sortedArrayToBST(std::vector<std::string> &arr, int start, int end)  
{  
    /* Base Case */
    if (start > end)  
		return NULL;  
  
    /* Get the middle element and make it root */
    int mid = (start + end)/2;  
    TNode *root = newNode(arr[mid]);  
  
    /* Recursively construct the left subtree and make it left child of root */
    root->left = sortedArrayToBST(arr, start, mid - 1);  
  
    /* Recursively construct the right subtree and make it right child of root */
    root->right = sortedArrayToBST(arr, mid + 1, end);  
  
    return root;  
}  
  
/* Helper function that allocates a new node with the given data and NULL left and right pointers. */
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
		
    if(node->data == key)       // Key is present at root
		return true;
	
    if(node->data < key)   // Key is greater than root's key 
		search(node->right, key); 
    else
		search(node->left, key); // Key is smaller than root's key 
    
    return false;
}

void recordSearch(std::string fileName, TNode *root)
{
	std::chrono::duration<double> searchableDuration, unsearchableDuration;
	double totalSeachableTime, totalUnsearchableTime;
	std::string target = "";
	
	// Record duration for searching searchable data
	for(int i = 0; i < 10; i++)
	{
		if(fileName == "SET_A.txt")
			target = searchable_set_a[i];
		else if(fileName == "SET_B.txt")
			target = searchable_set_b[i];
		else
			target = searchable_set_c[i];
		
		auto start = std::chrono::system_clock::now();
		search(root, target);
		auto end = std::chrono::system_clock::now();
		searchableDuration = end - start;
		totalSeachableTime += searchableDuration.count();
	}
	
	// Record duration for searching unsearchable data
	for(int i = 0; i < 10; i++)
	{
		if(fileName == "SET_A.txt")
			target = unsearchable_set_a[i];
		else if(fileName == "SET_B.txt")
			target = unsearchable_set_b[i];
		else
			target = unsearchable_set_c[i];
		
		auto start = std::chrono::system_clock::now();	
		search(root, target);
		auto end = std::chrono::system_clock::now();
		unsearchableDuration = end - start;
		totalUnsearchableTime += unsearchableDuration.count();
	}
	
	// Display
	std::cout << "Average search time for searchable data: " << totalSeachableTime/10 << "s\n";
	std::cout << "Average search time for unsearchable data: " << totalUnsearchableTime/10 << "s\n";
}

int main()
{
	int option = 0;
	std::string fileName = "";
	
	std::cout << "SELECT DATASET\n"
			  << "[1] SET A\n"
			  << "[2] SET B\n"
			  << "[3] SET C\n\n"
			  << "Enter 1, 2 or 3 to proceed. Other keys will exit the program.\n"
			  << ">> ";
	
	std::cin >> option;
	
	if(option == 1)
		fileName = "SET_A.txt";
	else if(option == 2)
		fileName = "SET_B.txt";
	else if(option == 3)
		fileName = "SET_C.txt";
	else
		return 0;
	
	std::cout << "\nSUMMARY\n"
			  << "Dataset: " << fileName << '\n';
		
	std::vector< std::string > emails;
	
	std::fstream myFile;
	myFile.open(fileName, std::ios::in);
	std::string line = "";	
	
	std::chrono::duration<double> duration;
	auto start = std::chrono::system_clock::now();	
	while(1)
	{			
		getline(myFile, line);
		
		if(myFile.eof())
			break;
		
		emails.push_back(line);
	}
	
	myFile.close();
	
	sort(emails.begin(), emails.end());
    /* Convert vector to BST */
    TNode *root = sortedArrayToBST(emails, 0, emails.size()-1);   
    auto end = std::chrono::system_clock::now();
    duration = end - start;
    
    std::cout << "Insertion time: " << duration.count() << "s\n";
    
    recordSearch(fileName, root);

	return 0;
}
