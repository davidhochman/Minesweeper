#include "counter.h"
//#include "board.h"

Counter::Counter(int rows, int mines) {
	_rows = rows;
	_minecount = mines;


	_digit1.setPosition(28, rows * 32 + 5);
	_digit2.setPosition(39, rows * 32 + 5);
	_digit3.setPosition(60, rows * 32 + 5);
	_digit4.setPosition(81, rows * 32 + 5);

	_digit1.setTexture(TextureManager::GetDigitNeg());

	
	if (mines % 10 == 0) { _digit4.setTexture(TextureManager::GetDigit0()); }
	else if (mines % 10 == 1 || mines % 10 == -1) { _digit4.setTexture(TextureManager::GetDigit1()); }
	else if (mines % 10 == 2 || mines % 10 == -2) { _digit4.setTexture(TextureManager::GetDigit2()); }
	else if (mines % 10 == 3 || mines % 10 == -3) { _digit4.setTexture(TextureManager::GetDigit3()); }
	else if (mines % 10 == 4 || mines % 10 == -4) { _digit4.setTexture(TextureManager::GetDigit4()); }
	else if (mines % 10 == 5 || mines % 10 == -5) { _digit4.setTexture(TextureManager::GetDigit5()); }
	else if (mines % 10 == 6 || mines % 10 == -6) { _digit4.setTexture(TextureManager::GetDigit6()); }
	else if (mines % 10 == 7 || mines % 10 == -7) { _digit4.setTexture(TextureManager::GetDigit7()); }
	else if (mines % 10 == 8 || mines % 10 == -8) { _digit4.setTexture(TextureManager::GetDigit8()); }
	else if (mines % 10 == 9 || mines % 10 == -9) { _digit4.setTexture(TextureManager::GetDigit9()); }

	if (mines/10 == 0) { _digit3.setTexture(TextureManager::GetDigit0()); }
	else if (mines/10 == 1 || mines / 10 == -1) { _digit3.setTexture(TextureManager::GetDigit1()); }
	else if (mines/10 == 2 || mines / 10 == -2) { _digit3.setTexture(TextureManager::GetDigit2()); }
	else if (mines/10 == 3 || mines / 10 == -3) { _digit3.setTexture(TextureManager::GetDigit3()); }
	else if (mines/10 == 4 || mines / 10 == -4) { _digit3.setTexture(TextureManager::GetDigit4()); }
	else if (mines/10 == 5 || mines / 10 == -5) { _digit3.setTexture(TextureManager::GetDigit5()); }
	else if (mines/10 == 6 || mines / 10 == -6) { _digit3.setTexture(TextureManager::GetDigit6()); }
	else if (mines/10 == 7 || mines / 10 == -7) { _digit3.setTexture(TextureManager::GetDigit7()); }
	else if (mines/10 == 8 || mines / 10 == -8) { _digit3.setTexture(TextureManager::GetDigit8()); }
	else if (mines/10 == 9 || mines / 10 == -9) { _digit3.setTexture(TextureManager::GetDigit9()); }

	if (mines / 100 == 0) { _digit2.setTexture(TextureManager::GetDigit0()); }
	else if (mines / 100 == 1 || mines / 100 == -1) { _digit2.setTexture(TextureManager::GetDigit1()); }
	else if (mines / 100 == 2 || mines / 100 == -2) { _digit2.setTexture(TextureManager::GetDigit2()); }
	else if (mines / 100 == 3 || mines / 100 == -3) { _digit2.setTexture(TextureManager::GetDigit3()); }
	else if (mines / 100 == 4 || mines / 100 == -4) { _digit2.setTexture(TextureManager::GetDigit4()); }
	else if (mines / 100 == 5 || mines / 100 == -5) { _digit2.setTexture(TextureManager::GetDigit5()); }
	else if (mines / 100 == 6 || mines / 100 == -6) { _digit2.setTexture(TextureManager::GetDigit6()); }
	else if (mines / 100 == 7 || mines / 100 == -7) { _digit2.setTexture(TextureManager::GetDigit7()); }
	else if (mines / 100 == 8 || mines / 100 == -8) { _digit2.setTexture(TextureManager::GetDigit8()); }
	else if (mines / 100 == 9 || mines / 100 == -9) { _digit2.setTexture(TextureManager::GetDigit9()); }
}

