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

int selectedPhraseNumber(std::ifstream &phr, std::string& route);
void zilchFace(int *output, std::string rootRoute);
void phraseToShow(int v, std::ifstream& file);
std::string configLoader(std::string route, int index);
int logCheck(std::string route, int match, int percent);