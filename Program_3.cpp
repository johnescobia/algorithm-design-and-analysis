#include "Variables.cpp"
#include "PriorityQueue.cpp"

// A function that inserts data to the hash table using chaining
void enqueue(std::string fileName, PriorityQueue<std::string> &pq)
{
	readFile.open(fileName, std::ios::in);	

	while(true)
	{			
		getline(readFile, line);
		
		if(readFile.eof())
			break;
			
		auto start = std::chrono::system_clock::now();
		pq.enqueue (line);
		auto end = std::chrono::system_clock::now();
		duration = end - start;
		totalDuration += duration.count();
	}
		
	readFile.close();
	
	// Display
	//~ std::cout << ht << '\n';
}

void dequeue(int n, PriorityQueue<std::string> &pq)
{
	for (int i = 0; i < n*0.9; i++)
	{    
		auto start = std::chrono::system_clock::now();
		pq.dequeue();
		auto end = std::chrono::system_clock::now();
		duration = end - start;
		totalDuration += duration.count();
	}
}

int main ()
{		
	// Get number of emails to generate
	menu(n, fileName, "3", option);

	if(n == 0)
		return 0;
	
	PriorityQueue< std::string > pq;
	
	// Enqueue data to priority queue
	enqueue(fileName, pq);
	
	// Dequeue data from priority queue
	dequeue(n, pq);
	
	// Exit message
	std::cout << "\nPRIORITY QUEUE SUMMARY\n"
			  << "Dataset     : " << fileName << '\n'
			  << "Total data  : " << n << " emails\n"
			  << "Enqueue time: " << totalDuration << "s\n"
			  << "Dequeue time: " << totalDuration << "s\n";

	return 0;
}

