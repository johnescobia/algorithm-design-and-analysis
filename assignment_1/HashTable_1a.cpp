#include <vector>
#include "LinkedList.cpp"

template < typename T >
class HashTable
{
	std::vector< LinkedList<T> > table;
	
	int hashFunction ( std::string hashitem )
	{
		int num = 0;
		
		// Hash code to convert letters to integers with ascii values
		for(char x: hashitem)
			num += int(x);
		
		return num % table.size();
	}
 
	public:
	    // Constructor
		HashTable ( int size )
		{
			// Resize vector to support size elements
			table.resize(size);
		}
		
		// Deconstructor
		~HashTable()
		{
			for(size_t i = 0; i < table.size(); i++)
				table[i].makeEmpty();
		}
		
		// A function that returns the size of the hash table
		int size()
		{
			return table.size();
		}
		
		// Subroutine that calculates where to store the number
		// and inserts element to hash table
		void insert ( T newItem )
		{
			int location = hashFunction(newItem);
			table[location].insertFront(newItem);
		}
		
		// A function that determines if element exists in the hash table 
		bool retrieve ( T & target )
		{
			int location = hashFunction(target);
			
			// Return false if target is not found
			if(!table[location].find(target)) return false;
			
			return true;
		}
		
		// Override operator<<
		friend std::ostream& operator<< ( std::ostream& os, HashTable<T>& ht )
		{
			for (int i = 0; i < ht.size(); i++)
				os << i << " = " << ht.table[i] << '\n';
			
			return os;
		}
};

