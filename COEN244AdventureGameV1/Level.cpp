#include "pch.h"
#include "Level.h"
#include <string>
#include <fstream>
#include <cstring>
#include <iostream>

/*

We take an inputfilestream to a text file that represents our level in
ascii text. We build the level by determining the longest line so we can 
allocate a simple character array. We then read through again, filling in
the dynamically allocated character array.

*/
Level::Level() {
	
	ROW = COL = playerRow = playerCol = 0;
	memset(gameMap, 0, sizeof(gameMap)); // memset definition: sets the first num bytes of the block of memory 
					     // pointed by ptr to the specified value (interpreted as an unsigned char)
	}
void Level::readMapFromFile(const string &fileName)
{
	ifstream file(fileName);
	if (!file.is_open())
	{
		cout<<"Error opening file"<< endl;
		return;
	}
	int row = 0;
	string line;
	while (getline(file, line))
	{
		if (line.empty())
			continue;
		int col = 0;
		for (int i = 0; i< line.length(); i++)
		{
			if(line[i[ == " ")
				  continue;
			char c = line[i];
			gameMap[row][col++] = c;
			if (c == '@')
			{
				playerRow = row;
				playerCol = col-1;
			}
		}
				  
		ROW = row + 1;
		COL = max(COL, col);
		row++;
	}
	file.close();
}
void Level::displayMap()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << gameMap[i][j];
		}
		cout << endl;
	}
}

void Level::movePlayer(char direction)
{
	int newRow = playerRow, newCol = playerCol;
	switch (direction)
	{
	case 'w':
		newRow--;
		break;
	case 's':
		newRow++;
		break;
	case 'a':
		newCol--;
		break;
	case 'd':
		newCol++;
		break;
	default:
		cout << "Invalid move" << endl;
		return;
	}
	if (newRow < 0 || newRow >= ROW || newCol < 0 || newCol >= COL || gameMap[newRow][newCol] == '#')
	{
		cout << "Invalid move" << endl;
		return;
	}
	if (gameMap[newRow][newCol] == '<')
	{
		cout << "Loading next map..." << endl;
		string nextMap = "level2.txt"; // Sets the next file to read from
		memset(gameMap, 0, sizeof(gameMap));
		readMapFromFile(nextMap);
		playerRow = playerCol = 0;
		displayMap();
		return;
	}
	gameMap[playerRow][playerCol] = '.';
	playerRow = newRow;
	playerCol = newCol;
	gameMap[playerRow][playerCol] = '@';
}
				  {
