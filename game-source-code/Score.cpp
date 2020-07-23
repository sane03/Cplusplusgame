#include "Score.h"
#include <iostream>
using namespace std;
Score::Score() : score{0}
{

}

int Score::readHighScore()
{
	ifstream infile;
	infile.open ("score.txt");
	infile >> HighScore;
	auto HighestScore=HighScore;
	infile.close();
	
return HighestScore; 	
}

