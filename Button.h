#pragma once
#include "TextureManager.h"

class Board;

class Button {
	sf::Sprite _buttonSprite;
	sf::Sprite _loseSprite;
	sf::Sprite _winSprite;
	bool _isFace;
	bool _isCounter;

public:
	Button(string filename);
	void SetPosition(float x, float y);
	sf::Sprite& GetSprite();
	sf::Sprite& GetFaceSprite(bool gamelost, bool gamewon);
	void CreateFace();
	void LeftClick();
	void CreateCounter(int digit);

};
