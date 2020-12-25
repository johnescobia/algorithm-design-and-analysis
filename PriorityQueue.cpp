#include <vector>

template <typename T>
void printArray (T A[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << A[i] << " ";
    std::cout << std::endl;
}

template <typename T>
class PriorityQueue
{
	std::vector<T> A;

	void heapify_enqueue (int index)
	{     // used in enqueue.
		if (index == 0)                    // if already at root.
			return;
    
		// parent index
		int parent_index = (index-1)/2;
		
		// swap if parent is smaller
		if(A[index] > A[parent_index])
			std::swap(A[index], A[parent_index]);

		// recursion of the function
		heapify_enqueue(parent_index);
	}
    
	void heapify_dequeue (int index)
	{   	  // used in dequeue.
		int max=0;                            // max index
		// left child index
		int left = 2*index+1;
		
		// right child index
		int right = 2*index+2;

		// compare and find the greatest child
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
	void enqueue (T element)
	{
		A.push_back (element);
		heapify_enqueue (A.size()-1);  // start at last element.
	}
  
	T dequeue()
	{
		T removed_element = A[0];
		A[0] = A[A.size()-1];          // copy last element to root.
		A.pop_back();                  // remove last element.
		heapify_dequeue (0);           // start at root.
		
		return removed_element;
	}
  
	int size()
	{
		return A.size();
	}

	void print()
	{
		for (size_t i = 0; i < A.size(); i++)
			std::cout << A[i] << " ";
		std::cout << std::endl;
	}  
};
