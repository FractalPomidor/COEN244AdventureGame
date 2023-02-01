#include <iostream>
#include <fstream>
#include "Level.h"
#include "Item.h"
#include "Game.h"

using namespace std;


// for now this is only a main which calls Level and 
// allows player to move around the displayed map
// items and other functions will be implemented later

int main()
{
  
  Level level1;
  level1.readMapFromFile("level1.txt");
  level1.displayMap();
  char direction;
  
  while(true)
  {
    cout<<"\nEnter the following to move (w, a, s, d): ";
    cin>> direction;
    level1.movePlayer(direction);
    level1.displayMap();
  }
  return 0;
}
