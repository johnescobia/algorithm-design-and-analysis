//template for generic type 
template<typename K> 
  
//Hashnode class 
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
class HashMap 
{ 
    // Hash element array 
    HashNode<K> **arr; 

    //current size 
    int size; 
    //dummy node 
    //~ HashNode<K> *dummy; 
  
    public: 
		HashMap(int n) 
		{ 
			//Initial capacity of hash array 
			size = n; 
			arr = new HashNode<K>*[size]; 
			  
			//Initialise all elements of array as NULL 
			for(int i=0 ; i < size ; i++) 
				arr[i] = NULL; 
			  
			//~ // Dummy node with value and key -1 and ""
			//~ dummy = new HashNode<K>(-1, ""); 
		} 
		
		// Hash function to find index
		int hashFunction(K key, std::string fileName) 
		{ 
			int num = 0, n = 1;
	
			if(fileName == "SET_B.txt" || fileName == "SET_C.txt")
				n = 987654;
			
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
		  
		//Function to search the value for a given key 
		//~ V get(int key) 
		//~ { 
			//~ // Apply hash function to find index for given key 
			//~ int hashIndex = hashCode(key); 
			//~ int counter=0; 
			//~ //finding the node with given key    
			//~ while(arr[hashIndex] != NULL) 
			//~ {
				//~ counter = 0; 
				
				//~ if(counter++>capacity)  //to avoid infinite loop 
					//~ return 0;         
				
				//~ //if node found return its value 
				//~ if(arr[hashIndex]->key == key) 
					//~ return arr[hashIndex]->value; 
				//~ hashIndex++; 
				//~ hashIndex %= capacity; 
			//~ } 
			  
			//~ //If not found return null 
			//~ return 0; 
		//~ }
		  
		//Return current size  
		int sizeofMap() 
		{ 
			return size; 
		} 
		  
		//Return true if size is 0 
		bool isEmpty() 
		{ 
			return size == 0; 
		} 
		  
		//Function to display the stored key value pairs 
		void display() 
		{ 
			int cc = 0;
			for(int i=0 ; i<size ; i++) 
			{ 
				if(arr[i] != NULL && arr[i]->key != "")
				{
					std::cout << "Item: " << ++cc << " "
						 << "Index: " << i << " ";
					std::cout << "key = " << arr[i]->key << std::endl;
				}
			} 
		} 
};
