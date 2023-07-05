#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>

using namespace std;

int main() {
    const int MAP_SIZE_X = 5;
    const int MAP_SIZE_Y = 5;
    int map[MAP_SIZE_Y][MAP_SIZE_X] = {0,};
    vector<int> checkNumber;
    int saveNumber = 0;
    bool isSame = false;
    int myLocationY = 0, myLocationX = 0;
    int binggoY = 0, binggoX = 0;
    int binggoCount = 0;
    int finalBinggo = 0;

    int key = 0;

    srand(time(NULL));

    // 중복 숫자 제거
    for (int y = 0; y < MAP_SIZE_Y; y++) {
        for (int x = 0; x < MAP_SIZE_X; x++) {
            while (true) {
                isSame = false;
                saveNumber = random() % 25 + 1;
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
    // 중복 숫자 제거

    // 맵 프린트
    for (int y = 0; y < MAP_SIZE_Y; y++) {
        for (int x = 0; x < MAP_SIZE_X; x++) {
            printf("%4d",map[y][x]);
        }
        printf("\n");
    }
    // 맵 프린트

    while (true) {
        cin >> key;

        // 숫자 위치 체크 후 0으로 치환
        for (int y = 0; y < MAP_SIZE_Y; y++) {
            for (int x = 0; x < MAP_SIZE_X; x++) {
                if (map[y][x] == key) {
                    map[y][x] = 0;
                }
            }
        }
        // 숫자 위치 체크 후 0으로 치환

        // Bingo 승리조건
        for (int y = 0; y < MAP_SIZE_Y; y++) {
            binggoCount = 0;
            for (int x = 0; x < MAP_SIZE_X; x++) {
                if (map[y][x] == 0) {
                    binggoCount++;
                }

                if (binggoCount == 5) {
                    finalBinggo += 1;
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
                    finalBinggo += 1;
                }
            }
        }

        if (map[0][0] == 0 && map[1][1] == 0 && map[2][2] == 0 && map[3][3] == 0 && map[4][4] == 0) {
            finalBinggo += 1;
        }

        if (map[0][4] == 0 && map[1][3] == 0 && map[2][2] == 0 && map[3][1] == 0 && map[4][0] == 0) {
            finalBinggo += 1;
        }
        // Bingo 승리조건

        if (finalBinggo >= 3) {
            printf("%d개 빙고 성공",finalBinggo);
            break;
        }

        // 맵 프린트
        system("clear");
        printf("%d개 빙고 \n",finalBinggo);
        for (int y = 0; y < MAP_SIZE_Y; y++) {
            for (int x = 0; x < MAP_SIZE_X; x++) {
                if (map[y][x] == 0) {
                    printf("   #");
                } else {
                    printf("%4d",map[y][x]);
                }
            }
            printf("\n");
        }
        // 맵 프린트
        finalBinggo = 0;
    }
}