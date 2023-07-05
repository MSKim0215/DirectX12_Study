#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define BOARD_SIZE 5

class GameManager
{
private:
	vector<int> numbers;
	string boards[BOARD_SIZE][BOARD_SIZE];

	void ShuffleNumber();
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