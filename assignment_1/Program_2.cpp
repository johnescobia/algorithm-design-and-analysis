#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <algorithm>
#include "Menu.cpp"
#include "SearchData.cpp"
#include "BinarySearchTree.cpp"

// A function that inserts data to the AVL tree and returns root
TNode* insert ( std::vector< std::string > &emails,
				std::string fileName,
				std::chrono::duration<double> time, 
				double &insertTime )
{
	std::fstream readFile;
	readFile.open(fileName, std::ios::in);
	
	// Email from fileName.txt to be inserted
	std::string email = "";
		
	while(true)
	{			
		getline(readFile, email);
		if(readFile.eof()) break;
		emails.push_back(email);
	}
	
	readFile.close();
	
	auto start = std::chrono::system_clock::now();
	// Sort emails in ascending order
	sort(emails.begin(), emails.end());
    // Convert vector to BST
    TNode *root = sortedArrayToBST(emails, 0, emails.size()-1);   
    auto end = std::chrono::system_clock::now();
    time = end - start;
    insertTime += time.count();
    
    return root;
}

// A subroutine that searches data in the AVL tree and records the time taken
void search ( TNode *root,
			  std::string fileName,
			  std::chrono::duration<double> time, 
			  double &searchableTime,
			  double &unsearchableTime )
{	
	// Email to be searched
	std::string email = "";
	
	// Returned true is email is found
	bool check;
	
	// Record duration for searching data
	for(int i = 0; i < 20; i++)
	{
		if(fileName == "SET_A.txt")
			email = search_set_a[i];
		else if(fileName == "SET_B.txt")
			email = search_set_b[i];
		else
			email = search_set_c[i];
		
		auto start = std::chrono::system_clock::now();
		searchBST(root, email, check);
		auto end = std::chrono::system_clock::now();
		time = end - start;

		if(searchBST(root, email,check))
			searchableTime += time.count();
		else
			unsearchableTime += time.count();			
	}
}

// Driver function
int main()
{	
	// Array size
	int n = 0;

	// Option determines combination of emails and fileName
	int option = 0;

	// Text file name
	std::string fileName = "";
	
	// Difference between start and end time of a specific function
	std::chrono::duration<double> time;

	// Time taken to insert all emails to the hash table
	double insertTime = 0;

	// Time taken to search searchable 10 emails
	double searchableTime = 0;

	// Time taken to search unsearchable 10 emails
	double unsearchableTime = 0;
	
	// Show menu and get number of emails to generate
	menu(n, fileName, "2", option);

	if(n == 0) return 0;
		
	std::vector< std::string > emails;
	
	// Insert data to AVL tree
	TNode *root = insert(emails, fileName, time, insertTime);
	
	// Search data in AVL tree
    search(root, fileName, time, searchableTime, unsearchableTime);
	
	// Exit message
	std::cout << "\nAVL TREE SUMMARY\n"
			  << "Dataset: " << fileName << '\n'
			  << "Total data: " << n << " emails\n"
			  << "Insertion time: " << insertTime << "s\n"
			  << "Average search time for searchable data: "
			  << searchableTime/10 << "s\n"
			  << "Average search time for unsearchable data: "
			  << unsearchableTime/10 << "s\n";

    delete root;

	return 0;
}
