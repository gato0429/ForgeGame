#include "Grid.h"


Grid::Grid(void)
{
	mOriginX=400;
	mOriginY=300;
	mTam.x=30;
	mTam.y=30;

}


Grid::~Grid(void)
{
}

void Grid::AddCell( int x, int y )
{
	int nX=(x-mOriginX)/45;
	int nY=(y-mOriginY)/45;
	float dX=(x-mOriginX)/45;
	float dY=(y-mOriginY)/45;
	map<int, map <int, sf::RectangleShape*>* >::iterator it;

	it=mGrid.find(nY);
	if (it!=mGrid.end())
	{
		map <int, sf::RectangleShape*> * mapa=it->second;

		map <int, sf::RectangleShape*>::iterator itm;
		itm=mapa->find(nX);
		if (itm==mapa->end())
		{
			pair<int, sf::RectangleShape*> mn;
			sf::RectangleShape* nr=new sf::RectangleShape(mTam);
			nr->setOrigin(sf::Vector2f(15,15));
			nr->setPosition(mOriginX+nX*45,mOriginY+nY*45);
			nr->setRotation(45);
			nr->setFillColor(sf::Color::Green);
			nr->setOutlineColor(sf::Color::Red);
			nr->setOutlineThickness(1);
			mn.first=nX;
			mn.second=nr;
			mapa->insert(mn);
		}
	}
	else
	{
	pair<int, sf::RectangleShape*> mn;
	sf::RectangleShape* nr=new sf::RectangleShape(mTam);
	nr->setOrigin(sf::Vector2f(15,15));
	nr->setPosition(mOriginX+nX*45,mOriginY+nY*45);
	nr->setRotation(45);
	nr->setFillColor(sf::Color::Blue);
	nr->setOutlineColor(sf::Color::Red);
	nr->setOutlineThickness(1);
	mn.first=nX;
	mn.second=nr;
	
	map<int,sf::RectangleShape*>* mi=new map<int,sf::RectangleShape*>();
	mi->insert(pair<int, sf::RectangleShape*>(mn));
	mGrid.insert(pair< int,map <int, sf::RectangleShape*>* >(nY,mi));
	}
}
