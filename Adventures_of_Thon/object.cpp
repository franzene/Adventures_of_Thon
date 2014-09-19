#include "object.h"
object::object(void)

{
	x0=16;
	y0=16; 
	h0 = 16;
	w0 = 16;
	tt=-1;
	sf::Sprite sprite;
	sf::Texture texture;

}
object::~object(void)
{
}
object::object(const string& tileset,int tiletype, int tilesize, int x, int y, int h,int w)
	:x0(x0), y0(y0)
{

}
int object::reportPos(char axis)
{
	sf::Vector2f cord(sprite.getPosition());
	if(axis == 'y')
		return cord.y;
	else
		return cord.x;

}

bool object::load(const string& tileset,int tiletype, int tilesize, int x, int y, int h,int w)
{
	if (!texture.loadFromFile(tileset))
            return false;
	sprite.setScale(sf::Vector2f(5.f, 5.f));
	sprite.setTexture(texture);
	/*sprite.setTextureRect(sf::IntRect(24, 232, 8, 8));*/
	sprite.setTextureRect(start_sprite(tiletype));
	sprite.setPosition(sf::Vector2f(x, y));


}
sf::IntRect object::start_sprite(int type)
{
	//0 warrior
	//1 archer
	//2 npc_test
	if(type == 1)
		return sf::IntRect(24, 232, 8, 8);
	else if(type == 2)
		return sf::IntRect(0, 72, 8, 8);
	else 
		return sf::IntRect(0, 0, 8, 8);
}
void object::erase(void)
{
	cout <<"changing pen to background color\n";
	/*draw();*/
	cout << "changing pen to foreground color\n";
}
void object::moveTo(int x,int y)
{
	erase();
	x0=x;
	y0=y;
	/*draw();*/
}