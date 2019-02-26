#include <iostream>
#include <fstream>
#include "Modes.h"
#include <string>

using namespace std;

Modes::Modes()//constructor
{
  //ask them to pick a mode
  while(true)
  {
    cout << "Would you like to (1) provide a map file or (2) use a random assignment? " << endl;
    string choice = "";
    cin >> choice;// takes user input and stores it in choice
    if(choice == "1")
    {
      provideMap();
      break;
    }
    else if(choice == "2")
    {
      randomMap();
      break;
    }
    else
    {
      cout << "Invalid input" << endl;
    }
  }
}
Modes::~Modes()//destructor
{

}
void Modes::randomMap()// not done
{
  cout << "What height would you like for the map?" << endl; // input the size of thr map and the population density of the cells
  while(true)
  {
    cin >> mapHeight;
    if(mapHeight > 0)
    {
      break;
    }
    else
    {
      cout << "Invalid height, try again" << endl;
    }
  }

  cout << "What width would you like for the map?" << endl;

  while(true)
  {
    cin >> mapWidth;
    if(mapWidth > 0)
    {
      break;
    }
    else
    {
      cout << "invalid width, try again" << endl;
    }
  }


  cout << "Enter a decimal number for the population dencity that is greater than 0 and less than 1" << endl;
  double popDensity = 0.0;
  cin >> popDensity;
  string mapA [mapHeight][mapWidth];
  string mapB [mapHeight][mapWidth];

  for(int i = 0; i < mapHeight; i++) // fills the map with
  {
    for(int j = 0; j < mapWidth; j++)
    {
      //chooses "X" or "~" based on probability
      double random = rand() % 1;
      if(random < popDensity)
      {
        mapA[i][j] = 'X';
      }
      else
      {
        mapA[i][j] = '~';
      }
    }
  }
}

void Modes::provideMap() //takes the file name as an input and sets mapA to the contents of the file.
{
  cout << "What is the name of the file?: ";
  string fileName = "";
  cin >> fileName;
  fstream inputMap(fileName);
  mapHeight = 0;
  mapWidth = 0;
  if(inputMap.is_open())
  {
    string line = "";
    while (getline(inputMap, line))
    {
      if(mapHeight == 0)
      {
        mapHeight = stoi(line);
      }
      else if(mapWidth == 0)
      {
        mapWidth = stoi(line);
        mapA [mapHeight][mapWidth];
        mapB [mapHeight][mapWidth];
      }
      else
      {
        for(int i = 0; i < mapHeight; i++)
        {
          for(int j = 0; j < line.length(); j++)
          {
            mapA[i][j] = line[j]; //writes the map to the array
          }
        }
      }
    }
  }
}
void Modes::Classic() // runs classic mode of Game of Life for 1 genoration
{
  for(int i = 0; i < mapHeight; i++)
  {
    for(int j = 0; j < mapWidth; j++)
    {
      //check for neighabors
      if(checkNeighborClassic(i,j) <= 1)
      {
        mapB[i][j] = '~';
      }
      else if(checkNeighborClassic(i,j) == 3)
      {
        mapB[i][j] = 'X';
      }
      else if(checkNeighborClassic(i,j) >= 4)
      {
        mapB[i][j] = '~';
      }
    }
  }

}

void Modes::Doughnut()
{
  for(int i = 0; i < mapHeight; i++)
  {
    for(int j = 0; j < mapWidth; j++)
    {
      //check for neighabors
      if(checkNeighborDoughnut(i,j) <= 1)
      {
        mapB[i][j] = '~';
      }
      else if(checkNeighborDoughnut(i,j) == 3)
      {
        mapB[i][j] = 'X';
      }
      else if(checkNeighborDoughnut(i,j) >= 4)
      {
        mapB[i][j] = '~';
      }
    }
  }
}

void Modes::Mirror()
{
  for(int i = 0; i < mapHeight; i++)
  {
    for(int j = 0; j < mapWidth; j++)
    {
      //check for neighabors
      if(checkNeighborMirror(i,j) <= 1)
      {
        mapB[i][j] = '~';
      }
      else if(checkNeighborMirror(i,j) == 3)
      {
        mapB[i][j] = 'X';
      }
      else if(checkNeighborMirror(i,j) >= 4)
      {
        mapB[i][j] = '~';
      }
    }
  }
}

