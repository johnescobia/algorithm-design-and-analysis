#include <iostream>
#include <fstream>
#include <chrono>
#include "HashTable.cpp"
#include "SearchData.cpp"

// A function that inserts data to the hash table
void insert_to_ht(std::string fileName, HashTable<std::string> &ht)
{
	std::fstream myFile;
	myFile.open(fileName, std::ios::in);
	std::chrono::duration<double> duration;
	double totalDuration = 0;
	std::string line = "";		

	while(1)
	{			
		getline(myFile, line);
		
		if(myFile.eof())
			break;
			
		auto start = std::chrono::system_clock::now();
		ht.insert(line);
		auto end = std::chrono::system_clock::now();
		duration = end - start;
		totalDuration += duration.count();
	}
		
	myFile.close();
	
	// Display
	// std::cout << ht << '\n';
	std::cout << "Insertion time: " << totalDuration << "s\n";
}

// A function that searches data in the hash table
void search_in_ht(HashTable<std::string> &ht, std::string fileName)
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
		ht.retrieve(target);
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
		ht.retrieve(target);
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
	int option = 0, n = 0;
	std::string fileName = "";
	
	std::cout << "SELECT A DATASET\n"
			  << "[1] SET A\n"
			  << "[2] SET B\n"
			  << "[3] SET C\n\n"
			  << "Enter 1, 2 or 3 to proceed. Other keys will exit the program.\n"
			  << ">> ";
	
	std::cin >> option;
	
	if(option == 1)
	{
		n = 100;
		fileName = "SET_A.txt";
	}
	else if(option == 2)
	{
		n = 100000;
		fileName = "SET_B.txt";
	}
	else if(option == 3)
	{
		n = 500000;
		fileName = "SET_C.txt";
	}
	else
		return 0;
		
	HashTable<std::string> ht(n*0.9);
	
	std::cout << "\nSUMMARY\n"
			  << "Dataset: " << fileName << '\n'
			  << "Total data: " << n << " emails\n";
	
	// Insert data to the hash table
	insert_to_ht(fileName, ht);
	
	// Search data in the hash table
	search_in_ht(ht, fileName);
	
	return 0;
}
