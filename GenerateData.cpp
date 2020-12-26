#include "Variables.cpp"

// A function that returns a random character from the passed string
char generate_random_char(std::string s, int x)
{
	return s[rand() % x];
}

int main()
{
	// Character array of alphabets	
	std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	// Character array of alphabets and numbers
	std::string alphaNum = alpha + "0123456789";

	// String array of dot domain names	
	std::string domain[] = {"com","net","org"};
	
	// Get number of emails to generate
	menu(n, fileName, "gd", option);
	
	if(n == 0)
		return 0;
	
	std::string email = "";
	int counter = n;
	srand(time(0));
	
	// Regular Expression: [A-Za-z0-9]{5}\.[A-Za-z0-9]{5}@[A-Za-z]{5}\.(com|net|org)
	while(counter--)
	{
		// Generate and append 10 random letters and numbers to email
		for(int i = 0; i < 10; i++)
		{
			if(i == 5) email += '.';
			email += generate_random_char(alphaNum, alphaNum.length()-1);
		}
		
		// Append character '@' to email
		email += '@';
		
		// Generate and append 5 random letters to email
		for(int i = 0; i < 5; i++)
			email += generate_random_char(alpha, alpha.length()-1);
		
		// Append '.' to email
		email += '.';
		
		// Append random domain to email
		email += domain[rand() % 3];
		
		// Append newline to email
		email += '\n';
	}
	
	// Create a text file fileName.txt and insert variable email into it
	writeFile.open(fileName);
	writeFile << email;
	writeFile.close();
	
	// Exit message
	std::cout << "\n" << n << " emails have been generated and inserted to "
	          << fileName;
	
	return 0;
}
