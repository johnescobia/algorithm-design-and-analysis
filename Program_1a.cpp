#include "Variables.cpp"
#include "HashTable_1a.cpp"

// A function that inserts data to the hash table using chaining
void insert(std::string fileName, HashTable<std::string> &ht)
{
	readFile.open(fileName, std::ios::in);
	
	while(true)
	{			
		getline(readFile, line);
		
		if(readFile.eof())
			break;
			
		auto start = std::chrono::system_clock::now();
		ht.insert(line);
		auto end = std::chrono::system_clock::now();
		duration = end - start;
		totalDuration += duration.count();
	}
		
	readFile.close();
}

// A function that searches data in the hash table
void search(HashTable<std::string> &ht, std::string fileName)
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
}

int main()
{	
	// Get number of emails to generate
	menu(n, fileName, "1a", option);

	if(n == 0)
		return 0;
		
	HashTable<std::string> ht(n*0.9);
	
	// Insert data to the hash table using chaining
	insert(fileName, ht);
	
	// Search data in the hash table
	search(ht, fileName);
	
	// Exit message
	std::cout << "\nCHAINING METHOD SUMMARY\n"
			  << "Dataset: " << fileName << '\n'
			  << "Total data: " << n << " emails\n"
			  << "Array size: " << n*0.9 << '\n'
			  << "Insertion time: " << totalDuration << "s\n"
			  << "Average search time for searchable data: "
			  << totalSeachableTime/10 << "s\n"
			  << "Average search time for unsearchable data: "
			  << totalUnsearchableTime/10 << "s\n";
	
	// Uncomment the code below to display the hashtable
	// std::cout << ht << '\n';
	
	return 0;
}
