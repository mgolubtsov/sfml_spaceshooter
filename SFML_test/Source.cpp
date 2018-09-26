#include "Game.h"

int main() 
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dat a game!", sf::Style::Default);
	

	Game game(&window);

	//Game loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
		}

		game.Update();
		game.Draw();
	}

	

	return 0;
}