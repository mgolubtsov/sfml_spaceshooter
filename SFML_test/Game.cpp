#include "Game.h"

Game::Game(sf::RenderWindow* window)
{
	this->window = window;
	this->window->setFramerateLimit(60);

	this->font.loadFromFile("Fonts/Dosis-Light.ttf");

	this->playerTexture.loadFromFile("Textures/ship.png");
	this->bullet_texture.loadFromFile("Textures/Guns/missileTex01.png");

	this->players.push_back(Player(&playerTexture, &bullet_texture));
	
	/*this->players.push_back(Player(&playerTexture, &bullet_texture, 
		sf::Keyboard::I, sf::Keyboard::K, sf::Keyboard::J, sf::Keyboard::L, sf::Keyboard::RShift));*/
	this->InitUI();
}


Game::~Game()
{
	
}

void Game::InitUI()
{
	for (size_t i = 0; i < this->players.size(); i++)
	{
		//FollowTextInit
		sf::Text tempText;
		tempText.setCharacterSize(12);
		tempText.setFillColor(sf::Color::White);
		tempText.setFont(font);
		tempText.setString(std::to_string(i));

		this->followPlayerTexts.push_back(sf::Text(tempText));

		//StaticTextInit
		tempText.setCharacterSize(12);
		tempText.setFillColor(sf::Color::White);
		tempText.setFont(font);
		tempText.setString("");
		
		this->staticPlayerTexts.push_back(sf::Text(tempText));
	}
}

void Game::UpdateUI()
{
	for (size_t i = 0; i < this->followPlayerTexts.size(); i++)
	{
		this->followPlayerTexts[i].setPosition(this->players[i].getPosition());
		this->followPlayerTexts[i].setString(std::to_string(i) + " | " + this->players[i].getHpAsString());
	}

	for (size_t i = 0; i < this->staticPlayerTexts.size(); i++)
	{
		
	}
}

void Game::DrawUI()
{
	for (size_t i = 0; i < this->followPlayerTexts.size(); i++)
	{
		this->window->draw(this->followPlayerTexts[i]);
	}

	for (size_t i = 0; i < this->staticPlayerTexts.size(); i++)
	{
		this->window->draw(this->staticPlayerTexts[i]);
	}
}

void Game::Update() 
{
	for (size_t i = 0; i < this->players.size(); i++)
	{
		//Update players
		this->players[i].Update(this->window->getSize());

		for (size_t k = 0; k < this->players[i].getBullets().size(); k++)
		{
			this->players[i].getBullets()[k].Update();
			//window bounce check
			if (this->players[i].getBullets()[k].getPosition().x > this->window->getSize().x)
			{
				this->players[i].getBullets().erase(this->players[i].getBullets().begin() + k);
				break;
			}

			//Enemy collision check
		}
	}

	//UPDATE UI
	this->UpdateUI();
	//this->InitUI();
}

void Game::Draw()
{
	this->window->clear();
	

	for (size_t i = 0; i < this->players.size(); i++)
	{
		this->players[i].Draw(*this->window);
	}

	this->DrawUI();

	this->window->display();
}