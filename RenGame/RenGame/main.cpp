#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
int main()
{
	cout<<"La semilla del juego"<<endl;
	cout<<"Miau Reportandose"<<endl;

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML RenGame in Progress!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
	//system("pause");
	return 0;
}