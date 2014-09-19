#pragma once
#include "object.h"
class player : public object
{
public:
	player(void);
	~player(void);
	player(const string& tileset,int tiletype, int tilesize, int x, int y, int h,int w);
	void player::moveto(int x,int y);
	void player::move(int x,int y);
	void player::left();
	void player::right();
	void player::up();
	void player::down();
	char player::currentdir();
	sf::IntRect spriteTexture(int d); 
	bool checkPos(int x, int y);
	char lastdir;


protected:
	//int h,w;
};

