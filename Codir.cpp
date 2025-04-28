#include <iostream>
#include <random>
#include <fstream>
#include <iomanip>

#define DARKGRN "\e[38;5;34m"
#define RESET "\033[0m"
#define BLUE "\e[38;5;63m"
#define HEART "\e[38;5;197m"
#define MAGENTA "\e[38;5;207m"
#define RED "\e[38;5;196m"

int selectedPhraseNumber(std::ifstream &phr);
void zilchFace(int *output, std::string rootRoute);
void phraseToShow(int v, std::ifstream& file);
std::string configLoader(std::string route, int index);

int main(int argc, char* argv[])
{
	int code = 0;
	std::string rootRoute = "/home/hunish/Desktop/coding/CustomCommands/codir/";

	std::string phrasesRoute = configLoader(rootRoute, 2);

	std::ifstream phrases(phrasesRoute);
	if(!phrases.is_open())
	{
		std::cerr << "There's no phrase file!\n";
		code += 1;
	}

	int phraseNumber = selectedPhraseNumber(phrases);
	if(argc > 1 && std::string(argv[1]) == "2")
	{
			zilchFace(&code, rootRoute);
	}

	phrases.clear();
	phrases.seekg(0);

	phraseToShow(phraseNumber, phrases);

	return code;
}

void phraseToShow(int v, std::ifstream& file)
{
	std::cout << "\n\n" << BLUE << std::setw(22) << " " 
			  << "Welcome to your coding directory Hunish! n.n " << HEART
			  << "~ ♥\n\n";

	std::string lineToShow;
	int currentLine = 1;

	while(std::getline(file, lineToShow))
	{
		if(currentLine == v)
		{
			std::cout << std::setw(10) << " " << MAGENTA << lineToShow
					  << "  💖\n\n";
			break;
		}
		currentLine ++;
	}
}

void zilchFace(int *output, std::string rootRoute)
{
	std::string route = configLoader(rootRoute, 3);
	std::ifstream face(route);
	if(!face.is_open())
	{
		std::cerr << "There's no splash file!\n";
		(*output) += (1 << 1);
	}else
	{
		std::cout << DARKGRN;
		std::string line;
		while(std::getline(face, line))
		{
			std::cout << line << std::endl;
		}
		std::cout << RESET;
	}
}

int numberOfLines(std::ifstream& phr)
{
    std::string line;
    int lineCount = 0;

    while(std::getline(phr, line))
    {
        ++ lineCount;
    }

    return lineCount;
}

int selectedPhraseNumber(std::ifstream& phr)
{
	phr.clear();
	phr.seekg(0);

	int totalLines = numberOfLines(phr);

	std::random_device roll;
	std::uniform_int_distribution<> asMuchAsLines(1, totalLines);
	return asMuchAsLines(roll);
}

std::string configLoader(std::string route, int index)
{
	std::string configF = route + "config";
	std::ifstream fileC(configF);

	if(!fileC.is_open())
	{
		std::cout << RED << "There's no config file!\n"
				  << RESET << "One was created.\n";
		std::ofstream newFile("config");
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