#include <iostream>
#include <fstream>

int main()
{
	std::string inputInformation;
	std::fstream fileName;
	std::string userSelection;
	int configFileFound = 0;
	fileName.open("Welcome.txt", std::fstream::in);
	if(fileName.is_open())
	{
		std::cin >> inputInformation;
	}
	if(configFileFound == 0) //If default file is found display this message.
	{
		std::cout << "Welcome.\n";
		std::cout << "This information is in your file:\n";
		while(getline(fileName, inputInformation))
		{
			std::cout << inputInformation << '\n';
		}
		fileName.close();
		std::cout << "Done!\n";
		std::cout << "Select your choice:\n";

		std::cout << "r = run, t = test, o = options\n";
		std::cin >> userSelection;
		while(userSelection != "r" && userSelection != "t" && userSelection != "o")
		{
			std::cout << "Error, Invalid Selection, please try again!\n";
			std::cin >> userSelection;
				
		}

	}
	else
	{
		std::cout << "Welcome, this program uses a default welcome file location: '/home/usr/welcome.txt' please either set it up with your welcome message and try again or set up it up here and save it.\n";
		std::cout << "i = Ignore, q = Quit\n";
		std::cin >> userSelection;
		while(userSelection != "i" && userSelection != "q")
		{
			std::cout << "Error, Invalid Selection, please try again!\n";
			std::cin >> userSelection;	
		}
		if(userSelection == "q")
		{
			return 0;
		}
				
	}
	fileName.close();
	return 0;
}
