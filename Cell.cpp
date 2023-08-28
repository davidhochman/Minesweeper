#include "Cell.h"
#include "Board.h"

Cell::Cell() {
	_unclickedSprite.setTexture(TextureManager::GetTexture("tile_hidden")); 
	_revealedSprite.setTexture(TextureManager::GetTexture("tile_revealed"));
	_mineSprite.setTexture(TextureManager::GetTexture("mine"));
	_flagSprite.setTexture(TextureManager::GetTexture("flag"));
	_1Sprite.setTexture(TextureManager::GetTexture("number_1"));
	_2Sprite.setTexture(TextureManager::GetTexture("number_2"));
	_3Sprite.setTexture(TextureManager::GetTexture("number_3"));
	_4Sprite.setTexture(TextureManager::GetTexture("number_4"));
	_5Sprite.setTexture(TextureManager::GetTexture("number_5"));
	_6Sprite.setTexture(TextureManager::GetTexture("number_6"));
	_7Sprite.setTexture(TextureManager::GetTexture("number_7"));
	_8Sprite.setTexture(TextureManager::GetTexture("number_8"));

	_notRevealed = true;
	_isFlagged = false;
	_hasMine = false;
	_inDebugMode = false;
	_adjacentMines = 0;
}

sf::Sprite& Cell::GetSprite() {
	if (_notRevealed) { return _unclickedSprite; }

	else { return _revealedSprite; }
}

void Cell::SetPosition(float x, float y) {
	_unclickedSprite.setPosition(x, y);
	_revealedSprite.setPosition(x, y);
	_mineSprite.setPosition(x, y);
	_flagSprite.setPosition(x, y);
	_1Sprite.setPosition(x, y);
	_2Sprite.setPosition(x, y);
	_3Sprite.setPosition(x, y);
	_4Sprite.setPosition(x, y);
	_5Sprite.setPosition(x, y);
	_6Sprite.setPosition(x, y);
	_7Sprite.setPosition(x, y);
	_8Sprite.setPosition(x, y);

}

void Cell::PrintCell(sf::RenderWindow& window, bool gameover, bool winner,  int& count) {

	if (_notRevealed) {
		 window.draw(_unclickedSprite); 
		 if (_isFlagged) { window.draw(_flagSprite); }
	}

	else {
		window.draw(_revealedSprite);
		if (_hasMine) { window.draw(_mineSprite); }

		else {

			if (_adjacentMines == 1) { window.draw(_1Sprite); }
			else if (_adjacentMines == 2) { window.draw(_2Sprite); }
			else if (_adjacentMines == 3) { window.draw(_3Sprite); }
			else if (_adjacentMines == 4) { window.draw(_4Sprite); }
			else if (_adjacentMines == 5) { window.draw(_5Sprite); }
			else if (_adjacentMines == 6) { window.draw(_6Sprite); }
			else if (_adjacentMines == 7) { window.draw(_7Sprite); }
			else if (_adjacentMines == 8) { window.draw(_8Sprite); }
		}

		
	}

	if (_inDebugMode) {
		if (_hasMine) { window.draw(_mineSprite); }
	}

	if (gameover) {
		if (_hasMine) { window.draw(_mineSprite); }
	}

	if (winner) {
		if (_hasMine && _notRevealed) {
			_isFlagged = true;
		}
	}

}

