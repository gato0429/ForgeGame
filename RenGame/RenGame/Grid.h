#pragma once
#include <SFML/Graphics.hpp>
#include <map>
using namespace std;


class Grid
{

private:
	
	float mOriginX;	//centros del mundo
	float mOriginY;	//centros del mundo (total de la pantalla / 2)

	sf::Vector2f mTam;  //tamaño del cuadrante
public:
	map<int, map <int, sf::RectangleShape*>* > mGrid; //tablero de la grilla el sf::RectangleShape luego se cambiara por la estructura corrspondiente
	Grid(void);
	void AddCell(int x, int y);
	~Grid(void);
};

