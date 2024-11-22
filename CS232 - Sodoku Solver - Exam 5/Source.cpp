#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

const int ROW = 9;
const int COL = 9;

void fillCrossHatchArrWithZeroes(int crossHatchArr[ROW][COL]);
void crossHatchBasedOnNum(int numPar);

int main() {
	//declarations
	int userNum;

	int puzzleArr[ROW][COL] = {
		{5, 3, 4, 0, 7, 0, 9, 1, 2},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 4},
		{2, 8, 7, 4, 1, 9, 0, 0, 5},
		{3, 4, 5, 0, 8, 0, 0, 7, 9}
	};

	int crossHatchArr[ROW][COL] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
	};

	//get user input
	cout << "What puzzle number do you want to cross hatch: ";
	cin >> userNum;




	return 0;
}

void fillCrossHatchArrWithZeroes(int crossHatchArr[ROW][COL]) {
	int startingPoint = 0;

	for (int i = startingPoint; i < ROW; i++) {
		for (int j = startingPoint; j < COL; j++) {
			crossHatchArr[i][j] = 0;
		}
	}
}