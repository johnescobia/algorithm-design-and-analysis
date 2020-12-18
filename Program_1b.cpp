#include <iostream>
#include <fstream>
#include <chrono> 
#include "HashMap.cpp"
#include "SearchData.cpp"

// A function that inserts data to the hash table using linear probing
void insert(std::string fileName, HashMap<std::string> &h)
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
		h.insertNode(line, fileName); 
		auto end = std::chrono::system_clock::now();
		duration = end - start;
		totalDuration += duration.count();
	}
		
	myFile.close();
	
	//~ h.display();
	std::cout << "Insertion time: " << totalDuration << "s\n";
}

void search(std::string fileName, HashMap<std::string> h)
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
		h.find(target, fileName);
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
		h.find(target, fileName);
		auto end = std::chrono::system_clock::now();
		unsearchableDuration = end - start;
		totalUnsearchableTime += unsearchableDuration.count();
	}
	
	// Display
	std::cout << "Average search time for searchable data: " << totalSeachableTime/10 << "s\n";
	std::cout << "Average search time for unsearchable data: " << totalUnsearchableTime/10 << "s\n";
}

//Driver method to test map class 
int main() 
{ 
	int option = 0, n = 0, emails = 0;
	std::string fileName = "";
	
	std::cout << "SELECT DATASET\n"
			  << "[1] SET A\n"
			  << "[2] SET B\n"
			  << "[3] SET C\n\n"
			  << "Enter 1, 2 or 3 to proceed. Other keys will exit the program.\n"
			  << ">> ";
	
	std::cin >> option;
	
	if(option == 1)
	{
		n = 151;
		emails = 150;
		fileName = "SET_A.txt";
	}
	else if(option == 2)
	{
		n = 150001;
		emails = 150000;
		fileName = "SET_B.txt";
	}
	else if(option == 3)
	{
		n = 758099;
		emails = 500000;
		fileName = "SET_C.txt";
	}
	else
		return 0;
    
    HashMap<std::string> h(n);
    
    std::cout << "\nSUMMARY\n"
			  << "Dataset: " << fileName << '\n'
			  << "Total data: " << emails << " emails\n"
			  << "Array size: " << n << '\n';
    
    // Insert data to the hash table using linear probing
    insert(fileName, h);
    
    // Search data in the hash table
    search(fileName, h);
	
    return 0; 
} 
