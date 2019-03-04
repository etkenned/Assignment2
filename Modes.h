#include <iostream>

using namespace std;

class Modes
{
  public:
    Modes();
    ~Modes();
    bool mapA[1000][1000];
    bool mapB[1000][1000];
    int mapHeight;
    int mapWidth;
    int numOfGenerations = 0;
    void swapMaps();// coppies the placements of the Xs from matB to mapA
    bool Stable();//checks if the simulation has stabilized
    void randomMap(); //creates a map from parameters inputed by the user
    void provideMap(); // takes map from a file inputed by the user.
    void Classic();
    void Doughnut();
    void Mirror();
    void DisplayGen(); //prints mapB
    int checkNeighborClassic(int cellHeight, int cellWidth);
    int checkNeighborDoughnut(int cellHeight, int cellWidth);
    int checkNeighborMirror(int cellHeight, int cellWidth);

};
