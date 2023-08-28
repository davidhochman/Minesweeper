#pragma once
#include <SFML/Graphics.hpp>
#include <string>

#include "TextureManager.h"

//class Board;

class Counter {
	sf::Sprite _digit1;
	sf::Sprite _digit2;
	sf::Sprite _digit3;
	sf::Sprite _digit4;	

	int _rows;
	int _minecount;

public:
	Counter(int rows, int mines);
	sf::Sprite& GetSprite1();
	sf::Sprite& GetSprite2();
	sf::Sprite& GetSprite3();
	sf::Sprite& GetSprite4();
	void Update(int mines);

};
