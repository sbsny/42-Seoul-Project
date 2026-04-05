#include <iostream>
#include <fstream>
#include <string>

int	main(int argumentCount, char **argumentValues)
{
	if (argumentCount == 4)
	{
		std::string		inputFileName = argumentValues[1];
		std::string		searchText = argumentValues[2];
		std::string		replacementText = argumentValues[3];
		std::ifstream	inputFile(inputFileName.c_str());

		if (inputFile.is_open())
		{
			std::string		outputFileName = inputFileName + ".replace";
			std::ofstream	outputFile(outputFileName.c_str());
			std::string		currentLine;

			while (std::getline(inputFile, currentLine))
			{
				std::string::size_type	matchPosition = 0;

				while (searchText.length() && (matchPosition = currentLine.find(searchText,
							matchPosition)) != std::string::npos)
				{
					currentLine.erase(matchPosition, searchText.length());
					currentLine.insert(matchPosition, replacementText);
					matchPosition += replacementText.length();
				}
				outputFile << currentLine << std::endl;
			}
			inputFile.close();
			outputFile.close();
		}
		else
			std::cerr << "Error: File could not be opened" << std::endl;
	}
	else
		std::cerr << "Error: Wrong number of arguments" << std::endl;
	return 0;
}
