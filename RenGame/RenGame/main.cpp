#include <SFML/Graphics.hpp>

class Game
{
	public:
	
	Game();
	void run()
	{
		while (mWindow.isOpen())
		{
			processEvents();
			update();
			render();
		}
	}
	private:
		void processEvents()
		{
			sf::Event event;
			while (mWindow.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					mWindow.close();
			}
		}
		void update()
		{
		}
		void render()
		{
			int centrox = 320;
			int centroy = 240;
			int variacion = 60;

			mWindow.clear();
			mWindow.draw(mPlayer);
			//mWindow.draw(sf::Shape::Line(100,100, 200, 200, 30.0, sf::Color::Blue));
			
			for(int j = 0; j < 5;j++)
			{
				int nuevoCentroY;
				if (j%2 == 0)
					nuevoCentroY = centroy+(j/2)*variacion-((j%2)*variacion/2);
				else
					nuevoCentroY = centroy+(j-2)*variacion-((j%2)*variacion/2);
				int repite = 0;
				while(repite<2)
				{
					for(int i = 0; i < 3;i++)
					{
						sf::CircleShape punto;
						//sf::CircleShape casilla;
						int nuevoCentroX = centrox+((j%2)*variacion/2)+i*variacion;										

						sf::Vertex line[] =
						{
							sf::Vertex(sf::Vector2f(nuevoCentroX-variacion/2,nuevoCentroY)),
							sf::Vertex(sf::Vector2f(nuevoCentroX,nuevoCentroY+variacion/2)),
							sf::Vertex(sf::Vector2f(nuevoCentroX,nuevoCentroY+variacion/2)),
							sf::Vertex(sf::Vector2f(nuevoCentroX+variacion/2,nuevoCentroY)),
							sf::Vertex(sf::Vector2f(nuevoCentroX+variacion/2,nuevoCentroY)),
							sf::Vertex(sf::Vector2f(nuevoCentroX,nuevoCentroY-variacion/2)),
							sf::Vertex(sf::Vector2f(nuevoCentroX,nuevoCentroY-variacion/2)),
							sf::Vertex(sf::Vector2f(nuevoCentroX-variacion/2,nuevoCentroY))
						};

						mWindow.draw(line, 8, sf::Lines);

						punto.setRadius(1.0f);
						punto.setPosition(nuevoCentroX,nuevoCentroY);
						punto.setFillColor(sf::Color::Cyan);
						mWindow.draw(punto);

						nuevoCentroX = centrox+((j%2)*variacion/2)-i*variacion;

						sf::Vertex line2[] =
						{
							sf::Vertex(sf::Vector2f(nuevoCentroX-variacion/2,nuevoCentroY)),
							sf::Vertex(sf::Vector2f(nuevoCentroX,nuevoCentroY+variacion/2)),
							sf::Vertex(sf::Vector2f(nuevoCentroX,nuevoCentroY+variacion/2)),
							sf::Vertex(sf::Vector2f(nuevoCentroX+variacion/2,nuevoCentroY)),
							sf::Vertex(sf::Vector2f(nuevoCentroX+variacion/2,nuevoCentroY)),
							sf::Vertex(sf::Vector2f(nuevoCentroX,nuevoCentroY-variacion/2)),
							sf::Vertex(sf::Vector2f(nuevoCentroX,nuevoCentroY-variacion/2)),
							sf::Vertex(sf::Vector2f(nuevoCentroX-variacion/2,nuevoCentroY))
						};

			

						mWindow.draw(line2, 8, sf::Lines);

						punto.setPosition(nuevoCentroX,nuevoCentroY);
						punto.setFillColor(sf::Color::Cyan);
						mWindow.draw(punto);

					}
					if (j%2 == 0)
						nuevoCentroY = centroy-(j/2)*variacion+((j%2)*variacion/2);
					else
						nuevoCentroY = centroy-(j-2)*variacion+((j%2)*variacion/2);

					repite+=1;
				}
				

			}

			mWindow.display();
		}
	private:
		sf::RenderWindow mWindow;
		sf::CircleShape mPlayer;
};

Game::Game() : mWindow(sf::VideoMode(640, 480), "SFML Application") , mPlayer()
{
mPlayer.setRadius(4.f);
mPlayer.setPosition(0.f, 0.f);
mPlayer.setFillColor(sf::Color::Cyan);
}

int main()
{
	Game game;
	game.run();
    /*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
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
    }*/

    return 0;
}