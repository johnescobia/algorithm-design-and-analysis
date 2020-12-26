void menu(int &n, std::string &fileName, std::string program, int &option)
{
	if(program == "gd") // GenerateData.cpp
	{
		std::cout << "SELECT NUMBER OF EMAILS\n"
				  << "[1] 100\n"
				  << "[2] 100000\n"
				  << "[3] 500000\n\n";
	}
	else // Program_1a.cpp || Program_1b.cpp || Program_2.cpp || Program_3.cpp
	{
		std::cout << "SELECT DATASET\n"
				  << "[1] SET A\n"
				  << "[2] SET B\n"
				  << "[3] SET C\n\n";
	}
	
	std::cout << "Enter 1, 2 or 3 to proceed."
			  << "Other keys will exit the program.\n"
			  << ">> ";

	std::cin >> option;

	if(option == 1)
	{
		if(program == "1b")
			n = 151;
		else
			n = 100;
		
		fileName = "SET_A.txt";
	}
	else if(option == 2)
	{
		if(program == "1b")
			n = 150001;
		else
			n = 100000;
		
		fileName = "SET_B.txt";
	}
	else if(option == 3)
	{
		if(program == "1b")
			n = 758099;
		else
			n = 500000;
		
		fileName = "SET_C.txt";
	}
	else
		return;
}


