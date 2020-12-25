#include <iostream>
#include <fstream>
#include <chrono>
#include "PriorityQueue.cpp"

// A function that inserts data to the hash table using chaining
void enqueue(std::string fileName, PriorityQueue<std::string> &pq)
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
		pq.enqueue (line);
		auto end = std::chrono::system_clock::now();
		duration = end - start;
		totalDuration += duration.count();
	}
		
	myFile.close();
	
	// Display
	//~ std::cout << ht << '\n';
	std::cout << "Enqueue time: " << totalDuration << "s\n";
}

void dequeue(int n, PriorityQueue<std::string> &pq)
{
	std::chrono::duration<double> duration;
	double totalDuration = 0;
	
	for (int i = 0; i < n*0.9; i++)
	{    
		auto start = std::chrono::system_clock::now();
		pq.dequeue();
		auto end = std::chrono::system_clock::now();
		duration = end - start;
		totalDuration += duration.count();
	}
	
	std::cout << "Dequeue time: " << totalDuration << "s\n";
}

int main ()
{	
	int option = 0, n = 0;
	std::string fileName = "";
	PriorityQueue<std::string> pq;
	
	std::cout << "SELECT DATASET\n"
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
		
	std::cout << "\nPRIORITY QUEUE SUMMARY\n\n"
			  << "Dataset     : " << fileName
			  << "\nTotal data  : " << n << " emails\n";
	
	enqueue(fileName, pq);
	dequeue(n, pq);
	
	return 0;
}

