#include "codirHeader.h"

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

int selectedPhraseNumber(std::ifstream& phr, std::string& route)	//	<==== From here we call the log
{
	phr.clear();
	phr.seekg(0);

	int totalLines = numberOfLines(phr);
	float f = (totalLines / 100.0) * 15;
	int forbidden = f;
	int valid = 0;
	int pickedNumber = 0;

	//std::cout << f << '\n';
	//std::cout << forbidden << '\n';

	std::random_device roll;
	std::uniform_int_distribution<> asMuchAsLines(1, totalLines);

	do
	{
		pickedNumber = asMuchAsLines(roll);
		valid = logCheck(route, pickedNumber, forbidden);

	}while(valid == 1); 

	return pickedNumber;
}

int logCheck(std::string route, int match, int percent)
{
	std::string logFile = route + "logFile";
	std::ifstream openedLog(logFile);

	if(!openedLog.is_open())
	{
		std::ofstream newFile(logFile);
		newFile << match;
		newFile.close();
		return 0;
	}

	std::vector<std::string> numbers;
	std::string line;

	while(std::getline(openedLog, line))
	{
		if(match == std::stoi(line))
		{
			return 1;
		}
		numbers.push_back(line);
	}

	openedLog.close();

	if(numbers.size() >= percent)
	{
		for(int i = 0; i < numbers.size() - 1; i ++)
		{
			numbers[i] = numbers[i + 1];
		}
		numbers[percent - 1] = std::to_string(match);
	}else
	{
		numbers.push_back(std::to_string(match));
	}

	std::ofstream writeLog(logFile);

	for(const auto& ln : numbers)
	{
		writeLog << ln << '\n';
	}

	openedLog.close();

	return 0;
}