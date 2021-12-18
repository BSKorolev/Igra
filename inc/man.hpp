#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
namespace af 
{
	
    class bird
    {
    private:
        float x = 0, y = 0;
    public:
        Texture texture;
        Image image;
        Sprite sprite;
        Clock clock;
        bird( float X, float Y);
        ~bird();
    };


}