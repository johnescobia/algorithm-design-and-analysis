#include <vector>
#include "LinkedList.cpp"

template <typename T>
class HashTable
{
	std::vector< LinkedList<T> > table;
	
	int hashfunction (std::string hashitem)
	{
		int num = 0;
		
		for(char x: hashitem)
			num += int(x);
		
		return num % table.size();
	}
 
	public:
		HashTable (int size)
		{
			table.resize (size); // resize vector to support size elements.
		}
		
		~HashTable()
		{
			for(size_t i = 0; i < table.size(); i++)
				table[i].makeEmpty();
		}
		
		int size()
		{
			return table.size();
		}
	  
		void insert (T newItem)
		{
			int location = hashfunction(newItem); // calculate where to store the number
			table[location].insertFront(newItem);
		}
	  
		bool retrieve (T & target)
		{
			int location = hashfunction(target);
			if(!table[location].find(target))     // if target is not found
				return false;
			
			return true;
		}
	  
		friend std::ostream& operator<< (std::ostream& os, HashTable<T>& ht)
		{
			for (int i = 0; i < ht.size(); i++)
				os << i << " = " << ht.table[i] << '\n';
			
			return os;
		}
};

