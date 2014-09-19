#include "player_projectile.h"
#include "map.h"
sf::Vector2i cords_buffer;
//buffer adjusts imaginary boundries for sprite smaller than 40*40
	projectile::projectile()
	{

	}
	projectile::projectile(const string& tileset,int tiletype, int tilesize, int x, int y, int h,int w)
		:player(tileset,tiletype,tilesize,x,y,h,w)
	{

	}
	void projectile::set(int xs,int ys,char pdir)
	{
		dir=pdir;
		switch (dir)
		{
			case 'r':
			sprite.setTextureRect(sf::IntRect(112, 120, 8, 8));
			cords_buffer.y = 0;
			cords_buffer.x = 36;
			break ;
			case 'l':
			sprite.setTextureRect(sf::IntRect(80, 120, 8, 8));
			cords_buffer.y = 0;
			cords_buffer.x = 4;
			break ;
			case 'd':
			sprite.setTextureRect(sf::IntRect(64, 120, 8, 8));
			cords_buffer.y = 36;
			cords_buffer.x = 0;
			break ;
			case 'u':
			sprite.setTextureRect(sf::IntRect(96, 120, 8, 8));
			cords_buffer.y = 0;
			cords_buffer.x = 0;
			break ;
			return;

		}
		sprite.setPosition(sf::Vector2f(xs,ys));
		
		
	}
		void projectile::move()
	{
		sf::Vector2f cord(sprite.getPosition());
		if(checkPos(cord.x+cords_buffer.x,cord.y+cords_buffer.y))
		{
		cout<<cord.x+cords_buffer.x<<" , "<<cord.y+cords_buffer.y<<endl;
		sf::Vector2f arrowcords=sprite.getPosition();		
		//cout<<arrowcords.x<<" , "<<arrowcords.y<<endl;
		elapsedTime = clock.restart();
		tempSpeed = elapsedTime.asSeconds() * 300;
		cout <<cord.x<<" , "<<cord.y<<endl;
		switch (dir)
		{
			case 'r':
			sprite.move(0+tempSpeed,0);
			break ;
			case 'l':
			sprite.move(0-tempSpeed,0);
			break ;
			case 'd':
			sprite.move(0,0+tempSpeed);
			break ;
			case 'u':
			sprite.move(0,0-tempSpeed);
			break ;
			return;

		}
		//if(dir=='r')
		//	sprite.move(0+tempSpeed,0);
		//if(dir == 'l')
		//	sprite.move(0-tempSpeed,0);

		}	
	}
	sf::Vector2f projectile::getSpritePos()
	{
		return sf::Vector2f(0,0);
	}
