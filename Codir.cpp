#include <iostream>
#include <random>
#include <fstream>
#include <iomanip>

#define DARKGRN "\e[38;5;34m"
#define RESET "\033[0m"
#define BLUE "\e[38;5;63m"
#define HEART "\e[38;5;197m"
#define MAGENTA "\e[38;5;207m"

int selectedPhraseNumber(std::ifstream *phr);
void zilchFace(int *output);
void phraseToShow(int v, std::ifstream& file);

int main(int argc, char* argv[])
{
	int code = 0;
	std::string phrasesRoute = "/home/hunish/Desktop/coding/CustomCommands/SysDepen/codir_splash_phrase.txt";
	std::ifstream phrases(phrasesRoute);
	if(!phrases.is_open())
	{
		std::cerr << "There's no " << phrasesRoute << " file!\n";
		code ++;
	}

	int phraseNumber = selectedPhraseNumber(&phrases);
	if(argc > 1 && std::string(argv[1]) == "2")
	{
			zilchFace(&code);
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

void zilchFace(int *output)
{
	std::string route = "/home/hunish/Desktop/coding/CustomCommands/SysDepen/codir_splash_5.txt";
	std::ifstream face(route);
	if(!face.is_open())
	{
		std::cerr << "There's no " << route << " file!\n";
		(*output) ++;
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

int numberOfLines(std::ifstream *phr)
{
    std::string line;
    int lineCount = 0;

    while(std::getline(*phr, line))
    {
        ++ lineCount;
    }

    return lineCount;
}

int selectedPhraseNumber(std::ifstream *phr)
{
	phr -> clear();
	phr -> seekg(0);

	int totalLines = numberOfLines(phr);

	std::random_device roll;
	std::uniform_int_distribution<> asMuchAsLines(1, totalLines);
	return asMuchAsLines(roll);
}