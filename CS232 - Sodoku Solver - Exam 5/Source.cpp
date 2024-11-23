#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

const int ROW = 9;
const int COL = 9;
const int STARTINGPOINT = 0;

void fillCrossHatchArrWithZeroes(int crossHatchArr[ROW][COL]);
void crossHatchBasedOnNum(int row, int col, int crossHatchArr[ROW][COL]);
void searchForUserNum(int userNum, int puzzleArr[ROW][COL], int crossHatchArr[ROW][COL]);
void displayArray(int crossHatchArray[ROW][COL]);
bool searchForIsolates(int crossHatchArray[ROW][COL]);
bool searchUpperLeftCell(int crossHatchArray[ROW][COL]);
bool searchUpperMidCell(int crossHatchArray[ROW][COL]);
bool searchUpperRightCell(int crossHatchArray[ROW][COL]);
bool searchMidLeftCell(int crossHatchArray[ROW][COL]);
bool searchMidMidCell(int crossHatchArray[ROW][COL]);
bool searchMidRightCell(int crossHatchArray[ROW][COL]);
bool searchBottomLeftCell(int crossHatchArray[ROW][COL]);
bool searchBottomMidCell(int crossHatchArray[ROW][COL]);
bool searchBottomRightCell(int crossHatchArray[ROW][COL]);
void searchForCoordinatesOfIsolate(int crossHatchArray[ROW][COL], int startingRow, int startingCol, int lastRow, int lastCol);

