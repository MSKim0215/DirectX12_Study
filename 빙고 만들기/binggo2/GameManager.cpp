#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include "GameManager.h"

void GameManager::Play()
{
    MakeBoard();

    int finalBinggo = 0;

    while(true)
    {
        cout << "현재 빙고: " << finalBinggo << endl;
        cout << "원하는 숫자를 입력하세요. (0~24) ";

        int key;
        cin >> key;

        ChangeBoard(key);
        PrintBoard();

        finalBinggo = 0;
        if(CheckBingo(&finalBinggo))
        {
            cout << "현재 빙고: " << finalBinggo << endl;
            cout << "빙고 완료!!!" << endl;
            return;
        }
    }
}

void GameManager::PrintBoard()
{
    system("cls");
    for (int y = 0; y < MAP_SIZE_Y; y++) 
    {
        for (int x = 0; x < MAP_SIZE_X; x++) 
        {
            printf("%4d",map[y][x]);
        }
        printf("\n");
    }
}

void GameManager::SettingBoard()
{
    bool isSame = false;
    int saveNumber = 0;

    for (int y = 0; y < MAP_SIZE_Y; y++) {
        for (int x = 0; x < MAP_SIZE_X; x++) {
            while (true) {
                isSame = false;
                saveNumber = ShuffleNumber();
                for (int a : checkNumber) {
                    if (saveNumber == a) {
                        isSame = true;
                        break;
                    }
                }

                if (!isSame) {
                    map[y][x] = saveNumber;
                    checkNumber.push_back(saveNumber);
                    break;
                }
            }
        }
    }
}

int GameManager::ShuffleNumber()
{
    srand(time(NULL));

    return random() % 25 + 1;
}

void GameManager::ChangeBoard(int key)
{
        for (int y = 0; y < MAP_SIZE_Y; y++) {
            for (int x = 0; x < MAP_SIZE_X; x++) {
                if (map[y][x] == key) {
                    map[y][x] = 0;
                }
            }
        }
}

bool GameManager::CheckBingo(int* finalBinggo)
{
    int binggoCount = 0;

    for (int y = 0; y < MAP_SIZE_Y; y++) {
            binggoCount = 0;
            for (int x = 0; x < MAP_SIZE_X; x++) {
                if (map[y][x] == 0) {
                    binggoCount++;
                }

                if (binggoCount == 5) {
                    *finalBinggo += 1;
                }
            }
        }

        for (int x = 0; x < MAP_SIZE_X; x++) {
            binggoCount = 0;
            for (int y = 0; y < MAP_SIZE_Y; y++) {
                if (map[y][x] == 0) {
                    binggoCount++;
                }

                if (binggoCount == 5) {
                    *finalBinggo += 1;
                }
            }
        }

        if (map[0][0] == 0 && map[1][1] == 0 && map[2][2] == 0 && map[3][3] == 0 && map[4][4] == 0) {
            *finalBinggo += 1;
        }

        if (map[0][4] == 0 && map[1][3] == 0 && map[2][2] == 0 && map[3][1] == 0 && map[4][0] == 0) {
            *finalBinggo += 1;
        }

        return *finalBinggo >= 3;
}