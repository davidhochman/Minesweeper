#include "Board.h"


Board::Board(int rows, int cols, int minecount) : _faceButton("face_happy"), _test1Button("test_1"), 
_test2Button("test_2"), _test3Button("test_3"), _debugButton("debug"), _counter(rows, minecount) {

	_gameOver = false;
	_isWinner = false;
	_rows = rows;
	_cols = cols;
	_originalminecount = minecount;
	_tempminecount = minecount;

	//_countDigit1.SetPosition(28, _rows * 32);
	//_countDigit2.SetPosition(28 + 21, _rows * 32);
	//_countDigit3.SetPosition(28 + 42, _rows * 32);
	//_countDigit4.SetPosition(28 + 63, _rows * 32);

	_faceButton.SetPosition(_cols * 14, _rows * 32);
	_debugButton.SetPosition(_cols * 14 + 128, _rows * 32);
	_test1Button.SetPosition(_cols * 14 + 192, _rows * 32);
	_test2Button.SetPosition(_cols * 14 + 256, _rows * 32);
	_test3Button.SetPosition(_cols * 14 + 320, _rows * 32);

	_faceButton.CreateFace();
	
	for (int i = 0; i < _rows; i++) {
		vector<Cell> tempvec;

		for (int j = 0; j < _cols; j++) {
			Cell temp;
			temp.SetPosition(j * 32, i * 32);
			tempvec.push_back(temp);
		}
		
		_cellList.push_back(tempvec);
	}

	int tempcount = _originalminecount;
	while (tempcount > 0) {
		int i = Random::randomNum(0, _rows-1);
		int j = Random::randomNum(0, _cols-1);

		if (_cellList[i][j].HasMine() == false) {
			_cellList[i][j].AddMine();
			tempcount--;
		}
	}

	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			_cellList[i][j].ReadAdjacent(i, j, _cellList);
		}
	}
}

void Board::PrintBoard(sf::RenderWindow& window) {

	for (int i = 0; i < _rows; i++) {
		
		for (int j = 0; j < _cols; j++) {
			_cellList[i][j].PrintCell(window, _gameOver, _isWinner, _tempminecount);
		}
	}

	//window.draw(_countDigit1.GetSprite());
	window.draw(_faceButton.GetFaceSprite(_gameOver, _isWinner));
	window.draw(_debugButton.GetSprite());
	window.draw(_test1Button.GetSprite());
	window.draw(_test2Button.GetSprite());
	window.draw(_test3Button.GetSprite());


}


Cell& Board::GetCell(int i, int j) {
	return _cellList[i][j];
}

void Board::DebugMode() {
	for (int i = 0; i < _rows; i++) {

		for (int j = 0; j < _cols; j++) {
			if (_cellList[i][j]._inDebugMode) { _cellList[i][j]._inDebugMode = false; }
			else { _cellList[i][j]._inDebugMode = true; }
		}
	}

}

vector<vector<Cell>>& Board::GetList() {
	return _cellList;
}

bool Board::IsGameOver() {
	if (_gameOver) { return true; }
	return false;
}

void Board::EndGame() {
	_gameOver = true;
	for (int i = 0; i < _rows; i++) {

		for (int j = 0; j < _cols; j++) {
			_cellList[i][j].Reveal();
		}
	}
}

void Board::Reset() {
	_isWinner = false;
	_gameOver = false;
	_tempminecount = _originalminecount;

	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			_cellList[i][j].UnReveal();
			_cellList[i][j].RemoveMine();
			_cellList[i][j].RemoveFlag();
			_cellList[i][j].ResetAdjacent();

		}
	}

	int tempcount = _tempminecount;
	while (tempcount > 0) {
		int i = Random::randomNum(0, _rows - 1);
		int j = Random::randomNum(0, _cols - 1);

		if (_cellList[i][j].HasMine() == false) {
			_cellList[i][j].AddMine();
			tempcount--;
		}
	}

	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			_cellList[i][j].ReadAdjacent(i, j, _cellList);
		}
	}
}

void Board::LoadTest(string filename) {
	_tempminecount = 0;
	_gameOver = false;
	_isWinner = false;

	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			_cellList[i][j].UnReveal();
			_cellList[i][j].RemoveMine();
			_cellList[i][j].RemoveFlag();
			_cellList[i][j].ResetAdjacent();
		}
	}


	ifstream inFile(filename);

	if (inFile.is_open()) {

		int i = 0;
		string values;
		while (getline(inFile, values)) {

			for (int j = 0; j < values.size(); j++) {
				bool mine;

				if (values[j] == '1') { mine = true; }
				else { mine = false; }

				if (mine) { 
					_cellList[i][j].AddMine(); 
					_tempminecount++;
				}
			}

			i++;
		}

	}

	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			_cellList[i][j].ReadAdjacent(i, j, _cellList);
		}
	}
}

void Board::CheckForWinner() {
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			if (_cellList[i][j].HasMine() == false && _cellList[i][j].IsRevealed() == false) {
				return;
			}
		}
	}

	if (_gameOver == false) { _isWinner = true; }

	if (_isWinner) { _tempminecount = 0; }

}

bool Board::IsWinner() {
	return _isWinner;
}

void Board::DecrementMinecount() {
	_tempminecount--;
}

void Board::IncrementMinecount() {
	_tempminecount++;
}

void Board::PrintCounter(sf::RenderWindow& window) {
	if (_tempminecount < 0) { window.draw(_counter.GetSprite1()); }

	window.draw(_counter.GetSprite2());
	window.draw(_counter.GetSprite3());
	window.draw(_counter.GetSprite4());
}

void Board::UpdateCounter() {
	_counter.Update(_tempminecount);
}