void Counter::Update(int mines) {

	if (mines % 10 == 0) { _digit4.setTexture(TextureManager::GetDigit0()); }
	else if (mines % 10 == 1 || mines % 10 == -1) { _digit4.setTexture(TextureManager::GetDigit1()); }
	else if (mines % 10 == 2 || mines % 10 == -2) { _digit4.setTexture(TextureManager::GetDigit2()); }
	else if (mines % 10 == 3 || mines % 10 == -3) { _digit4.setTexture(TextureManager::GetDigit3()); }
	else if (mines % 10 == 4 || mines % 10 == -4) { _digit4.setTexture(TextureManager::GetDigit4()); }
	else if (mines % 10 == 5 || mines % 10 == -5) { _digit4.setTexture(TextureManager::GetDigit5()); }
	else if (mines % 10 == 6 || mines % 10 == -6) { _digit4.setTexture(TextureManager::GetDigit6()); }
	else if (mines % 10 == 7 || mines % 10 == -7) { _digit4.setTexture(TextureManager::GetDigit7()); }
	else if (mines % 10 == 8 || mines % 10 == -8) { _digit4.setTexture(TextureManager::GetDigit8()); }
	else if (mines % 10 == 9 || mines % 10 == -9) { _digit4.setTexture(TextureManager::GetDigit9()); }

	if (mines / 10 == 0) { _digit3.setTexture(TextureManager::GetDigit0()); }
	else if (mines / 10 == 1 || mines / 10 == -1) { _digit3.setTexture(TextureManager::GetDigit1()); }
	else if (mines / 10 == 2 || mines / 10 == -2) { _digit3.setTexture(TextureManager::GetDigit2()); }
	else if (mines / 10 == 3 || mines / 10 == -3) { _digit3.setTexture(TextureManager::GetDigit3()); }
	else if (mines / 10 == 4 || mines / 10 == -4) { _digit3.setTexture(TextureManager::GetDigit4()); }
	else if (mines / 10 == 5 || mines / 10 == -5) { _digit3.setTexture(TextureManager::GetDigit5()); }
	else if (mines / 10 == 6 || mines / 10 == -6) { _digit3.setTexture(TextureManager::GetDigit6()); }
	else if (mines / 10 == 7 || mines / 10 == -7) { _digit3.setTexture(TextureManager::GetDigit7()); }
	else if (mines / 10 == 8 || mines / 10 == -8) { _digit3.setTexture(TextureManager::GetDigit8()); }
	else if (mines / 10 == 9 || mines / 10 == -9) { _digit3.setTexture(TextureManager::GetDigit9()); }

	if (mines / 100 == 0) { _digit2.setTexture(TextureManager::GetDigit0()); }
	else if (mines / 100 == 1 || mines / 100 == -1) { _digit2.setTexture(TextureManager::GetDigit1()); }
	else if (mines / 100 == 2 || mines / 100 == -2) { _digit2.setTexture(TextureManager::GetDigit2()); }
	else if (mines / 100 == 3 || mines / 100 == -3) { _digit2.setTexture(TextureManager::GetDigit3()); }
	else if (mines / 100 == 4 || mines / 100 == -4) { _digit2.setTexture(TextureManager::GetDigit4()); }
	else if (mines / 100 == 5 || mines / 100 == -5) { _digit2.setTexture(TextureManager::GetDigit5()); }
	else if (mines / 100 == 6 || mines / 100 == -6) { _digit2.setTexture(TextureManager::GetDigit6()); }
	else if (mines / 100 == 7 || mines / 100 == -7) { _digit2.setTexture(TextureManager::GetDigit7()); }
	else if (mines / 100 == 8 || mines / 100 == -8) { _digit2.setTexture(TextureManager::GetDigit8()); }
	else if (mines / 100 == 9 || mines / 100 == -9) { _digit2.setTexture(TextureManager::GetDigit9()); }
}

sf::Sprite& Counter::GetSprite1() {
	return _digit1;
}

sf::Sprite& Counter::GetSprite2() {
	return _digit2;
}

sf::Sprite& Counter::GetSprite3() {
	return _digit3;
}

sf::Sprite& Counter::GetSprite4() {
	return _digit4;
}