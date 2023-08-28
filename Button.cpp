#include "Button.h"
#include "Board.h"

Button::Button(string filename) {
	_buttonSprite.setTexture(TextureManager::GetTexture(filename));
	_loseSprite.setTexture(TextureManager::GetTexture("face_lose"));
	_winSprite.setTexture(TextureManager::GetTexture("face_win"));

}

void Button::SetPosition(float x, float y) {
	_buttonSprite.setPosition(x, y);
	_loseSprite.setPosition(x, y);
	_winSprite.setPosition(x, y);
}

sf::Sprite& Button::GetSprite() {
	return _buttonSprite;
}

sf::Sprite& Button::GetFaceSprite(bool gamelost, bool gamewon) {
	if (gamelost) { return _loseSprite; }
	else if (gamewon) { return _winSprite; }
	return _buttonSprite;
}

void Button::CreateFace() {
	_isFace = true;
}


void Button::LeftClick() {

}