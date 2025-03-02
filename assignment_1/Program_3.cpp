#include <iostream>
#include <fstream>
#include <chrono>
#include "Menu.cpp"
#include "SearchData.cpp"
#include "PriorityQueue.cpp"

// A subroutine that inserts data to the priority queue
void enqueue ( PriorityQueue<std::string> &pq,
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
		pq.enqueue(email);
		auto end = std::chrono::system_clock::now();
		time = end - start;
		insertTime += time.count();
	}

	readFile.close();
}

// A subroutine that searches data in the priority queue
void search ( PriorityQueue<std::string> pq,
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
		pq.search(email);
		auto end = std::chrono::system_clock::now();
		time = end - start;
		
		if(pq.search(email))
			searchableTime += time.count();
		else
			unsearchableTime += time.count();
	}
}

// A subroutine that dequeues data from the priority queue
void dequeue ( PriorityQueue<std::string> &pq,
			   int size,
			   std::chrono::duration<double> time,
			   double &dequeueTime )
{
	for(int i = 0; i < size*0.1; i++)
	{    
		auto start = std::chrono::system_clock::now();
		pq.dequeue();
		auto end = std::chrono::system_clock::now();
		time = end - start;
		dequeueTime += time.count();
	}
}

// Driver function
int main ()
{
	// Number of emails
	int n = 0;

	// Option determines combination of n and fileName
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
	
	// Time taken to dequeue 10 elements
	double dequeueTime = 0;
	
	// Show menu and get number of emails to generate
	menu(n, fileName, "3", option);

	if(n == 0) return 0;
	
	// Priority queue
	PriorityQueue< std::string > pq;
	
	// Enqueue data to priority queue
	enqueue(pq, fileName, time, insertTime);
	
	// Search data in priority queue
	search(pq, fileName, time, searchableTime, unsearchableTime);

	// Dequeue data from priority queue
	dequeue(pq, pq.size(), time, dequeueTime);

	// Exit message
	std::cout << "\nPRIORITY QUEUE SUMMARY\n"
			  << "Dataset: " << fileName << '\n'
			  << "Total data: " << n << " emails\n"
			  << "Enqueue time: " << insertTime << "s\n"
			  << "Dequeue time: " << dequeueTime<< "s\n"
			  << "Average search time for searchable data: "
			  << searchableTime/10 << "s\n"
			  << "Average search time for unsearchable data: "
			  << unsearchableTime/10 << "s\n";

	return 0;
}

