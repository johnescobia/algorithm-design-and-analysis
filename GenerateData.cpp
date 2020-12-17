//~ [A-Za-z0-9]{5}\.[A-Za-z0-9]{5}@[A-Za-z]{5}\.(com|net|org)

#include <iostream>
#include <fstream>

//~ Uncomment to generate unsearchable datasets
//~ static const char alphaNum[] = "!#$%^&*()_+=-~`{}:,./";				   
//~ static const char alpha[] = "0123456789";						
//~ static const std::string domain[] = {"tech","io","dev"};

// Character array of alphabets and numbers
static const char alphaNum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
							   "abcdefghijklmnop"
							   "0123456789";

// Character array of alphabets	
static const char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
							"abcdefghijklmnop";

// String array of dot domain names	
static const std::string domain[] = {"com","net","org"};

// A function that returns an element from the passed character array
// at random index
char generate_random_char(const char arr[], int x)
{
	return arr[rand() % x];
}

int main()
{
	int n = 500000;                     // 100, 100000, 500000
	std::string fileName = "SET_C.txt"; // SET_A.txt, SET_B.txt, SET_C.txt 
	
	int alphaNumSize = sizeof(alphaNum)-1;
	int alphaSize = sizeof(alpha)-1;
	
	std::string email = "";
	srand(time(0));
	
	while(n--)
	{
		for(int i = 0; i < 10; i++)
		{
			if(i == 5) email += '.';
			email += generate_random_char(alphaNum, alphaNumSize);
		}
	
		email += '@';
			
		for(int i = 0; i < 5; i++)
		{
			email += generate_random_char(alpha, alphaSize);
		}
		
		email += '.';
		email += domain[rand() % 3];
		email += '\n';
	}
	
	// Create a text file "fileName". And then insert variable email
	// into text file fileName.
	std::ofstream myFile;
	myFile.open (fileName);
	myFile << email;
	myFile.close();
	
	return 0;
}
