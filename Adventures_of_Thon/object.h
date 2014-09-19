#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;


class object : public sf::Drawable, public sf::Transformable
{
public:
	object();
		object(const string& tileset,int tiletype, int tilesize, int x, int y, int h,int w);
		~object(void);
		bool load(const string& tileset,int tiletype, int tilesize, int x, int y, int h,int w);
		int reportPos(char axis);
protected:
	int x0;
	int y0;
	int h0;
	int w0;
	int tt;
	void draw(sf::RenderTarget& target,sf::RenderStates states) const
    {
		states.texture=&texture;
		target.draw(sprite,states);
    }
	sf::Sprite sprite;
	sf::Texture texture;
public:
	object(int x0,int y0);
	/*virtual void draw(void) = 0;*/
	void erase(void);
	void moveTo(int x,int y);
	sf::IntRect start_sprite(int type);
};