int Modes::checkNeighborClassic(int cellHeight, int cellWidth) // 0-1 neighbor == empty, 2 == stable(stays the same), 3 == gain cell if empty and keep if not, 4+ == cell dies
{
  int numNeighbor = 0;// keeps track of the number of neighaboring cells
  if(cellHeight == 0)//check if the cell is at the top of the grid
  {
    if(cellWidth == 0)//check if the cell is at the top left corner
    {
      if(mapB[cellHeight + 1][cellWidth] == 'X')//cell below
      {
        numNeighbor++;
      }
      if(mapB[cellHeight + 1][cellWidth + 1] == 'X')//cell to the bottom right
      {
        numNeighbor++;
      }
      if(mapB[cellHeight][cellWidth + 1] == 'X')//cell to the right
      {
        numNeighbor++;
      }
    }
    else if(cellWidth == mapWidth - 1)//check if the cell is at the top right corner
    {
      if(mapB[cellHeight][cellWidth - 1] == 'X') //cell to the left
      {
        numNeighbor++;
      }
      if(mapB[cellHeight + 1][cellWidth - 1] == 'X')//cell to the bottom left
      {
        numNeighbor++;
      }
      if(mapB[cellHeight + 1][cellWidth] == 'X')//cell below
      {
        numNeighbor++;
      }
    }
    else //cell is along the top wall of the map but not in a corner
    {
      if(mapB[cellHeight][cellWidth - 1] == 'X') //cell to the left
      {
        numNeighbor++;
      }
      if(mapB[cellHeight + 1][cellWidth - 1] == 'X')//cell to the bottom left
      {
        numNeighbor++;
      }
      if(mapB[cellHeight + 1][cellWidth] == 'X')//cell to the bottom
      {
        numNeighbor++;
      }
      if(mapB[cellHeight + 1][cellWidth + 1] == 'X')//cell to the bottom right
      {
        numNeighbor++;
      }
      if(mapB[cellHeight][cellWidth + 1] == 'X')//cell to the right
      {
        numNeighbor++;
      }
    }
  }
  else if(cellHeight == mapHeight - 1) //checks if cell is at the bottom of the grid
  {
    if(cellWidth == 0)//check if the cell is at the bottom left corner
    {
      if(mapB[cellHeight][cellWidth + 1] == 'X')//cell to the right
      {
        numNeighbor++;
      }
      if(mapB[cellHeight - 1][cellWidth + 1] == 'X')//cell to the top right
      {
        numNeighbor++;
      }
      if(mapB[cellHeight - 1][cellWidth] == 'X')//cell to the top
      {
        numNeighbor++;
      }
    }
    else if(cellWidth == mapWidth - 1)//checks if the cell is at the bottom right corner
    {
      if(mapB[cellHeight][cellWidth - 1] == 'X')//cell to the left
      {
        numNeighbor++;
      }
      if(mapB[cellHeight - 1][cellWidth] == 'X')//cell to the top
      {
        numNeighbor++;
      }
      if(mapB[cellHeight - 1][cellWidth - 1] == 'X')//cell to the top left
      {
        numNeighbor++;
      }
    }
    else//cell is along the bottom of the map but not in a corner
    {
      if(mapB[cellHeight][cellWidth - 1] == 'X')//cell to the left
      {
        numNeighbor++;
      }
      if(mapB[cellHeight][cellWidth + 1] == 'X')//cell to the right
      {
        numNeighbor++;
      }
      if(mapB[cellHeight - 1][cellWidth + 1] == 'X')//cell to the top right
      {
        numNeighbor++;
      }
      if(mapB[cellHeight - 1][cellWidth] == 'X')//cell to the top
      {
        numNeighbor++;
      }
      if(mapB[cellHeight - 1][cellWidth - 1] == 'X')//cell to the top left
      {
        numNeighbor++;
      }
    }
    return numNeighbor;
  }
  else if(cellWidth == 0)//check if the cell is on the left wall
  {
    if(mapB[cellHeight + 1][cellWidth] == 'X')//cell to the bottom
    {
      numNeighbor++;
    }
    if(mapB[cellHeight + 1][cellWidth + 1] == 'X')//cell to the bottom right
    {
      numNeighbor++;
    }
    if(mapB[cellHeight][cellWidth + 1] == 'X')//cell to the right
    {
      numNeighbor++;
    }
    if(mapB[cellHeight - 1][cellWidth + 1] == 'X')//cell to the top rIght
    {
      numNeighbor++;
    }
    if(mapB[cellHeight - 1][cellWidth] == 'X')//cell to the top
    {
      numNeighbor++;
    }
  }
  else if(cellWidth == mapWidth - 1)//check if the celll is on the right wall
  {
    if(mapB[cellHeight][cellWidth - 1] == 'X')//cell to the left
    {
      numNeighbor++;
    }
    if(mapB[cellHeight + 1][cellWidth - 1] == 'X')//cell to the bottom left
    {
      numNeighbor++;
    }
    if(mapB[cellHeight + 1][cellWidth] == 'X')//cell to the bottom
    {
      numNeighbor++;
    }
    if(mapB[cellHeight - 1][cellWidth] == 'X')//cell to the top
    {
      numNeighbor++;
    }
    if(mapB[cellHeight - 1][cellWidth - 1] == 'X')//cell to the top left
    {
      numNeighbor++;
    }
  }
  else //cell is not along any of the edges of the grid
  {
    if(mapB[cellHeight][cellWidth - 1] == 'X')//cell to the left
    {
      numNeighbor++;
    }
    if(mapB[cellHeight + 1][cellWidth - 1] == 'X')//cell to the bottom left
    {
      numNeighbor++;
    }
    if(mapB[cellHeight + 1][cellWidth] == 'X')//cell to the bottom
    {
      numNeighbor++;
    }
    if(mapB[cellHeight + 1][cellWidth + 1] == 'X')//cell to the bottom right
    {
      numNeighbor++;
    }
    if(mapB[cellHeight][cellWidth + 1] == 'X')//cell to the right
    {
      numNeighbor++;
    }
    if(mapB[cellHeight - 1][cellWidth + 1] == 'X')//cell to the top rIght
    {
      numNeighbor++;
    }
    if(mapB[cellHeight - 1][cellWidth] == 'X')//cell to the top
    {
      numNeighbor++;
    }
    if(mapB[cellHeight - 1][cellWidth - 1] == 'X')//cell to the top left
    {
      numNeighbor++;
    }
  }
}
int Modes::checkNeighborDoughnut(int cellHeight, int cellWidth)
{
  
}
int Modes::checkNeighborMirror(int cellHeight, int cellWidth)
{

}