void Cell::ReadAdjacent(int i, int j, vector<vector<Cell>>& celllist) {
	if (i == 0) {
		if (j == 0) {
			if (celllist[i][j + 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i][j - 1].HasMine()) { _adjacentMines++; }
			if (celllist[i + 1][j + 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i + 1][j - 1].HasMine()) { _adjacentMines++; }
			if (celllist[i + 1][j].HasMine()) { _adjacentMines++; }
			//if (celllist[i - 1][j + 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i - 1][j - 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i - 1][j].HasMine()) { _adjacentMines++; }
		}

		else if (j == celllist[i].size() - 1) {
			//if (celllist[i][j + 1].HasMine()) { _adjacentMines++; }
			if (celllist[i][j - 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i + 1][j + 1].HasMine()) { _adjacentMines++; }
			if (celllist[i + 1][j - 1].HasMine()) { _adjacentMines++; }
			if (celllist[i + 1][j].HasMine()) { _adjacentMines++; }
			//if (celllist[i - 1][j + 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i - 1][j - 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i - 1][j].HasMine()) { _adjacentMines++; }
		}

		else {
			if (celllist[i][j + 1].HasMine()) { _adjacentMines++; }
			if (celllist[i][j - 1].HasMine()) { _adjacentMines++; }
			if (celllist[i + 1][j + 1].HasMine()) { _adjacentMines++; }
			if (celllist[i + 1][j - 1].HasMine()) { _adjacentMines++; }
			if (celllist[i + 1][j].HasMine()) { _adjacentMines++; }
			//if (celllist[i - 1][j + 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i - 1][j - 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i - 1][j].HasMine()) { _adjacentMines++; }
		}
	}

	else if (i == celllist.size()-1) {
		if (j == 0) {
			if (celllist[i][j + 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i][j - 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i + 1][j + 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i + 1][j - 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i + 1][j].HasMine()) { _adjacentMines++; }
			if (celllist[i - 1][j + 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i - 1][j - 1].HasMine()) { _adjacentMines++; }
			if (celllist[i - 1][j].HasMine()) { _adjacentMines++; }
		
		
		}

		else if (j == celllist[i].size()-1) {
			//if (celllist[i][j + 1].HasMine()) { _adjacentMines++; }
			if (celllist[i][j - 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i + 1][j + 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i + 1][j - 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i + 1][j].HasMine()) { _adjacentMines++; }
			//if (celllist[i - 1][j + 1].HasMine()) { _adjacentMines++; }
			if (celllist[i - 1][j - 1].HasMine()) { _adjacentMines++; }
			if (celllist[i - 1][j].HasMine()) { _adjacentMines++; }
		
		
		}

		else {
			if (celllist[i][j + 1].HasMine()) { _adjacentMines++; }
			if (celllist[i][j - 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i + 1][j + 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i + 1][j - 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i + 1][j].HasMine()) { _adjacentMines++; }
			if (celllist[i - 1][j + 1].HasMine()) { _adjacentMines++; }
			if (celllist[i - 1][j - 1].HasMine()) { _adjacentMines++; }
			if (celllist[i - 1][j].HasMine()) { _adjacentMines++; }
		
		

		}
	}

	else {
		if (j == 0) {
			if (celllist[i][j + 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i][j - 1].HasMine()) { _adjacentMines++; }
			if (celllist[i + 1][j + 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i + 1][j - 1].HasMine()) { _adjacentMines++; }
			if (celllist[i + 1][j].HasMine()) { _adjacentMines++; }
			if (celllist[i - 1][j + 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i - 1][j - 1].HasMine()) { _adjacentMines++; }
			if (celllist[i - 1][j].HasMine()) { _adjacentMines++; }
		
		
		}

		else if (j == celllist[i].size()-1) {
			//if (celllist[i][j + 1].HasMine()) { _adjacentMines++; }
			if (celllist[i][j - 1].HasMine()) { _adjacentMines++; }
			//if (celllist[i + 1][j + 1].HasMine()) { _adjacentMines++; }
			if (celllist[i + 1][j - 1].HasMine()) { _adjacentMines++; }
			if (celllist[i + 1][j].HasMine()) { _adjacentMines++; }
			//if (celllist[i - 1][j + 1].HasMine()) { _adjacentMines++; }
			if (celllist[i - 1][j - 1].HasMine()) { _adjacentMines++; }
			if (celllist[i - 1][j].HasMine()) { _adjacentMines++; }
		
		
		}

		else {
			if (celllist[i][j + 1].HasMine()) { _adjacentMines++; }
			if (celllist[i][j - 1].HasMine()) { _adjacentMines++; }
			if (celllist[i + 1][j + 1].HasMine()) { _adjacentMines++; }
			if (celllist[i + 1][j - 1].HasMine()) { _adjacentMines++; }
			if (celllist[i + 1][j].HasMine()) { _adjacentMines++; }
			if (celllist[i - 1][j + 1].HasMine()) { _adjacentMines++; }
			if (celllist[i - 1][j - 1].HasMine()) { _adjacentMines++; }
			if (celllist[i - 1][j].HasMine()) { _adjacentMines++; }
		
		
		}
	}
}


