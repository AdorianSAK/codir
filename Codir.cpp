#include "codirHeader.h"

int main(int argc, char* argv[])
{
	int code = 0;
	std::string fileRoute = "/home/hunish/Desktop/coding/CustomCommands/codir/";

	int lineOfConfig = 0;

	std::string logRoute;

	std::string cmd = "";

	switch(argv[1][0])
	{
	case '1':
		logRoute = fileRoute + "logSplash";
		lineOfConfig = 2;
		cmd += "play /home/hunish/Desktop/coding/CustomCommands/codir/textToPhrases/audioSplash/";
		break;
	case '2':
		logRoute = fileRoute + "logCompile";
		lineOfConfig = 3;
		cmd += "play /home/hunish/Desktop/coding/CustomCommands/codir/textToPhrases/audioCompile/";
		break;
	case '3':
		logRoute = fileRoute + "logFail";
		lineOfConfig = 4;
		cmd += "play /home/hunish/Desktop/coding/CustomCommands/codir/textToPhrases/audioFail/";
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

	cmd +=
    	std::to_string(phraseNumber) +
    	".ogg pitch 260 tempo 1.12 treble 5 bass -5 reverb 8 vol 0.35 "
    	">/dev/null 2>&1 </dev/null &";

    //std::cout << cmd;

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

