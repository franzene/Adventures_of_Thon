#include "object_player.h"
#include "map.h"

player::player(void)
{
}

player::~player(void)
{
}
char player::currentdir()
{
	return lastdir;
	//return the direction playe is facing
}
player::player(const string& tileset,int tiletype, int tilesize, int x, int y, int h,int w)
	:object(tileset,tiletype,tilesize,x,y,h,w)
{
}

	void player::moveto(int x,int y)
	{
		//move player to x,y cords
		sprite.setPosition(sf::Vector2f(x, y));
	}
	void player::move(int x,int y)
	{
		//change position by x pixels and y pixels
		sprite.move(sf::Vector2f(x, y));
	}
	void player::left()
	{
	lastdir = 'l';
	sprite.setTextureRect(spriteTexture(3));
	sf::Vector2f cord(sprite.getPosition());
	if(checkPos(cord.x-40,cord.y))
	{
	move(-40,0);
	}
	//if told left, change spite to look left, move if map allows so.
	}
	void player::right()
	{
	lastdir = 'r';
	sprite.setTextureRect(spriteTexture(4));
	sf::Vector2f cord(sprite.getPosition());
	if(checkPos(cord.x+40,cord.y))
	{
	move(40,0);
	//if told left, change spite to look left, move if map allows so.
	}}
	void player::up()
	{
		lastdir = 'u';
	sprite.setTextureRect(spriteTexture(1));
	sf::Vector2f cord(sprite.getPosition());
	if(checkPos(cord.x,cord.y-40))
	{move(0,-40);
	//if told left, change spite to look left, move if map allows so.
	}}
	void player::down()
	{
		lastdir = 'd';
		sprite.setTextureRect(spriteTexture(2));
		sf::Vector2f cord(sprite.getPosition());
		if(checkPos(cord.x,cord.y+40))
		{move(0,40);
		}//if told left, change spite to look left, move if map allows so.
	}
	bool player::checkPos(int x, int y)
	{
		//check if cords player wishes to move to are restricted
	int pos;
	y = (y/40);
	pos = ((y*16)+(x/40));
	if (level[pos] == 1)
	{
		return true;
	}
		return false;
	}
	sf::IntRect player::spriteTexture(int d)
{
	if(d == 1)
	{return sf::IntRect(24, 232, 8, 8);}
	if(d==2)
	{return sf::IntRect(8, 232, 8, 8);}
	if (d==3)
	{return sf::IntRect(16, 232, 8, 8);}
	if (d==4)
	{return sf::IntRect(0, 232, 8, 8);}



}