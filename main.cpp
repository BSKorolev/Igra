#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <man.hpp>
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
using namespace sf;
using namespace af;

int main()
{
	RenderWindow window(VideoMode(1200, 700), "Boria's animation");

	Texture t_back;
	t_back.loadFromFile("C:/Users/U1/source/Igra/img/back.jpg");
	Sprite back;
	back.setTexture(t_back);

	Image icon;
	icon.loadFromFile("C:/Users/U1/source/Igra/img/ico.png");
	window.setIcon(32, 32, icon.getPixelsPtr());

	Texture t;
	t.loadFromFile("C:/Users/U1/source/Igra/img/dva.png");
	Sprite bird;
	bird.setTexture(t);
	bird.setPosition(600, 100);
	bird.setTextureRect(IntRect(0, 0, 175, 160));


	Clock clock;
	float currentFrame = 0;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 1200;
		
		if ((Keyboard::isKeyPressed(Keyboard::Left)) || (Keyboard::isKeyPressed(Keyboard::A)))
		{
			bird.move(-0.1, 0);
			bird.setTextureRect(IntRect(0, 0, 175, 160)); 
			currentFrame += 0.005 * time;
			if (currentFrame > 2) 
				currentFrame -= 2;
			bird.setTextureRect(IntRect(0 * int(currentFrame), 0, 175, 160));
			bird.setTextureRect(IntRect(175 * int(currentFrame) + 175, 0, -175, 160));
		}
		if ((Keyboard::isKeyPressed(Keyboard::Right)) || (Keyboard::isKeyPressed(Keyboard::D)))
		{
			bird.move(0.1, 0);
			bird.setTextureRect(IntRect(175,0 ,-175 , 160));
			currentFrame += 0.005 * time;
			if (currentFrame > 2)
				currentFrame -= 2;
			bird.setTextureRect(IntRect(0 * int(currentFrame), 0, 175, 160));
			bird.setTextureRect(IntRect(175 * int(currentFrame) , 0, 175, 160));
		}
		if ((Keyboard::isKeyPressed(Keyboard::Up)) || (Keyboard::isKeyPressed(Keyboard::W)))
		{
			bird.move(0, -0.1);
		}
		if ((Keyboard::isKeyPressed(Keyboard::Down)) || (Keyboard::isKeyPressed(Keyboard::S)))
		{
			bird.move(0, 0.1);
		}
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		
		window.clear();
		window.draw(back);
		window.draw(bird);
		window.display();
	}

	return 0; 
}

