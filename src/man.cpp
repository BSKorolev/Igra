#include <SFML/Graphics.hpp>
#include <man.hpp>
using namespace sf;

namespace af
{
    bird::bird( float X, float Y)
    {
		RenderWindow window(VideoMode(1200, 700), "Boria's animation");
        x = X; y = Y;
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
    }
    bird::~bird()
    {
    }


}