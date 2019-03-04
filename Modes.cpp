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
  while(true)//asks which type of mode to run the simulation in
  {
    string choice2 = "";
    cout << "Which kind of boundary mode will the simulation run in? : (classic)(doughnut)(mirror)" << endl;
    cin >> choice2;
    if(choice2 == "classic")
    {

      while(true) // ask which kind of pause to apply between Generations
      {
        string choice3 = "";
        cout << "Do you want a pause between generations and to press [enter] to continue, or if it will all be outputted to a file? : (enter)(file)" << endl;
        cin >> choice3;
        if(choice3 == "enter")
        {
          while(true)
          {
            Classic();
            DisplayGen();
            if(Stable())
            {
              break;
            }
            swapMaps();
            cout << "Press [enter] to see the next generation." << endl;
            cin.ignore(); //ignores whatever is typed before [enter] is pressed
          }
          break; // exits the "Which pause" while loop
        }
        else if(choice3 == "file")
        {
          string name = "";
          cout << "Enter the name for the file" << endl;
          cin >> name;
          fstream outputFile(name);
          if(outputFile.is_open())
          {
            while(true)
            {
              Classic();
              if(Stable())
              {
                break;
              }
              swapMaps();
              numOfGenerations++; // keeps track of the number of Generations
              outputFile << "Generation " << numOfGenerations << endl; // marks which genortion is being printed to the file
              for(int i = 0; i < mapHeight - 1; i++)
              {
                for(int j = 0; j < mapWidth - 1; j++)
                {
                  if(mapB[i][j] == true)
                  {
                    outputFile << "X";
                  }
                  else
                  {
                  outputFile << "-";
                  }
                }
                outputFile << endl;
              }
            }
          }
          outputFile.close();
          break; // exits the "Which pause" while loop
        }
        else
        {
          cout << "Invalid input, please try again." << endl;
        }
      }

      break; //exits the "Which boundary mode while loop"
    }
    else if(choice2 == "doughnut")
    {
      while(true) // ask which kind of pause to apply between Generations
      {
        string choice3 = "";
        cout << "Do you want a pause between generations and to press [enter] to continue, or if it will all be outputted to a file? : (enter)(file)" << endl;
        cin >> choice3;
        if(choice3 == "enter")
        {
          while(true)
          {
            Doughnut();
            DisplayGen();
            if(Stable())
            {
              break;
            }
            swapMaps();
            cout << "Press [enter] to see the next generation." << endl;
            cin.ignore(); //ignores whatever is typed before [enter] is pressed
          }
          break; // exits the which pause while loop
        }
        else if(choice3 == "file")
        {
          string name = "";
          cout << "Enter the name for the file" << endl;
          cin >> name;
          fstream outputFile(name);
          if(outputFile.is_open())
          {
            while(true)
            {

              Doughnut();
              if(Stable())
              {
                break;
              }
              swapMaps();
              numOfGenerations++; // keeps track of the number of Generations
              outputFile << "Generation " << numOfGenerations << endl; // marks which genortion is being printed to the file
              for(int i = 0; i < mapHeight - 1; i++)
              {
                for(int j = 0; j < mapWidth - 1; j++) //fix th
                {
                  if(mapB[i][j] == true)
                  {
                    outputFile << "X";
                  }
                  else
                  {
                  outputFile << "-";
                  }
                }
                outputFile << endl;
              }
            }
          }
          outputFile.close();
          break; // exits the "which pause" while loop
        }
        else
        {
          cout << "Invalid input, please try again." << endl;
        }
      }
      break; //exits the "Which boundary mode while loop"
    }
    else if(choice2 == "mirror")
    {
      while(true) // ask which kind of pause to apply between Generations
      {
        string choice3 = "";
        cout << "Do you want a pause between generations and to press [enter] to continue, or if it will all be outputted to a file? : (enter)(file)" << endl;
        cin >> choice3;
        if(choice3 == "enter")
        {
          while(true)
          {
            Mirror();
            DisplayGen();
            if(Stable())
            {
              break;
            }
            swapMaps();
            cout << "Press [enter] to see the next generation." << endl;
            cin.ignore(); //ignores whatever is typed before [enter] is pressed
          }
          break; // exits the "which pause" while loop
        }
        else if(choice3 == "file")
        {
          string name = "";
          cout << "Enter the name for the file" << endl;
          cin >> name;
          fstream outputFile(name);
          if(outputFile.is_open())
          {
            while(true)
            {
              Mirror();
              if(Stable())
              {
                break;
              }
              swapMaps();
              numOfGenerations++; // keeps track of the number of Generations
              outputFile << "Generation " << numOfGenerations << endl; // marks which genortion is being printed to the file
              for(int i = 0; i < mapHeight - 1; i++)
              {
                for(int j = 0; j < mapWidth - 1; j++) //fix th
                {
                  if(mapB[i][j] == true)
                  {
                    outputFile << "X";
                  }
                  else
                  {
                  outputFile << "-";
                  }
                }
                outputFile << endl;
              }
            }
          }
          outputFile.close();
          break; // exits the "which pause" while loop
        }
        else
        {
          cout << "Invalid input, please try again." << endl;
        }
      }
      break; //exits the "Which boundary mode while loop"
    }
    else
    {
      cout << "Invalid input, please try again." << endl;
    }
  }
}
Modes::~Modes()//destructor
{

}
void Modes::DisplayGen()
{
  for(int i = 0; i < mapHeight - 1; i++)
  {
    for(int j = 0; j < mapWidth - 1; j++)
    {
      if(mapB[i][j] == true)
      {
        cout << "X";
      }
      else
      {
        cout << "-";
      }
    }
    cout << endl;
  }
}
bool Modes::Stable()
{
  for(int i = 0; i < mapHeight - 1; i++)
  {
    for(int j = 0; j < mapWidth - 1; j++)
    {
      if(mapA[i][j] != mapB[i][j])
      {
        return false;
      }
    }
  }
  return true;
}
void Modes::swapMaps()
{
  for(int i = 0; i < mapHeight - 1; i++)
  {
    for(int j = 0; j < mapWidth - 1; j++)
    {
      mapA[i][j] = mapB[i][j];
    }
  }
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
  int cellCount = mapHeight * mapWidth * popDensity;
  int randomHeight = 0;
  int randomWidth = 0;
  for(int i = 0; i < cellCount; i++) // fills the map with cells determined by the population dencity
  {
    randomHeight = rand() % mapHeight-1;
    randomWidth = rand() % mapWidth-1;

    if(mapA[randomHeight][randomWidth] == false) // if random spot on the map is empty, fill it with a cell
    {
      mapA[randomHeight][randomWidth] = true;
    }
    else // if spot is not empty then try again
    {
      i--;
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
    int lineCount = 0;
    while (getline(inputMap, line))
    {
      if(lineCount == 0)
      {
        mapHeight = stoi(line);
      }
      else if(lineCount == 1)
      {
        mapWidth = stoi(line);
      }
      else
      {
        for(int i = 0; i < line.length() - 1; i++)
        {
          if(line[i] == 'X') //saves the x as true
          {
            mapA[lineCount - 2][i] = true; //writes the map to the array
          }
          else
          {
            mapA[lineCount - 2][i] = false;
          }
        }




      }
      lineCount++;
    }
  }
  inputMap.close();
}
void Modes::Classic() // runs classic mode of Game of Life for 1 Generation
{
  for(int i = 0; i < mapHeight - 1; i++)
  {
    for(int j = 0; j < mapWidth - 1; j++)
    {
      //check for neighabors
      if(checkNeighborClassic(i,j) <= 1)
      {
        mapB[i][j] = false;
      }
      else if(checkNeighborClassic(i,j) == 3)
      {
        mapB[i][j] = true;
      }
      else if(checkNeighborClassic(i,j) >= 4)
      {
        mapB[i][j] = false;
      }
    }
  }

}

void Modes::Doughnut()
{
  for(int i = 0; i < mapHeight - 1; i++)
  {
    for(int j = 0; j < mapWidth - 1; j++)
    {
      //check for neighabors
      if(checkNeighborDoughnut(i,j) <= 1)
      {
        mapB[i][j] = false;
      }
      else if(checkNeighborDoughnut(i,j) == 3)
      {
        mapB[i][j] = true;
      }
      else if(checkNeighborDoughnut(i,j) >= 4)
      {
        mapB[i][j] = false;
      }
    }
  }
}

void Modes::Mirror()
{
  for(int i = 0; i < mapHeight - 1; i++)
  {
    for(int j = 0; j < mapWidth - 1; j++)
    {
      //check for neighabors
      if(checkNeighborMirror(i,j) <= 1)
      {
        mapB[i][j] = false;
      }
      else if(checkNeighborMirror(i,j) == 3)
      {
        mapB[i][j] = true;
      }
      else if(checkNeighborMirror(i,j) >= 4)
      {
        mapB[i][j] = false;
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
      if(mapA[cellHeight + 1][cellWidth] == true)//cell below
      {
        numNeighbor++;
      }
      if(mapA[cellHeight + 1][cellWidth + 1] == true)//cell to the bottom right
      {
        numNeighbor++;
      }
      if(mapA[cellHeight][cellWidth + 1] == true)//cell to the right
      {
        numNeighbor++;
      }
    }
    else if(cellWidth == mapWidth - 1)//check if the cell is at the top right corner
    {
      if(mapA[cellHeight][cellWidth - 1] == true) //cell to the left
      {
        numNeighbor++;
      }
      if(mapA[cellHeight + 1][cellWidth - 1] == true)//cell to the bottom left
      {
        numNeighbor++;
      }
      if(mapA[cellHeight + 1][cellWidth] == true)//cell below
      {
        numNeighbor++;
      }
    }
    else //cell is along the top wall of the map but not in a corner
    {
      if(mapA[cellHeight][cellWidth - 1] == true) //cell to the left
      {
        numNeighbor++;
      }
      if(mapA[cellHeight + 1][cellWidth - 1] == true)//cell to the bottom left
      {
        numNeighbor++;
      }
      if(mapA[cellHeight + 1][cellWidth] == true)//cell to the bottom
      {
        numNeighbor++;
      }
      if(mapA[cellHeight + 1][cellWidth + 1] == true)//cell to the bottom right
      {
        numNeighbor++;
      }
      if(mapA[cellHeight][cellWidth + 1] == true)//cell to the right
      {
        numNeighbor++;
      }
    }
  }
  else if(cellHeight == mapHeight - 1) //checks if cell is at the bottom of the grid
  {
    if(cellWidth == 0)//check if the cell is at the bottom left corner
    {
      if(mapA[cellHeight][cellWidth + 1] == true)//cell to the right
      {
        numNeighbor++;
      }
      if(mapA[cellHeight - 1][cellWidth + 1] == true)//cell to the top right
      {
        numNeighbor++;
      }
      if(mapA[cellHeight - 1][cellWidth] == true)//cell to the top
      {
        numNeighbor++;
      }
    }
    else if(cellWidth == mapWidth - 1)//checks if the cell is at the bottom right corner
    {
      if(mapA[cellHeight][cellWidth - 1] == true)//cell to the left
      {
        numNeighbor++;
      }
      if(mapA[cellHeight - 1][cellWidth] == true)//cell to the top
      {
        numNeighbor++;
      }
      if(mapA[cellHeight - 1][cellWidth - 1] == true)//cell to the top left
      {
        numNeighbor++;
      }
    }
    else//cell is along the bottom of the map but not in a corner
    {
      if(mapA[cellHeight][cellWidth - 1] == true)//cell to the left
      {
        numNeighbor++;
      }
      if(mapA[cellHeight][cellWidth + 1] == true)//cell to the right
      {
        numNeighbor++;
      }
      if(mapA[cellHeight - 1][cellWidth + 1] == true)//cell to the top right
      {
        numNeighbor++;
      }
      if(mapA[cellHeight - 1][cellWidth] == true)//cell to the top
      {
        numNeighbor++;
      }
      if(mapA[cellHeight - 1][cellWidth - 1] == true)//cell to the top left
      {
        numNeighbor++;
      }
    }

  }
  else if(cellWidth == 0)//check if the cell is on the left wall
  {
    if(mapA[cellHeight + 1][cellWidth] == true)//cell to the bottom
    {
      numNeighbor++;
    }
    if(mapA[cellHeight + 1][cellWidth + 1] == true)//cell to the bottom right
    {
      numNeighbor++;
    }
    if(mapA[cellHeight][cellWidth + 1] == true)//cell to the right
    {
      numNeighbor++;
    }
    if(mapA[cellHeight - 1][cellWidth + 1] == true)//cell to the top rIght
    {
      numNeighbor++;
    }
    if(mapA[cellHeight - 1][cellWidth] == true)//cell to the top
    {
      numNeighbor++;
    }
  }
  else if(cellWidth == mapWidth - 1)//check if the celll is on the right wall
  {
    if(mapA[cellHeight][cellWidth - 1] == true)//cell to the left
    {
      numNeighbor++;
    }
    if(mapA[cellHeight + 1][cellWidth - 1] == true)//cell to the bottom left
    {
      numNeighbor++;
    }
    if(mapA[cellHeight + 1][cellWidth] == true)//cell to the bottom
    {
      numNeighbor++;
    }
    if(mapA[cellHeight - 1][cellWidth] == true)//cell to the top
    {
      numNeighbor++;
    }
    if(mapA[cellHeight - 1][cellWidth - 1] == true)//cell to the top left
    {
      numNeighbor++;
    }
  }
  else //cell is not along any of the edges of the grid
  {
    if(mapA[cellHeight][cellWidth - 1] == true)//cell to the left
    {
      numNeighbor++;
    }
    if(mapA[cellHeight + 1][cellWidth - 1] == true)//cell to the bottom left
    {
      numNeighbor++;
    }
    if(mapA[cellHeight + 1][cellWidth] == true)//cell to the bottom
    {
      numNeighbor++;
    }
    if(mapA[cellHeight + 1][cellWidth + 1] == true)//cell to the bottom right
    {
      numNeighbor++;
    }
    if(mapA[cellHeight][cellWidth + 1] == true)//cell to the right
    {
      numNeighbor++;
    }
    if(mapA[cellHeight - 1][cellWidth + 1] == true)//cell to the top rIght
    {
      numNeighbor++;
    }
    if(mapA[cellHeight - 1][cellWidth] == true)//cell to the top
    {
      numNeighbor++;
    }
    if(mapA[cellHeight - 1][cellWidth - 1] == true)//cell to the top left
    {
      numNeighbor++;
    }
  }
  return numNeighbor;
}

int Modes::checkNeighborDoughnut(int cellHeight, int cellWidth)
{
  int numNeighbor = 0;// keeps track of the number of neighaboring cells
  if(cellHeight == 0)//check if the cell is at the top of the grid
  {
    if(cellWidth == 0)//check if the cell is at the top left corner
    {
      if(mapA[cellHeight + 1][cellWidth] == true)//cell below
      {
        numNeighbor++;
      }
      if(mapA[cellHeight + 1][cellWidth + 1] == true)//cell to the bottom right
      {
        numNeighbor++;
      }
      if(mapA[cellHeight][cellWidth + 1] == true)//cell to the right
      {
        numNeighbor++;
      }
      if(mapA[mapHeight - 1][cellWidth + 1] == true)//doughnut reflection of top right cell to bottom left cell next to corner
      {
        numNeighbor++;
      }
      if(mapA[mapHeight - 1][cellWidth] == true)//doughnut reflection of top cell to bottom left corner cell
      {
        numNeighbor++;
      }
      if(mapA[mapHeight - 1][mapWidth - 1] == true)//doughnut reflection of top left cell to bottom right corner cell
      {
        numNeighbor++;
      }
      if(mapA[cellHeight][mapWidth - 1] == true)//doughnut reflection of left cell to right corner cell
      {
        numNeighbor++;
      }
      if(mapA[cellHeight + 1][mapWidth - 1] == true)//doughnut reflection of top left cell to next to top right corner cell
      {
        numNeighbor++;
      }
    }

    else if(cellWidth == mapWidth - 1)//check if the cell is at the top right corner
    {
      if(mapA[cellHeight][cellWidth - 1] == true) //cell to the left
      {
        numNeighbor++;
      }
      if(mapA[cellHeight + 1][cellWidth - 1] == true)//cell to the bottom left
      {
        numNeighbor++;
      }
      if(mapA[cellHeight + 1][cellWidth] == true)//cell below
      {
        numNeighbor++;
      }
      if(mapA[cellHeight + 1][0] == true)//doughnut reflection of bottom right cell to left side cell
      {
        numNeighbor++;
      }
      if(mapA[0][0] == true)//doughnut reflection of right cell to top left corner cell
      {
        numNeighbor++;
      }
      if(mapA[mapHeight - 1][0] == true)//doughnut reflection of top right cell to bottom left corner cell
      {
        numNeighbor++;
      }
      if(mapA[mapHeight - 1][mapWidth - 1] == true)//doughnut reflection of top cell to bottom right corner cell
      {
        numNeighbor++;
      }
      if(mapA[mapHeight - 1][cellWidth - 1] == true)//doughnut reflection of top left cell to next to bottom right corner cell
      {
        numNeighbor++;
      }
    }

    else //cell is along the top wall of the map but not in a corner
    {
      if(mapA[cellHeight][cellWidth - 1] == true) //cell to the left
      {
        numNeighbor++;
      }
      if(mapA[cellHeight + 1][cellWidth - 1] == true)//cell to the bottom left
      {
        numNeighbor++;
      }
      if(mapA[cellHeight + 1][cellWidth] == true)//cell to the bottom
      {
        numNeighbor++;
      }
      if(mapA[cellHeight + 1][cellWidth + 1] == true)//cell to the bottom right
      {
        numNeighbor++;
      }
      if(mapA[cellHeight][cellWidth + 1] == true)//cell to the right
      {
        numNeighbor++;
      }
      if(mapA[mapHeight - 1][cellWidth + 1] == true)//doughnut reflection of top right cell to the bottom wall
      {
        numNeighbor++;
      }
      if(mapA[mapHeight - 1][cellWidth] == true)//doughnut reflection of top cell to the bottom wall
      {
        numNeighbor++;
      }
      if(mapA[mapHeight - 1][cellWidth - 1] == true)//doughnut reflection of top left cell to the bottom wall
      {
        numNeighbor++;
      }
    }
  }

  else if(cellHeight == mapHeight - 1) //checks if cell is at the bottom of the grid
  {
    if(cellWidth == 0)//check if the cell is at the bottom left corner
    {
      if(mapA[cellHeight][cellWidth + 1] == true)//cell to the right
      {
        numNeighbor++;
      }
      if(mapA[cellHeight - 1][cellWidth + 1] == true)//cell to the top right
      {
        numNeighbor++;
      }
      if(mapA[cellHeight - 1][cellWidth] == true)//cell to the top
      {
        numNeighbor++;
      }
      if(mapA[cellHeight - 1][mapWidth - 1] == true)//doughnut reflection of top left cell to the far right wall
      {
        numNeighbor++;
      }
      if(mapA[cellHeight][mapWidth - 1] == true)//doughnut reflection of left cell to the right wall
      {
        numNeighbor++;
      }
      if(mapA[0][mapWidth - 1] == true)//doughnut reflection of bottom left cell to the top right corner
      {
        numNeighbor++;
      }
      if(mapA[0][0] == true)//doughnut reflection of bottom cell to the top left corner
      {
        numNeighbor++;
      }
      if(mapA[0][cellWidth + 1] == true)//doughnut reflection of bottom right cell to the top wall
      {
        numNeighbor++;
      }
    }

    else if(cellWidth == mapWidth - 1)//checks if the cell is at the bottom right corner
    {
      if(mapA[cellHeight][cellWidth - 1] == true)//cell to the left
      {
        numNeighbor++;
      }
      if(mapA[0][cellWidth - 1] == true)//doughnut reflection of bottom left cell to the top
      {
        numNeighbor++;
      }
      if(mapA[0][mapWidth - 1] == true)//doughnut reflection of bottom cell to the top right corner
      {
        numNeighbor++;
      }
      if(mapA[0][0] == true)//doughnut reflection of bottom right cell to the top left corner
      {
        numNeighbor++;
      }
      if(mapA[cellHeight][0] == true)//doughnut reflection of right cell to the left wall
      {
        numNeighbor++;
      }
      if(mapA[cellHeight - 1][0] == true)//doughnut reflection of top right cell to the left wall
      {
        numNeighbor++;
      }
      if(mapA[cellHeight - 1][cellWidth] == true)//cell to the top
      {
        numNeighbor++;
      }
      if(mapA[cellHeight - 1][cellWidth - 1] == true)//cell to the top left
      {
        numNeighbor++;
      }
    }

    else//cell is along the bottom of the map but not in a corner
    {
      if(mapA[cellHeight][cellWidth - 1] == true)//cell to the left
      {
        numNeighbor++;
      }
      if(mapA[0][cellWidth - 1] == true)//doughnut reflection of bottom left cell to the top wall
      {
        numNeighbor++;
      }
      if(mapA[0][cellWidth] == true)//doughnut reflection of bottom cell to the top wall
      {
        numNeighbor++;
      }
      if(mapA[0][cellWidth + 1] == true)//doughnut reflection of bottom right cell to the top wall
      {
        numNeighbor++;
      }
      if(mapA[cellHeight][cellWidth + 1] == true)//cell to the right
      {
        numNeighbor++;
      }
      if(mapA[cellHeight - 1][cellWidth + 1] == true)//cell to the top right
      {
        numNeighbor++;
      }
      if(mapA[cellHeight - 1][cellWidth] == true)//cell to the top
      {
        numNeighbor++;
      }
      if(mapA[cellHeight - 1][cellWidth - 1] == true)//cell to the top left
      {
        numNeighbor++;
      }
    }

  }
  else if(cellWidth == 0)//check if the cell is on the left wall
  {
    if(mapA[cellHeight][mapWidth - 1] == true)//doughnut reflection of left cell to the right wall
    {
      numNeighbor++;
    }
    if(mapA[cellHeight + 1][mapWidth - 1] == true)//doughnut reflection of bottom left cell to the right wall
    {
      numNeighbor++;
    }
    if(mapA[cellHeight - 1][mapWidth - 1] == true)//doughnut reflection of top left cell to the right wall
    {
      numNeighbor++;
    }
    if(mapA[cellHeight + 1][cellWidth] == true)//cell to the bottom
    {
      numNeighbor++;
    }
    if(mapA[cellHeight + 1][cellWidth + 1] == true)//cell to the bottom right
    {
      numNeighbor++;
    }
    if(mapA[cellHeight][cellWidth + 1] == true)//cell to the right
    {
      numNeighbor++;
    }
    if(mapA[cellHeight - 1][cellWidth + 1] == true)//cell to the top rIght
    {
      numNeighbor++;
    }
    if(mapA[cellHeight - 1][cellWidth] == true)//cell to the top
    {
      numNeighbor++;
    }
  }
  else if(cellWidth == mapWidth - 1)//check if the cell is on the right wall
  {
    if(mapA[cellHeight][cellWidth - 1] == true)//cell to the left
    {
      numNeighbor++;
    }
    if(mapA[cellHeight + 1][cellWidth - 1] == true)//cell to the bottom left
    {
      numNeighbor++;
    }
    if(mapA[cellHeight + 1][cellWidth] == true)//cell to the bottom
    {
      numNeighbor++;
    }
    if(mapA[cellHeight + 1][0] == true)//doughnut reflection of bottom right cell to the left wall
    {
      numNeighbor++;
    }
    if(mapA[cellHeight][0] == true)//doughnut reflection of right cell to the left wall
    {
      numNeighbor++;
    }
    if(mapA[cellHeight - 1][0] == true)//doughnut reflection of top right cell to the left wall
    {
      numNeighbor++;
    }
    if(mapA[cellHeight - 1][cellWidth] == true)//cell to the top
    {
      numNeighbor++;
    }
    if(mapA[cellHeight - 1][cellWidth - 1] == true)//cell to the top left
    {
      numNeighbor++;
    }
  }
  else //cell is not along any of the edges of the grid
  {
    if(mapA[cellHeight][cellWidth - 1] == true)//cell to the left
    {
      numNeighbor++;
    }
    if(mapA[cellHeight + 1][cellWidth - 1] == true)//cell to the bottom left
    {
      numNeighbor++;
    }
    if(mapA[cellHeight + 1][cellWidth] == true)//cell to the bottom
    {
      numNeighbor++;
    }
    if(mapA[cellHeight + 1][cellWidth + 1] == true)//cell to the bottom right
    {
      numNeighbor++;
    }
    if(mapA[cellHeight][cellWidth + 1] == true)//cell to the right
    {
      numNeighbor++;
    }
    if(mapA[cellHeight - 1][cellWidth + 1] == true)//cell to the top rIght
    {
      numNeighbor++;
    }
    if(mapA[cellHeight - 1][cellWidth] == true)//cell to the top
    {
      numNeighbor++;
    }
    if(mapA[cellHeight - 1][cellWidth - 1] == true)//cell to the top left
    {
      numNeighbor++;
    }
  }
  return numNeighbor;
}
int Modes::checkNeighborMirror(int cellHeight, int cellWidth)
{
  int numNeighbor = 0;// keeps track of the number of neighaboring cells
  if(cellHeight == 0)//check if the cell is at the top of the grid
  {
    if(cellWidth == 0)//check if the cell is at the top left corner
    {
      if(mapA[cellHeight + 1][cellWidth] == true)//cell below
      {
        numNeighbor += 2;
      }
      if(mapA[cellHeight + 1][cellWidth + 1] == true)//cell to the bottom right
      {
        numNeighbor++;
      }
      if(mapA[cellHeight][cellWidth + 1] == true)//cell to the right
      {
        numNeighbor += 2;
      }
      if(mapA[0][0] == true)//checks if current cell is occupied
      {
        numNeighbor += 3;
      }
    }
    else if(cellWidth == mapWidth - 1)//check if the cell is at the top right corner
    {
      if(mapA[cellHeight][cellWidth - 1] == true) //cell to the left
      {
        numNeighbor += 2;
      }
      if(mapA[cellHeight + 1][cellWidth - 1] == true)//cell to the bottom left
      {
        numNeighbor++;
      }
      if(mapA[cellHeight + 1][cellWidth] == true)//cell below
      {
        numNeighbor += 2;
      }
      if(mapA[0][mapWidth - 1] == true)// checks if current cell is occupied
      {
        numNeighbor += 3;
      }
    }
    else //cell is along the top wall of the map but not in a corner
    {
      if(mapA[cellHeight][cellWidth - 1] == true) //cell to the left
      {
        numNeighbor += 2;
      }
      if(mapA[cellHeight + 1][cellWidth - 1] == true)//cell to the bottom left
      {
        numNeighbor++;
      }
      if(mapA[cellHeight + 1][cellWidth] == true)//cell to the bottom
      {
        numNeighbor++;
      }
      if(mapA[cellHeight + 1][cellWidth + 1] == true)//cell to the bottom right
      {
        numNeighbor++;
      }
      if(mapA[cellHeight][cellWidth + 1] == true)//cell to the right
      {
        numNeighbor += 2;
      }
    }
  }
  else if(cellHeight == mapHeight - 1) //checks if cell is at the bottom of the grid
  {
    if(cellWidth == 0)//check if the cell is at the bottom left corner
    {
      if(mapA[cellHeight][cellWidth + 1] == true)//cell to the right
      {
        numNeighbor += 2;
      }
      if(mapA[cellHeight - 1][cellWidth + 1] == true)//cell to the top right
      {
        numNeighbor++;
      }
      if(mapA[cellHeight - 1][cellWidth] == true)//cell to the top
      {
        numNeighbor += 2;
      }
      if(mapA[mapHeight - 1][0] == true) //checks if current cell is occupied
      {
        numNeighbor += 3;
      }
    }
    else if(cellWidth == mapWidth - 1)//checks if the cell is at the bottom right corner
    {
      if(mapA[cellHeight][cellWidth - 1] == true)//cell to the left
      {
        numNeighbor += 2;
      }
      if(mapA[cellHeight - 1][cellWidth] == true)//cell to the top
      {
        numNeighbor++;
      }
      if(mapA[cellHeight - 1][cellWidth - 1] == true)//cell to the top left
      {
        numNeighbor += 2;
      }
      if(mapA[mapHeight - 1][mapWidth - 1] == true)//check if current cell is occupied
      {
        numNeighbor += 3;
      }
    }
    else//cell is along the bottom of the map but not in a corner
    {
      if(mapA[cellHeight][cellWidth - 1] == true)//cell to the left
      {
        numNeighbor += 2;
      }
      if(mapA[cellHeight][cellWidth + 1] == true)//cell to the right
      {
        numNeighbor += 2;
      }
      if(mapA[cellHeight - 1][cellWidth + 1] == true)//cell to the top right
      {
        numNeighbor++;
      }
      if(mapA[cellHeight - 1][cellWidth] == true)//cell to the top
      {
        numNeighbor++;
      }
      if(mapA[cellHeight - 1][cellWidth - 1] == true)//cell to the top left
      {
        numNeighbor++;
      }
    }

  }
  else if(cellWidth == 0)//check if the cell is on the left wall
  {
    if(mapA[cellHeight + 1][cellWidth] == true)//cell to the bottom
    {
      numNeighbor += 2;
    }
    if(mapA[cellHeight + 1][cellWidth + 1] == true)//cell to the bottom right
    {
      numNeighbor++;
    }
    if(mapA[cellHeight][cellWidth + 1] == true)//cell to the right
    {
      numNeighbor++;
    }
    if(mapA[cellHeight - 1][cellWidth + 1] == true)//cell to the top rIght
    {
      numNeighbor++;
    }
    if(mapA[cellHeight - 1][cellWidth] == true)//cell to the top
    {
      numNeighbor += 2;
    }
  }
  else if(cellWidth == mapWidth - 1)//check if the celll is on the right wall
  {
    if(mapA[cellHeight][cellWidth - 1] == true)//cell to the left
    {
      numNeighbor++;
    }
    if(mapA[cellHeight + 1][cellWidth - 1] == true)//cell to the bottom left
    {
      numNeighbor++;
    }
    if(mapA[cellHeight + 1][cellWidth] == true)//cell to the bottom
    {
      numNeighbor += 2;
    }
    if(mapA[cellHeight - 1][cellWidth] == true)//cell to the top
    {
      numNeighbor += 2;
    }
    if(mapA[cellHeight - 1][cellWidth - 1] == true)//cell to the top left
    {
      numNeighbor++;
    }
  }
  else //cell is not along any of the edges of the grid
  {
    if(mapA[cellHeight][cellWidth - 1] == true)//cell to the left
    {
      numNeighbor++;
    }
    if(mapA[cellHeight + 1][cellWidth - 1] == true)//cell to the bottom left
    {
      numNeighbor++;
    }
    if(mapA[cellHeight + 1][cellWidth] == true)//cell to the bottom
    {
      numNeighbor++;
    }
    if(mapA[cellHeight + 1][cellWidth + 1] == true)//cell to the bottom right
    {
      numNeighbor++;
    }
    if(mapA[cellHeight][cellWidth + 1] == true)//cell to the right
    {
      numNeighbor++;
    }
    if(mapA[cellHeight - 1][cellWidth + 1] == true)//cell to the top rIght
    {
      numNeighbor++;
    }
    if(mapA[cellHeight - 1][cellWidth] == true)//cell to the top
    {
      numNeighbor++;
    }
    if(mapA[cellHeight - 1][cellWidth - 1] == true)//cell to the top left
    {
      numNeighbor++;
    }
  }
  return numNeighbor;
}
