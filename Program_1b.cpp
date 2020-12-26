#include "Variables.cpp" 
#include "HashTable_1b.cpp"

// A function that inserts data to the hash table using linear probing
void insert(std::string fileName, HashTable<std::string> &h)
{
	readFile.open(fileName, std::ios::in);

	while(true)
	{			
		getline(readFile, line);
		
		if(readFile.eof())
			break;
		
		auto start = std::chrono::system_clock::now();
		h.insertNode(line, fileName); 
		auto end = std::chrono::system_clock::now();
		duration = end - start;
		totalDuration += duration.count();
	}
		
	readFile.close();
}

void search(std::string fileName, HashTable<std::string> h)
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
}

int main() 
{ 
	int emails = 0;
	
	menu(n, fileName, "1b", option);
	
	if(option == 1)
		emails = 150;
	else if(option == 2)
		emails = 150000;
	else if(option == 3)
		emails = 500000;
	else
		return 0;
    
    HashTable<std::string> h(n);
    
    // Insert data to the hash table using linear probing
    insert(fileName, h);
    
    // Search data in the hash table
    search(fileName, h);
    
    // Exit message
    std::cout << "\nLINEAR PROBING METHOD SUMMARY\n"
			  << "Dataset: " << fileName << '\n'
			  << "Total data: " << emails << " emails\n"
			  << "Array size: " << n << '\n'
			  << "Insertion time: " << totalDuration << "s\n"
			  << "Average search time for searchable data: "
			  << totalSeachableTime/10 << "s\n"
			  << "Average search time for unsearchable data: "
			  << totalUnsearchableTime/10 << "s\n";   
			  
	// Uncomment the code below to display the hashtable
	// h.display();
	
    return 0; 
} 
