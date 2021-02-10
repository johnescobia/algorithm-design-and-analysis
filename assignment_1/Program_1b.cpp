#include <iostream>
#include <fstream>
#include <chrono>
#include "Menu.cpp"
#include "SearchData.cpp"
#include "HashTable_1b.cpp"

// A subroutine that inserts data to the hash table using linear probing
void insert ( HashTable<std::string> &ht,
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
		
		auto start = std::chrono::system_clock::now();
		ht.insertNode(email, fileName); 
		auto end = std::chrono::system_clock::now();
		time = end - start;
		insertTime += time.count();
	}
		
	readFile.close();
}

// A subroutine that searches data in the hash table and records the time taken
void search ( HashTable<std::string> ht,
			  std::string fileName,
			  std::chrono::duration<double> time, 
			  double &searchableTime,
			  double &unsearchableTime )
{	
	// Email to be searched
	std::string email = "";
	
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
		ht.find(email, fileName);
		auto end = std::chrono::system_clock::now();
		time = end - start;
		
		if(ht.find(email, fileName))
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
	
	// Number of emails
	int emails = 0;
	
	// Difference between start and end time of a specific function
	std::chrono::duration<double> time;

	// Time taken to insert all emails to the hash table
	double insertTime = 0;

	// Time taken to search searchable 10 emails
	double searchableTime = 0;

	// Time taken to search unsearchable 10 emails
	double unsearchableTime = 0;
	
	// Show menu and get number of emails to generate
	menu(n, fileName, "1b", option);
	
	// Assign number of emails separately because it is unequal to n 
	if(option == 1)
		emails = 100;
	else if(option == 2)
		emails = 100000;
	else if(option == 3)
		emails = 500000;
	else
		return 0;
    
    // Hash table
    HashTable<std::string> ht(n);
    
    // Insert data to the hash table using linear probing
    insert(ht, fileName, time, insertTime);
    
    // Search data in the hash table
    search(ht, fileName, time, searchableTime, unsearchableTime);
    
    // Exit message
    std::cout << "\nLINEAR PROBING METHOD SUMMARY\n"
			  << "Dataset: " << fileName << '\n'
			  << "Total data: " << emails << " emails\n"
			  << "Array size: " << n << '\n'
			  << "Insertion time: " << insertTime << "s\n"
			  << "Average search time for searchable data: "
			  << searchableTime/10 << "s\n"
			  << "Average search time for unsearchable data: "
			  << unsearchableTime/10 << "s\n";   
			  
	// Uncomment the code below to display the hashtable
	// h.display();
	
    return 0; 
} 
