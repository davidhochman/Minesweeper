#pragma once
#include "TextureManager.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "Random.h"
#include "Cell.h"
#include "Button.h"
#include "Counter.h"

using namespace std;

class Board {
	int _rows;
	int _cols;
	int _originalminecount;
	int _tempminecount;
	vector<vector<Cell>> _cellList;
	bool _gameOver;
	bool _isWinner;
	
public:
	Button _faceButton;
	Button _test1Button;
	Button _test2Button;
	Button _test3Button;
	Button _debugButton;
	

	Counter _counter;

	void PrintBoard(sf::RenderWindow& window);
	Board(int rows, int cols, int minecount);
	Cell& GetCell(int i, int j);
	void DebugMode();
	vector<vector<Cell>>& GetList();
	bool IsGameOver();
	void EndGame();
	void Reset();
	void LoadTest(string filename);
	void CheckForWinner();
	bool IsWinner();
	void DecrementMinecount();
	void IncrementMinecount();
	void PrintCounter(sf::RenderWindow& window);
	void UpdateCounter();

};