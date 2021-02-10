#include <vector>

template <typename T>
class PriorityQueue
{
	std::vector<T> A;
	
	// A subroutine that performs heapification on the priority queue
	// after enqueue
	void heapify_enqueue(int index)
	{
		if (index == 0)
			return;
    
		// Parent index
		int parent_index = (index-1)/2;
		
		// Swap if parent is smaller
		if(A[index] > A[parent_index])
			std::swap(A[index], A[parent_index]);

		// Perform recursion
		heapify_enqueue(parent_index);
	}
    
    // A subroutine that performs heapification on the priority queue
	// after dequeue
	void heapify_dequeue(int index)
	{
		// Max index
		int max=0;
		
		// Left child index
		int left = 2*index+1;
		
		// Right child index
		int right = 2*index+2;

		// Compare and find the greatest child
		int size = A.size();
		
		if(left < size && A[left] > A[max])
			max = left;
		else
			max = index;
		
		if(right < size && A[right] > A[max])
			max = right;

		if (max != index)
		{
			std::swap (A[index], A[max]);
			heapify_dequeue (max);
		}
	}
  
public:
	// A subroutine that enqueues elements to the priority queue 
	void enqueue(T element)
	{
		A.push_back(element);
		heapify_enqueue(A.size()-1);  // Start at last element
	}
	
	// A function that searches data in the priority queue
	// Returns 1 if element is found and returns 0 if not 
	bool search(T element)
	{	
		for(size_t i = 0; i < A.size(); i++)
			if(A[i] == element) return true;

		return false;
	}
	
	// A function that dequeues elements from the priority queue 
	T dequeue()
	{
		T removed_element = A[0];
		A[0] = A[A.size()-1];          // Copy last element to root
		A.pop_back();                  // Remove last element
		heapify_dequeue(0);            // Start at root
		
		return removed_element;
	}
	
	// A function that returns the size of the size of vector A
	int size()
	{
		return A.size();
	}
};
