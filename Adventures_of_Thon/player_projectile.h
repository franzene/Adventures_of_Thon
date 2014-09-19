#pragma once
#include "object_player.h"
class projectile : public player
{
public:
	projectile();
	projectile(const string& tileset,int tiletype, int tilesize, int x, int y, int h,int w);
	void projectile::set(int xs,int ys,char pdir);
	void projectile::move();
	sf::Vector2f getSpritePos();
	void find_dir();
	
private:
	sf::Clock clock;
	sf::Time elapsedTime;
	float tempSpeed;
	char dir;

protected:
	//int h,w;
};

