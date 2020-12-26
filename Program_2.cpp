#include <vector>
#include <algorithm>
#include "Variables.cpp"
#include "BinarySearchTree.cpp"

TNode* insert(std::string fileName, std::vector< std::string > &emails)
{
	readFile.open(fileName, std::ios::in);
		
	while(true)
	{			
		getline(readFile, line);
		
		if(readFile.eof())
			break;
		
		emails.push_back(line);
	}
	
	readFile.close();
	
	auto start = std::chrono::system_clock::now();
	// Sort emails in ascending order
	sort(emails.begin(), emails.end());

    // Convert vector to BST
    TNode *root = sortedArrayToBST(emails, 0, emails.size()-1);   
    auto end = std::chrono::system_clock::now();
    duration = end - start;
    
    return root;
}

void search(std::string fileName, TNode *root)
{	
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
}

int main()
{	
	// Get number of emails to generate
	menu(n, fileName, "2", option);

	if(n == 0)
		return 0;
		
	std::vector< std::string > emails;
	
	// Insert data to AVL tree
	TNode *root = insert(fileName, emails);
	
	// Search data in AVL tree
    search(fileName, root);
	
	// Exit message
	std::cout << "\nAVL TREE SUMMARY\n"
			  << "Dataset: " << fileName << '\n'
			  << "Total data: " << n << " emails\n"
			  << "Insertion time: " << duration.count() << "s\n"
			  << "Average search time for searchable data: "
			  << totalSeachableTime/10 << "s\n"
			  << "Average search time for unsearchable data: "
			  << totalUnsearchableTime/10 << "s\n";

    delete root;

	return 0;
}
