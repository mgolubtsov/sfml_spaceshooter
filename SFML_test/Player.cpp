#include "Player.h"

unsigned Player::players = 0;

enum controls { UP = 0, DOWN, LEFT, RIGHT, SHOOT };

Player::Player(sf::Texture* texture, sf::Texture *bullet_texture,
				int UP, int DOWN,
				int LEFT, int RIGHT, 
				int SHOOT)
	:	level(1), exp(0), expNext(100), HP(10), hpMax(10),
		damage(1), damageMax(2), score (0)
{
	this->texture = texture;
	this->sprite.setTexture(*this->texture);
	this->bullet_texture = bullet_texture;
	this->sprite.setScale(0.13f, 0.13f);

	this->shootTimerMax = 25;
	this->shootTimer = this->shootTimerMax;
	this->damageTimer = 10;
	this->damageTimer = this->damageTimerMax;

	this->controls[controls::UP] = UP;
	this->controls[controls::DOWN] = DOWN;
	this->controls[controls::LEFT] = LEFT;
	this->controls[controls::RIGHT] = RIGHT;
	this->controls[controls::SHOOT] = SHOOT;

	//Player::playerNr++;
	this->playerNr = Player::players;
	Player::players++;

	//std::cout << this->playerNr << "\n";
}



Player::~Player()
{

}


void Player::Movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->controls[controls::UP])))
	{
		this->sprite.move(0.f, -10.f);
		std::cout << "w" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->controls[controls::DOWN])))
	{
		this->sprite.move(0.f, 10.f);
		std::cout << "s" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->controls[controls::LEFT])))
	{
		this->sprite.move(-10.f, 0.f);
		std::cout << "a" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->controls[controls::RIGHT])))
	{
		this->sprite.move(10.f, 0.f);
		std::cout << "d" << std::endl;
	}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->controls[controls::SHOOT])) && this->shootTimer >= this->shootTimerMax)
	{
		this->bullets.push_back(Bullet(bullet_texture, this->sprite.getPosition()));
		std::cout << "shoot" << std::endl;
	}*/
}

void Player::Draw(sf::RenderTarget& target)
{
	for (size_t i = 0; i < this->bullets.size(); i++)
	{
		this->bullets[i].Draw(target);
	}

	target.draw(this->sprite);
}

void Player::Combat()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->controls[controls::SHOOT])) && this->shootTimer >= this->shootTimerMax)
	{
		this->bullets.push_back(Bullet(bullet_texture, 
			this->playerCenter, 
			sf::Vector2f(1.f, 0.f), 5.f, 
			35.f, 0.5f));
		std::cout << "shoot" << std::endl;

		this->shootTimer = 0;
	}
}

void Player::Update(sf::Vector2u windowBounds)
{
	if (this->shootTimer < this->shootTimerMax)
		this->shootTimer++;

	if (this->damageTimer < this->damageTimerMax)
		this->damageTimer++;
	
	//Update Position
	this->playerCenter.x = this->sprite.getPosition().x + 
		this->sprite.getGlobalBounds().width / 2;
	this->playerCenter.y = this->sprite.getPosition().y + 
		this->sprite.getGlobalBounds().height / 2;
									

	this->Movement();
	this->Combat();
}