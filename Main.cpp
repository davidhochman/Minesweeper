//#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

#include "TextureManager.h"
#include "Board.h"

using namespace std;

int main() {
    string line;
    int cols;
    int rows;
    int minecount;

    ifstream inFile("boards/config.cfg");

    getline(inFile, line);
    cols = stoi(line);

    getline(inFile, line);
    rows = stoi(line);

    getline(inFile, line);
    minecount = stoi(line);

    sf::RenderWindow window(sf::VideoMode(cols*32, rows*32+100), "Minesweeper");

    Board gameboard(rows, cols, minecount);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {

                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                if (event.mouseButton.button == sf::Mouse::Left) {

                    for (int i = 0; i < rows; i++) {

                        for (int j = 0; j < cols; j++) {
                            if (gameboard.GetCell(i, j).GetSprite().getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                                gameboard.GetCell(i, j).LeftClick(i, j, gameboard.GetList(), gameboard);
                            }
                        }
                    }

                    if (gameboard._debugButton.GetSprite().getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        gameboard.DebugMode();
                    }

                    if (gameboard._test1Button.GetSprite().getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        gameboard.LoadTest("boards/testboard1.brd");
                    }

                    if (gameboard._test2Button.GetSprite().getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        gameboard.LoadTest("boards/testboard2.brd");
                    }

                    if (gameboard._test3Button.GetSprite().getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        gameboard.LoadTest("boards/testboard3.brd");
                    }

                    if (gameboard._faceButton.GetFaceSprite(gameboard.IsGameOver(), gameboard.IsWinner()).getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        gameboard.Reset();

                    }
                    
                }

                if (event.mouseButton.button == sf::Mouse::Right) {
                    for (int i = 0; i < rows; i++) {

                        for (int j = 0; j < cols; j++) {
                            if (gameboard.GetCell(i, j).GetSprite().getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                                gameboard.GetCell(i, j).RightClick(gameboard);
                            }
                        }
                    }
                }
            }
        }

        window.clear();
        gameboard.CheckForWinner();
        gameboard.UpdateCounter();
        gameboard.PrintBoard(window);
        gameboard.PrintCounter(window);
        
        window.display();
    }

    return 0;
}