#pragma once
#include "object.h"
class npc : public object
{
public:
	npc(void);
	~npc(void);
	npc(const string& tileset,int tiletype, int tilesize, int x, int y, int h,int w);
	void npc::moveto(int x,int y);
	void npc::move();
	sf::IntRect spriteTexture(int d); 
	bool checkPos(int x, int y);
	char lastdir;
	void find_dir();
	sf::Vector2f getSpritePos();	
private:
	sf::Clock clock;
	sf::Time elapsedTime;
	float tempSpeed;
	char dir;

};