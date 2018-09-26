#pragma once

#include "Player.h"

class Game
{
private:
	sf::RenderWindow * window;

	//Text
	sf::Font font;
	std::vector<sf::Text> followPlayerTexts;
	std::vector <sf::Text> staticPlayerTexts;
	sf::Texture playerTexture;
	sf::Texture bullet_texture;

	std::vector<Player> players;

public:
	Game(sf::RenderWindow* window);
	virtual ~Game();

	sf::RenderWindow& getWindow() { return *this->window; };

	void DrawUI();
	void InitUI();
	void UpdateUI();
	void Update();
	void Draw();
};