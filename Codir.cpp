#include "codirHeader.h"

int main(int argc, char* argv[])
{
	int code = 0;
	std::string rootRoute = "/home/hunish/Desktop/coding/CustomCommands/codir/";
	std::string logRoute = rootRoute + "logFile";

	std::string phrasesRoute = configLoader(rootRoute, 2);

	std::ifstream phrases(phrasesRoute);
	if(!phrases.is_open())
	{
		std::cerr << "There's no phrase file!\n";
		code += 1;
	}

	int phraseNumber = selectedPhraseNumber(phrases, logRoute);
	if(argc > 1 && std::string(argv[1]) == "2")
	{
			zilchFace(&code, rootRoute);
	}

	phrases.clear();
	phrases.seekg(0);

	phraseToShow(phraseNumber, phrases);

	return code;
}

std::string configLoader(std::string route, int index)
{
	std::string configF = route + "config";
	std::ifstream fileC(configF);

	if(!fileC.is_open())
	{
		std::cout << RED << "There's no config file!\n"
				  << RESET << "One was created.\n";
		std::ofstream newFile(configF);
		newFile << "# Use line 2 for the file name of the list."
				<< " And line 3 for the file name of the ascii art.\n";
		newFile.close();
	}

	fileC.clear();
	fileC.seekg(0);

	std::string fileName;
	int lineNumber = 1;

	while(std::getline(fileC, fileName))
    {
        if(index == lineNumber)
        {
        	fileName = route + fileName;
        	break;
        }
        lineNumber ++;
    }

	return fileName;
}

