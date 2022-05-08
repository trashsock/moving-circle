#include <SFML/Graphics.hpp>
#include <iostream>

	//window size
const int winx = 700;
const int winy = 700;


int main()
{
	sf::RenderWindow window(sf::VideoMode(winx, winy), "week 5 assignment q4"); //window size

	float velx = 0.f;
	float vely = 0.f;
	float posx = winx / 2.0f;
	float posy = winy / 2.0f;

	float radius = 50.0f;

	sf::CircleShape disc1;
	disc1.setRadius(radius);
	disc1.setFillColor(sf::Color::Blue);
	disc1.setOrigin(sf::Vector2f(radius, radius));


	float dt = 0;
	sf::Clock clock;
	clock.restart();


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				vely = -100.0f;
				velx = 0.0f;
				posx += velx * dt;
				posy += vely * dt;
				disc1.setPosition(posx, posy);
				window.draw(disc1);
				window.display();
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				vely = 100.0f;
				velx = 0.0f;
				posx += velx * dt;
				posy += vely * dt;
				disc1.setPosition(posx, posy);
				window.draw(disc1);
				window.display();
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				velx = -100.0f;
				vely = 0.0f;
				posx += velx * dt;
				posy += vely * dt;
				disc1.setPosition(posx, posy);
				window.draw(disc1);
				window.display();
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				velx = 100.0f;
				vely = 0.0f;
				posx += velx * dt;
				posy += vely * dt;
				disc1.setPosition(posx, posy);
				window.draw(disc1);
				window.display();
			}

			else
			{
				velx = 0.0f;
				vely = 0.0f;
				posx += velx * dt;
				posy += vely * dt;
				disc1.setPosition(posx, posy);
				window.draw(disc1);
				window.display();
			}
		}

		dt = clock.restart().asSeconds();
		posx += velx * dt;
		posy += vely * dt;
		window.clear();
		disc1.setPosition(posx, posy);
		window.draw(disc1);
		window.display();
	}
	return 0;
}