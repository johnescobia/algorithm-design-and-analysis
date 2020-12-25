void menu(int &n, std::string &fileName)
{
	int option = 0;
	std::cout << "SELECT NUMBER OF EMAILS\n"
			  << "[1] 100\n"
			  << "[2] 100000\n"
			  << "[3] 500000\n\n"
			  << "Enter 1, 2 or 3 to proceed. Other keys will exit the program.\n"
			  << ">> ";
		
	std::cin >> option;

	if(option == 1)
	{
		n = 100;
		fileName = "SET_A.txt";
	}
	else if(option == 2)
	{
		n = 100000;
		fileName = "SET_B.txt";
	}
	else
	{
		n = 500000;
		fileName = "SET_C.txt";
	}
}