int main() {
	//declarations
	int userNum;

	/*int puzzleArr[ROW][COL] = {
		{5, 3, 4, 0, 7, 0, 9, 1, 2},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 4},
		{2, 8, 7, 4, 1, 9, 0, 0, 5},
		{3, 4, 5, 0, 8, 0, 0, 7, 9}
	};*/

	int puzzleArr[ROW][COL] = {
	{3, 0, 0, 2, 4, 0, 0, 6, 0},
	{0, 4, 0, 0, 0, 0, 0, 5, 3},
	{1, 8, 9, 6, 3, 5, 4, 0, 0},
	{0, 0, 0, 0, 8, 0, 2, 0, 0},
	{0, 0, 7, 4, 9, 6, 8, 0, 1},
	{8, 9, 3, 1, 5, 0, 6, 0, 4},
	{0, 0, 1, 9, 2, 0, 5, 0, 0},
	{2, 0, 0, 3, 0, 0, 7, 4, 0},
	{9, 6, 0, 5, 0, 0, 3, 0, 2}
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


	//calculations
	cout << "Cross Hatch Before: " << endl;
	displayArray(crossHatchArr);
	cout << endl;

	cout << "Puzzle Contents: " << endl;
	displayArray(puzzleArr);
	cout << endl;

	cout << "Cross Hatch After: " << endl;
	searchForUserNum(userNum, puzzleArr, crossHatchArr);
	cout << endl;

	cout << endl;

  	if (searchForIsolates(crossHatchArr) == true) {
		cout << "There is an isolate in the puzzle." << endl;
		cout << "Would you like to populate the puzzle? (Y/N): " << endl;


	}
	else {
		cout << "There are no isolates of this number." << endl;
	}




	return 0;
}

void fillCrossHatchArrWithZeroes(int crossHatchArr[ROW][COL]) {
	for (int i = STARTINGPOINT; i < ROW; i++) {
		for (int j = STARTINGPOINT; j < COL; j++) {
			crossHatchArr[i][j] = 0;
		}
	}
}

void crossHatchBasedOnNum(int row, int col, int crossHatchArr[ROW][COL]) {
	int rowToCrossHatch = row;
	int colToCrossHatch = col;

	for (int i = STARTINGPOINT; i < COL; i++) { //Cross hatches the row (using 1s)
		crossHatchArr[rowToCrossHatch][i] = 1;
	}

	for (int i = STARTINGPOINT; i < ROW; i++) { //Cross hatches the column (using 1s)
		crossHatchArr[i][colToCrossHatch] = 1;
	}
}

void searchForUserNum(int userNum, int puzzleArr[ROW][COL], int crossHatchArr[ROW][COL]) {
	int numToSearchFor = userNum;
	int rowOfNumberFound;
	int colOfNumberFound;

	for (int i = STARTINGPOINT; i < ROW; i++) {
		for (int j = STARTINGPOINT; j < COL; j++) {
			if (puzzleArr[i][j] == numToSearchFor) {
				rowOfNumberFound = i;
				colOfNumberFound = j;
				crossHatchBasedOnNum(rowOfNumberFound, colOfNumberFound, crossHatchArr);
			}
		}
	}

	displayArray(crossHatchArr);
}

void displayArray(int crossHatchArray[ROW][COL]) {

	for (int i = STARTINGPOINT; i < ROW; i++) {

		if (i % 3 == 0 && i != 0) {
			cout << "-----------";
			cout << endl;
		}

		for (int j = STARTINGPOINT; j < COL; j++) {

			if (j % 3 == 0 && j != 0) {
				cout << "|";
			}

			cout << crossHatchArray[i][j];
		}

		cout << endl;
	}
};

bool searchForIsolates(int crossHatchArray[ROW][COL]) {
	bool isolateConfirmation = false;

	if (searchUpperLeftCell(crossHatchArray) == true || searchUpperMidCell(crossHatchArray) == true || searchUpperRightCell(crossHatchArray) == true || searchMidLeftCell(crossHatchArray) == true || searchMidMidCell(crossHatchArray) == true || searchMidRightCell(crossHatchArray) == true || searchBottomLeftCell(crossHatchArray) == true || searchBottomMidCell(crossHatchArray) == true || searchBottomRightCell(crossHatchArray) == true) {
		isolateConfirmation = true;
	}

	return isolateConfirmation;
};

void searchForCoordinatesOfIsolate(int crossHatchArray[ROW][COL], int startingRow, int startingCol, int lastRow, int lastCol) {
	int rowOfZero;
	int colOfZero;
	int numToSearchFor = 0;

	for (int i = STARTINGPOINT; i < lastRow; i++) { //row count
		for (int j = STARTINGPOINT; j < lastCol; j++) { //col 
			if (crossHatchArray[i][j] == numToSearchFor) {
				rowOfZero = i;
				colOfZero = j;
			}
		}
	}
}

bool searchUpperLeftCell(int crossHatchArray[ROW][COL]) {
	//The upper left cell consists of rows 0 - 2
	int startingRow = 0;
	int startingCol = 0;
	int lastRow = 2;
	int lastCol = 2;
	int numToSearchFor = 0;
	int countOfZeroes = 0;
	bool isolateConfirmation = false;

	for (int i = startingRow; i <= lastRow; i++) { //row count

		for (int j = startingCol; j < lastCol; j++) { //col count

			if (crossHatchArray[i][j] == numToSearchFor) {
				countOfZeroes += 1;
			}
		}
	}

	if (countOfZeroes == 1) {
		isolateConfirmation = true;
		searchForCoordinatesOfIsolate(crossHatchArray, startingRow, startingCol, lastRow, lastCol);
	}

	return isolateConfirmation;

}

bool searchUpperMidCell(int crossHatchArray[ROW][COL]) {
	//The Upper mid cell consists of rows 0 - 2, and cols 3 - 5
	int startingRow = 0;
	int startingCol = 3;
	int lastRow = 2;
	int lastCol = 5;
	int numToSearchFor = 0;
	int countOfZeroes = 0;
	bool isolateConfirmation = false;

	for (int i = startingRow; i <= lastRow; i++) { //row count

		for (int j = startingCol; j < lastCol; j++) { //col count

			if (crossHatchArray[i][j] == numToSearchFor) {
				countOfZeroes += 1;
			}
		}
	}

	if (countOfZeroes == 1) {
		isolateConfirmation = true;
		searchForCoordinatesOfIsolate(crossHatchArray, startingRow, startingCol, lastRow, lastCol);
	}

	return isolateConfirmation;
}

bool searchUpperRightCell(int crossHatchArray[ROW][COL]) {
	//The Upper right cell consists of rows 0 - 2, and cols 6 - 8
	int startingRow = 0;
	int startingCol = 6;
	int lastRow = 2;
	int lastCol = 8;
	int numToSearchFor = 0;
	int countOfZeroes = 0;
	bool isolateConfirmation = false;

	for (int i = startingRow; i <= lastRow; i++) { //row count

		for (int j = startingCol; j < lastCol; j++) { //col count

			if (crossHatchArray[i][j] == numToSearchFor) {
				countOfZeroes += 1;
			}
		}
	}

	if (countOfZeroes == 1) {
		isolateConfirmation = true;
		searchForCoordinatesOfIsolate(crossHatchArray, startingRow, startingCol, lastRow, lastCol);
	}

	return isolateConfirmation;
}

bool searchMidLeftCell(int crossHatchArray[ROW][COL]) {
	//The mid left cell consists of rows 3 - 5, and cols 0 - 2
	int startingRow = 3;
	int startingCol = 0;
	int lastRow = 5;
	int lastCol = 2;
	int numToSearchFor = 0;
	int countOfZeroes = 0;
	bool isolateConfirmation = false;

	for (int i = startingRow; i <= lastRow; i++) { //row count

		for (int j = startingCol; j < lastCol; j++) { //col count

			if (crossHatchArray[i][j] == numToSearchFor) {
				countOfZeroes += 1;
			}
		}
	}

	if (countOfZeroes == 1) {
		isolateConfirmation = true;
		searchForCoordinatesOfIsolate(crossHatchArray, startingRow, startingCol, lastRow, lastCol);
	}

	return isolateConfirmation;
}

bool searchMidMidCell(int crossHatchArray[ROW][COL]) {
	//The mid mid cell consists of rows 3 - 5, and cols 3 - 5
	int startingRow = 3;
	int startingCol = 3;
	int lastRow = 5;
	int lastCol = 5;
	int numToSearchFor = 0;
	int countOfZeroes = 0;
	bool isolateConfirmation = false;

	for (int i = startingRow; i <= lastRow; i++) { //row count

		for (int j = startingCol; j < lastCol; j++) { //col count

			if (crossHatchArray[i][j] == numToSearchFor) {
				countOfZeroes += 1;
			}
		}
	}

	if (countOfZeroes == 1) {
		isolateConfirmation = true;
		searchForCoordinatesOfIsolate(crossHatchArray, startingRow, startingCol, lastRow, lastCol);
	}

	return isolateConfirmation;
}

bool searchMidRightCell(int crossHatchArray[ROW][COL]) {
	//The mid right cell consists of rows 3 - 5, and cols 6 - 8
	int startingRow = 3;
	int startingCol = 6;
	int lastRow = 5;
	int lastCol = 8;
	int numToSearchFor = 0;
	int countOfZeroes = 0;
	bool isolateConfirmation = false;

	for (int i = startingRow; i <= lastRow; i++) { //row count

		for (int j = startingCol; j < lastCol; j++) { //col count

			if (crossHatchArray[i][j] == numToSearchFor) {
				countOfZeroes += 1;
			}
		}
	}

	if (countOfZeroes == 1) {
		isolateConfirmation = true;
		searchForCoordinatesOfIsolate(crossHatchArray, startingRow, startingCol, lastRow, lastCol);
	}

	return isolateConfirmation;
}

bool searchBottomLeftCell(int crossHatchArray[ROW][COL]) {
	//The bottom left cell consists of rows 6 - 8, and cols 0 - 2
	int startingRow = 6;
	int startingCol = 0;
	int lastRow = 8;
	int lastCol = 2;
	int numToSearchFor = 0;
	int countOfZeroes = 0;
	bool isolateConfirmation = false;

	for (int i = startingRow; i <= lastRow; i++) { //row count

		for (int j = startingCol; j < lastCol; j++) { //col count

			if (crossHatchArray[i][j] == numToSearchFor) {
				countOfZeroes += 1;
			}
		}
	}

	if (countOfZeroes == 1) {
		isolateConfirmation = true;
		searchForCoordinatesOfIsolate(crossHatchArray, startingRow, startingCol, lastRow, lastCol);
	}

	return isolateConfirmation;
}

bool searchBottomMidCell(int crossHatchArray[ROW][COL]) {
	//The bottom mid cell consists of rows 6 - 8, and cols 3 - 5
	int startingRow = 6;
	int startingCol = 3;
	int lastRow = 8;
	int lastCol = 5;
	int numToSearchFor = 0;
	int countOfZeroes = 0;
	bool isolateConfirmation = false;

	for (int i = startingRow; i <= lastRow; i++) { //row count

		for (int j = startingCol; j < lastCol; j++) { //col count

			if (crossHatchArray[i][j] == numToSearchFor) {
				countOfZeroes += 1;
			}
		}
	}

	if (countOfZeroes == 1) {
		isolateConfirmation = true;
		searchForCoordinatesOfIsolate(crossHatchArray, startingRow, startingCol, lastRow, lastCol);
	}

	return isolateConfirmation;
}

bool searchBottomRightCell(int crossHatchArray[ROW][COL]) {
	//The bottom right cell consists of rows 6 - 8, and cols 6 - 8
	int startingRow = 6;
	int startingCol = 6;
	int lastRow = 8;
	int lastCol = 8;
	int numToSearchFor = 0;
	int countOfZeroes = 0;
	bool isolateConfirmation = false;

	for (int i = startingRow; i <= lastRow; i++) { //row count

		for (int j = startingCol; j < lastCol; j++) { //col count

			if (crossHatchArray[i][j] == numToSearchFor) {
				countOfZeroes += 1;
			}
		}
	}

	if (countOfZeroes == 1) {
		isolateConfirmation = true;
		searchForCoordinatesOfIsolate(crossHatchArray, startingRow, startingCol, lastRow, lastCol);
	}

	return isolateConfirmation;
}