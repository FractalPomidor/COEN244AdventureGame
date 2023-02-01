#pragma once
#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#inlcude <map>

using namespace std;

const int MAX_ROW = 100; // sets the max row/ col to 100 but the code checks for empty spaces from txt file
const int MAX_COL = 100; // and removes the empty spaces

class Level
{
  private:
	char gameMap[MAX_ROW][MAX_COL];
	int ROW, COL;
	int playerRow, playerCol;
  public:
	Level();
	Level(const string &fileName);

  	void readMapFromFile(const string &fileName);
	void displayMap();
	void movePlayer(char direction);

};

