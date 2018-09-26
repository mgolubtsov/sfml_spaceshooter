#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Bullet
{
private:
	sf::Texture* texture;
	sf::Sprite sprite;

	sf::Vector2f currentVelocity;
	float maxVelocity;
	float acceleration;
	sf::Vector2f direction;

public:
	Bullet(sf::Texture *texture, sf::Vector2f position,
		sf::Vector2f direction, float initialVelocity,
		float maxVelocity,  
		float acceleration);
	virtual ~Bullet();

	const sf::FloatRect& getGlobalBounds() const { return this->sprite.getGlobalBounds(); };
	const sf::Vector2f& getPosition() const { return this->sprite.getPosition(); };

	void Movement();

	void Update();
	void Draw(sf::RenderTarget &target);
};

