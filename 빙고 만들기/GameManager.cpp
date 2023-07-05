#include <Windows.h>
#include <iomanip>
#include <iostream>
#include "GameManager.h"

void GameManager::Play()
{
	MakeBoard();

	int bingoCount = 0;
	while (true)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "현재 빙고: " << bingoCount << endl;
		cout << "원하는 숫자를 입력하세요. (0 ~ 24): ";
		int answer;
		cin >> answer;

		ChangeBoard(answer);
		PrintBoard();

		bingoCount = 0;
		if (CheckBingo(&bingoCount))
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "현재 빙고: " << bingoCount << endl;
			cout << "빙고 완료!!!" << endl;
			return;
		}
	}
}

void GameManager::PrintBoard()
{
	system("cls");

	cout << "\n";
	for (int y = 0; y < BOARD_SIZE; y++)
	{
		for (int x = 0; x < BOARD_SIZE; x++)
		{
			if (boards[x][y] == "#")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			cout << setw(10) << left << boards[x][y];
		}
		cout << "\n\n\n";
	}
}

void GameManager::ShuffleNumber()
{
	if (numbers.size() > 0) numbers.clear();

	for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
	{
		numbers.push_back(i);
	}
	random_shuffle(numbers.begin(), numbers.end());
}

void GameManager::SettingBoard()
{
	int index = 0;
	for (int y = 0; y < BOARD_SIZE; y++)
	{
		for (int x = 0; x < BOARD_SIZE; x++)
		{
			boards[x][y] = to_string(numbers[index]);
			index++;
		}
	}
}

void GameManager::ChangeBoard(int answer)
{
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == answer)
		{
			for (int y = 0; y < BOARD_SIZE; y++)
			{
				for (int x = 0; x < BOARD_SIZE; x++)
				{
					if (boards[x][y] == to_string(answer))
					{
						boards[x][y] = "#";
						numbers.erase(numbers.begin() + i);
						break;
					}
				}
			}
		}
	}
}

bool GameManager::CheckBingo(int* bingoCount)
{
	int diagonal1Count = 0, diagonal2Count = 0;

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		int rowCount = 0, colCount = 0;

		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (boards[i][j] == "#") rowCount++;
			if (boards[j][i] == "#") colCount++;
		}

		if (rowCount == BOARD_SIZE) *bingoCount += 1;
		if (colCount == BOARD_SIZE) *bingoCount += 1;

		if (boards[i][i] == "#") diagonal1Count++;
		if (boards[i][BOARD_SIZE - 1 - i] == "#") diagonal2Count++;
	}

	if (diagonal1Count == BOARD_SIZE) *bingoCount += 1;
	if (diagonal2Count == BOARD_SIZE) *bingoCount += 1;

	return *bingoCount >= 3;
}