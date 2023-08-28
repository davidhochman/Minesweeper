#pragma once
#include <vector>
#include "TextureManager.h"
using namespace std;

class Board;

class Cell {
	sf::Sprite _unclickedSprite;
	sf::Sprite _revealedSprite;
	sf::Sprite _mineSprite;
	sf::Sprite _flagSprite;
	sf::Sprite _1Sprite;
	sf::Sprite _2Sprite;
	sf::Sprite _3Sprite;
	sf::Sprite _4Sprite;
	sf::Sprite _5Sprite;
	sf::Sprite _6Sprite;
	sf::Sprite _7Sprite;
	sf::Sprite _8Sprite;

	bool _notRevealed;
	bool _isFlagged;
	bool _hasMine;
	int _adjacentMines;

public:
	Cell();
	sf::Sprite& GetSprite();
	void SetPosition(float x, float y);
	void PrintCell(sf::RenderWindow& window, bool gameover, bool winner, int& count);
	void LeftClick(int i, int j, vector<vector<Cell>>& celllist, Board& gameboard);
	void RightClick(Board& gameboard);
	bool HasMine();
	void AddMine();
	void RemoveMine();
	void ReadAdjacent(int i, int j, vector<vector<Cell>>& celllist);
	void ResetAdjacent();
	void Reveal();
	void UnReveal();
	bool IsRevealed();
	void RemoveFlag();

	bool _inDebugMode;
};