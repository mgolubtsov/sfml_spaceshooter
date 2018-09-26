#pragma once

#include "Bullet.h"

class Player
{
private:
	unsigned int playerNr;

	sf::Vector2f playerCenter;
	
	int shootTimer;
	int damageTimer;
	int shootTimerMax;
	int damageTimerMax;

	sf::Texture *texture;
	sf::Texture *bullet_texture;
	sf::Sprite sprite;
	sf::RectangleShape hitBox;

	std::vector<Bullet> bullets;

	int controls[5];

	int level;
	int exp;
	int expNext;
	int HP;
	int hpMax;

	int damage;
	int damageMax;

	int score;

public:
	Player(sf::Texture* texture, sf::Texture *bullet_texture,
		int UP = 22, int DOWN = 18, 
		int LEFT = 0, int RIGHT = 3, 
		int SHOOT = 57);
	virtual ~Player();

	void Combat();
	void Movement();
	void Draw(sf::RenderTarget& target);
	void Update(sf::Vector2u windowBounds);
	

	std::vector<Bullet>& getBullets() { return this->bullets; };
	const sf::Vector2f& getPosition() const { return this->sprite.getPosition(); };
	const sf::String getHpAsString() const { return std::to_string(this->HP) + "/" + std::to_string(this->hpMax); }
	//Statics
	static unsigned players;
};