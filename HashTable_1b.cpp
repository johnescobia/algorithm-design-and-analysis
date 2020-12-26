//template for generic type 
template<typename K> 
  
// Hashnode class 
class HashNode 
{ 
	public: 
		K key;
      
		//Constructor of hashnode  
		HashNode(K key) 
		{ 
			this->key = key; 
		} 
}; 
  
// Template for generic type 
template<typename K> 

// Hashmap class 
class HashTable
{ 
    // Hash element array 
    HashNode<K> **arr; 

    //current size 
    int size; 
  
    public: 
		HashTable(int n) 
		{ 
			//Initial capacity of hash array 
			size = n; 
			arr = new HashNode<K>*[size]; 
			  
			//Initialise all elements of array as NULL 
			for(int i=0 ; i < size ; i++) 
				arr[i] = NULL; 
			  
		} 
		
		// Hash function to find index
		int hashFunction(K key, std::string fileName) 
		{ 
			int num = 0, n = 1;
	
			if(fileName == "SET_B.txt" || fileName == "SET_C.txt")
				n = 987654;
			
			// Hash code
			for(char x: key)
					num += abs(int(x))*n;
					
			return num % size; 
		} 
		  
		//Function to add key value pair 
		void insertNode(K key, std::string fileName) 
		{ 
			HashNode<K> *temp = new HashNode<K>(key); 
			  
			// Apply hash function to find index for given key 
			int hashIndex = hashFunction(key, fileName); 
			  
			// Find the next free space  
			while(arr[hashIndex] != NULL) 
			{ 
				hashIndex++; 
				if(hashIndex > 	size-1)
					hashIndex = 0;
			} 

			arr[hashIndex] = temp; 
		}
		
		// Return true if found
		bool find(K key, std::string fileName) 
		{ 			  
			// Apply hash function to find index for given key 
			int hashIndex = hashFunction(key, fileName); 
			  
			// Find the next free space  
			while(arr[hashIndex] != NULL) 
			{  
				if(hashIndex > 	size-1)
						hashIndex = 0;
						
				if(arr[hashIndex]->key == key)
					return true;
				
				hashIndex++;
			}
			
			return false;
		}
		  
		// Return current size  
		int sizeofMap() 
		{ 
			return size; 
		} 
		  
		// Return true if size is 0 
		bool isEmpty() 
		{ 
			return size == 0; 
		} 
		  
		// Function to display the stored keys 
		void display() 
		{ 
			for(int i=0 ; i<size ; i++) 
			{ 
				if(arr[i] != NULL && arr[i]->key != "")
				{
					std::cout << "Index: " << i << " "
							  << "key = " << arr[i]->key << std::endl;
				}
			} 
		} 
};
