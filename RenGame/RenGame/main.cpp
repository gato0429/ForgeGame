#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Grid.h"
using namespace std;
int main()
{
	cout<<"La semilla del juego"<<endl;
	cout<<"Miau Reportandose"<<endl;

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML RenGame in Progress!");

	sf::RectangleShape shape(sf::Vector2f(30,30));
	shape.setOrigin(sf::Vector2f(15,15));
	shape.setPosition(window.getSize().x/2,window.getSize().y/2);
	shape.setRotation(45);
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineColor(sf::Color::Red);
	shape.setOutlineThickness(1);

	sf::CircleShape centro(5);
	centro.setOrigin(2.5,2.5);
	centro.setPosition(window.getSize().x/2,window.getSize().y/2);
	centro.setFillColor(sf::Color::Red);
	cout<<centro.getPosition().x<<" ";
	cout<<centro.getPosition().y;
	cout<<endl;
	Grid gato;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left)
			{
				int nx=event.mouseButton.x;
				int ny=event.mouseButton.y;
				
				cout<<nx<<" "<<ny<<endl;
				gato.AddCell(nx,ny);
			}
		}

		window.clear(sf::Color::Transparent);
	//	window.draw(shape);
		window.draw(centro);

		map<int, map <int, sf::RectangleShape*>* >::iterator it;

		for (it=gato.mGrid.begin(); it!=gato.mGrid.end(); it++)
		{
			map <int, sf::RectangleShape*> * mapa=(it->second);
			map <int, sf::RectangleShape*>::iterator itm;

			for (itm=mapa->begin(); itm!=mapa->end(); itm++)
			{
				window.draw(*itm->second);
			}
		}
		window.display();
	}
	//system("pause");
	return 0;
}