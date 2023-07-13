#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

#define MAP_SIZE_X 5
#define MAP_SIZE_Y 5

class GameManager
{
    private:
            vector<int> checkNumber;
            int map[MAP_SIZE_Y][MAP_SIZE_X];

            int ShuffleNumber();
            void SettingBoard();
            void ChangeBoard(int);
            bool CheckBingo(int*);
            void MakeBoard()
            {
                ShuffleNumber();
                SettingBoard();
                PrintBoard();
            }


    public:
            void Play();
            void PrintBoard();
};