void Cell::LeftClick(int i, int j, vector<vector<Cell>>& celllist, Board& gameboard) {
	if (_hasMine && _isFlagged == false) {
		gameboard.EndGame();
		return;
	}

	if (_notRevealed && _isFlagged == false) {

		Reveal();

		if (_adjacentMines == 0 && _hasMine == false) {
			if (i == 0) {
				if (j == 0) {
					if (celllist[i][j + 1].HasMine() == false) { celllist[i][j + 1].LeftClick(i, j + 1, celllist, gameboard); }
					//if (celllist[i][j - 1].HasMine()) { _adjacentMines++; }
					if (celllist[i + 1][j + 1].HasMine() == false) { celllist[i + 1][j + 1].LeftClick(i + 1, j + 1, celllist, gameboard); }
					//if (celllist[i + 1][j - 1].HasMine()) { _adjacentMines++; }
					if (celllist[i + 1][j].HasMine() == false) { celllist[i + 1][j].LeftClick(i + 1, j, celllist, gameboard); }
					//if (celllist[i - 1][j + 1].HasMine()) { _adjacentMines++; }
					//if (celllist[i - 1][j - 1].HasMine()) { _adjacentMines++; }
					//if (celllist[i - 1][j].HasMine()) { _adjacentMines++; }
				}

				else if (j == celllist[i].size() - 1) {
					//if (celllist[i][j + 1].HasMine()) { _adjacentMines++; }
					if (celllist[i][j - 1].HasMine() == false) { celllist[i][j - 1].LeftClick(i, j - 1, celllist, gameboard); }
					//if (celllist[i + 1][j + 1].HasMine()) { _adjacentMines++; }
					if (celllist[i + 1][j - 1].HasMine() == false) { celllist[i + 1][j - 1].LeftClick(i + 1, j - 1, celllist, gameboard); }
					if (celllist[i + 1][j].HasMine() == false) { celllist[i + 1][j].LeftClick(i + 1, j, celllist, gameboard); }
					//if (celllist[i - 1][j + 1].HasMine()) { _adjacentMines++; }
					//if (celllist[i - 1][j - 1].HasMine()) { _adjacentMines++; }
					//if (celllist[i - 1][j].HasMine()) { _adjacentMines++; }
				}

				else {
					if (celllist[i][j + 1].HasMine() == false) { celllist[i][j + 1].LeftClick(i, j + 1, celllist, gameboard); }
					if (celllist[i][j - 1].HasMine() == false) { celllist[i][j - 1].LeftClick(i, j - 1, celllist, gameboard); }
					if (celllist[i + 1][j + 1].HasMine() == false) { celllist[i + 1][j + 1].LeftClick(i + 1, j + 1, celllist, gameboard); }
					if (celllist[i + 1][j - 1].HasMine() == false) { celllist[i + 1][j - 1].LeftClick(i + 1, j - 1, celllist, gameboard); }
					if (celllist[i + 1][j].HasMine() == false) { celllist[i + 1][j].LeftClick(i + 1, j, celllist, gameboard); }
					//if (celllist[i - 1][j + 1].HasMine()) { _adjacentMines++; }
					//if (celllist[i - 1][j - 1].HasMine()) { _adjacentMines++; }
					//if (celllist[i - 1][j].HasMine()) { _adjacentMines++; }
				}
			}

			else if (i == celllist.size() - 1) {
				if (j == 0) {
					if (celllist[i][j + 1].HasMine() == false) { celllist[i][j + 1].LeftClick(i, j + 1, celllist, gameboard); }
					//if (celllist[i][j - 1].HasMine()) { _adjacentMines++; }
					//if (celllist[i + 1][j + 1].HasMine()) { _adjacentMines++; }
					//if (celllist[i + 1][j - 1].HasMine()) { _adjacentMines++; }
					//if (celllist[i + 1][j].HasMine()) { _adjacentMines++; }
					if (celllist[i - 1][j + 1].HasMine() == false) { celllist[i - 1][j + 1].LeftClick(i - 1, j + 1, celllist, gameboard); }
					//if (celllist[i - 1][j - 1].HasMine()) { _adjacentMines++; }
					if (celllist[i - 1][j].HasMine() == false) { celllist[i - 1][j].LeftClick(i - 1, j, celllist, gameboard); }
				}

				else if (j == celllist[i].size() - 1) {
					//if (celllist[i][j + 1].HasMine()) { _adjacentMines++; }
					if (celllist[i][j - 1].HasMine() == false) { celllist[i][j - 1].LeftClick(i, j - 1, celllist, gameboard); }
					//if (celllist[i + 1][j + 1].HasMine()) { _adjacentMines++; }
					//if (celllist[i + 1][j - 1].HasMine()) { _adjacentMines++; }
					//if (celllist[i + 1][j].HasMine()) { _adjacentMines++; }
					//if (celllist[i - 1][j + 1].HasMine()) { _adjacentMines++; }
					if (celllist[i - 1][j - 1].HasMine() == false) { celllist[i - 1][j - 1].LeftClick(i - 1, j - 1, celllist, gameboard); }
					if (celllist[i - 1][j].HasMine() == false) { celllist[i - 1][j].LeftClick(i - 1, j, celllist, gameboard); }
				}

				else {
					if (celllist[i][j + 1].HasMine() == false) { celllist[i][j + 1].LeftClick(i, j + 1, celllist, gameboard); }
					if (celllist[i][j - 1].HasMine() == false) { celllist[i][j - 1].LeftClick(i, j - 1, celllist, gameboard); }
					//if (celllist[i + 1][j + 1].HasMine()) { _adjacentMines++; }
					//if (celllist[i + 1][j - 1].HasMine()) { _adjacentMines++; }
					//if (celllist[i + 1][j].HasMine()) { _adjacentMines++; }
					if (celllist[i - 1][j + 1].HasMine() == false) { celllist[i - 1][j + 1].LeftClick(i - 1, j + 1, celllist, gameboard); }
					if (celllist[i - 1][j - 1].HasMine() == false) { celllist[i - 1][j - 1].LeftClick(i - 1, j - 1, celllist, gameboard); }
					if (celllist[i - 1][j].HasMine() == false) { celllist[i - 1][j].LeftClick(i - 1, j, celllist, gameboard); }
				}
			}

			else {
				if (j == 0) {
					if (celllist[i][j + 1].HasMine() == false) { celllist[i][j + 1].LeftClick(i, j + 1, celllist, gameboard); }
					//if (celllist[i][j - 1].HasMine()) { _adjacentMines++; }
					if (celllist[i + 1][j + 1].HasMine() == false) { celllist[i + 1][j + 1].LeftClick(i + 1, j + 1, celllist, gameboard); }
					//if (celllist[i + 1][j - 1].HasMine()) { _adjacentMines++; }
					if (celllist[i + 1][j].HasMine() == false) { celllist[i + 1][j].LeftClick(i + 1, j, celllist, gameboard); }
					if (celllist[i - 1][j + 1].HasMine() == false) { celllist[i - 1][j + 1].LeftClick(i - 1, j + 1, celllist, gameboard); }
					//if (celllist[i - 1][j - 1].HasMine()) { _adjacentMines++; }
					if (celllist[i - 1][j].HasMine() == false) { celllist[i - 1][j].LeftClick(i - 1, j, celllist, gameboard); }


				}

				else if (j == celllist[i].size() - 1) {
					//if (celllist[i][j + 1].HasMine()) { _adjacentMines++; }
					if (celllist[i][j - 1].HasMine() == false) { celllist[i][j - 1].LeftClick(i, j - 1, celllist, gameboard); }
					//if (celllist[i + 1][j + 1].HasMine()) { _adjacentMines++; }
					if (celllist[i + 1][j - 1].HasMine() == false) { celllist[i + 1][j - 1].LeftClick(i + 1, j - 1, celllist, gameboard); }
					if (celllist[i + 1][j].HasMine() == false) { celllist[i + 1][j].LeftClick(i + 1, j, celllist, gameboard); }
					//if (celllist[i - 1][j + 1].HasMine()) { _adjacentMines++; }
					if (celllist[i - 1][j - 1].HasMine() == false) { celllist[i - 1][j - 1].LeftClick(i - 1, j - 1, celllist, gameboard); }
					if (celllist[i - 1][j].HasMine() == false) { celllist[i - 1][j].LeftClick(i - 1, j, celllist, gameboard); }


				}

				else {
					if (celllist[i][j + 1].HasMine() == false) { celllist[i][j + 1].LeftClick(i, j + 1, celllist, gameboard); }
					if (celllist[i][j - 1].HasMine() == false) { celllist[i][j - 1].LeftClick(i, j - 1, celllist, gameboard); }
					if (celllist[i + 1][j + 1].HasMine() == false) { celllist[i + 1][j + 1].LeftClick(i + 1, j + 1, celllist, gameboard); }
					if (celllist[i + 1][j - 1].HasMine() == false) { celllist[i + 1][j - 1].LeftClick(i + 1, j - 1, celllist, gameboard); }
					if (celllist[i + 1][j].HasMine() == false) { celllist[i + 1][j].LeftClick(i + 1, j, celllist, gameboard); }
					if (celllist[i - 1][j + 1].HasMine() == false) { celllist[i - 1][j + 1].LeftClick(i - 1, j + 1, celllist, gameboard); }
					if (celllist[i - 1][j - 1].HasMine() == false) { celllist[i - 1][j - 1].LeftClick(i - 1, j - 1, celllist, gameboard); }
					if (celllist[i - 1][j].HasMine() == false) { celllist[i - 1][j].LeftClick(i - 1, j, celllist, gameboard); }


				}
			}

		}
	}

}

void Cell::RightClick(Board& gameboard) {
	if (_notRevealed) {
		if (_isFlagged) { 
			_isFlagged = false; 
			gameboard.IncrementMinecount();
		
		}
		else {
			_isFlagged = true;
			gameboard.DecrementMinecount();
		}
	}
}

bool Cell::HasMine() {
	if (_hasMine) { return true; }
	return false;
}

void Cell::AddMine() {
	_hasMine = true;
}

void Cell::RemoveMine() {
	_hasMine = false;
}

void Cell::Reveal() {
	_notRevealed = false;
}

void Cell::UnReveal() {
	_notRevealed = true;
}

void Cell::ResetAdjacent() {
	_adjacentMines = 0;
}

bool Cell::IsRevealed() {
	if (_notRevealed) { return false; }
	else { return true; }
}

void Cell::RemoveFlag() {
	_isFlagged = false;
}