#include <iostream>

using namespace std;

class Modes
{
  public:
    Modes();
    ~Modes();
    string *mapA;
    string *mapB;
    int mapHeight;
    int mapWidth;
    void randomMap();
    void provideMap();
    void Classic();
    void Doughnut();
    void Mirror();
    int checkNeighborClassic(int cellHeight, int cellWidth);
    int checkNeighborDoughnut(int cellHeight, int cellWidth);
    int checkNeighborMirror(int cellHeight, int cellWidth);

};
