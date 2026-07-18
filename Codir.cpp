#include "codirHeader.h"

int main(int argc, char* argv[])
{
	int code = 0;
	std::string fileRoute = "/home/hunish/Desktop/coding/CustomCommands/codir/";

	int lineOfConfig = 0;

	std::string logRoute;

	switch(argv[1][0])
	{
	case '1':
		logRoute = fileRoute + "logSplash";
		lineOfConfig = 2;
		break;
	case '2':
		logRoute = fileRoute + "logCompile";
		lineOfConfig = 3;
		break;
	case '3':
		logRoute = fileRoute + "logFail";
		lineOfConfig = 4;
		break;
	}

	/*
	if(argc > 1 && std::string(argv[1]) == "1")
	{
		logRoute = fileRoute + "logSplash";
		lineOfConfig = 2;
	}else
	{
		logRoute = fileRoute + "logCompile";
		lineOfConfig = 3;
	}
	*/

	//std::string logRoute = fileRoute + "logFile";

	std::string phrasesRoute = configLoader(fileRoute, lineOfConfig);

	std::ifstream phrasesFile(phrasesRoute);
	if(!phrasesFile.is_open())
	{
		std::cerr << "There's no phrase file!\n";
		code += 1;
	}

	int phraseNumber = selectedPhraseNumber(phrasesFile, logRoute);
	/*
	if(argc > 1 && std::string(argv[1]) == "2")
	{
		zilchFace(&code, fileRoute);
	}
	*/

	phrasesFile.clear();
	phrasesFile.seekg(0);

	phraseToShow(phraseNumber, phrasesFile, argv[1][0]);

	std::string cmd =
    	"play /home/hunish/Desktop/coding/CustomCommands/codir/textToPhrases/audioSplash/" +
    	std::to_string(phraseNumber) +
    	".ogg >/dev/null 2>&1 </dev/null &";

	system(cmd.c_str());

	return code;
}

std::string configLoader(std::string route, int index)
{
	std::string configF = route + "config";
	std::ifstream fileC(configF);

	if(!fileC.is_open())
	{
		std::cout << RED << "There's no config file\n"
				  << RESET << "One was created.\n";
		std::ofstream newFile(configF);
		newFile << "# Use line 2 for the file name of the list.\n";
				//<< " And line 3 for the file name of the ascii art.\n";
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

