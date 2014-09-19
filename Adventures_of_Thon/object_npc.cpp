#include "object_npc.h"
#include "map.h"

	npc::npc(void)
	{
	}
	npc::~npc(void)
	{
	}
	npc::npc(const string& tileset,int tiletype, int tilesize, int x, int y, int h,int w)
		:object(tileset,tiletype,tilesize,x,y,h,w)
	{

	}
	void npc::find_dir()
	{
		cout<< "Whoooh sate 1"<<endl;
		sf::Vector2f npc_pos = sprite.getPosition();
		int npc_x = sprite.getPosition().x;
		int npc_y = sprite.getPosition().y;
		bool not_working = false;
		while (not_working)
		{
		
		switch (rand() % 7)
		{
			case 0:
			if(checkPos(npc_x-40, npc_y+-40))
			{
				dir = 0;
			}
			 not_working = true;
			break ;
			case 1:
			if(checkPos(npc_x+0, npc_y-40))
			{
				dir = 1;
			}
			 not_working = true;
			break ;
			case 2:
			if(checkPos(npc_x+40, npc_y-40))
			{
				dir = 2;
			} not_working = true;
			break ;
			case 3:
			if(checkPos(npc_x-40, npc_y+0))
			{
				dir = 3;
			} not_working = true;
			break ;
			case 4:
			if(checkPos(npc_x+40, npc_y+0))
			{
				dir = 4;
			} not_working = true;
			break ;
			case 5:
			if(checkPos(npc_x-40, npc_y+0))
			{
				dir = 5;
			} not_working = true;
			break ;
			case 6:
			if(checkPos(npc_x+0, npc_y-40))
			{
				dir = 6;
			} not_working = true;
			break ;
			case 7:
			if(checkPos(npc_x-40, npc_y-40))
			{
				dir = 7;
			} not_working = true;
			break ;
		}
		}

	}


	bool npc::checkPos(int x, int y)
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



	void npc::move()
	{
	sf::Vector2f cord(sprite.getPosition());
	find_dir();
		if(checkPos(cord.x,cord.y))
		{
		cout<<cord.x<<" , "<<cord.y<<endl;
		sf::Vector2f arrowcords=sprite.getPosition();		
		//cout<<arrowcords.x<<" , "<<arrowcords.y<<endl;
		elapsedTime = clock.restart();
		tempSpeed = elapsedTime.asSeconds() * 3;
		cout <<cord.x<<" , "<<cord.y<<endl;
		switch (dir)
		{
			case 0:
			sprite.move(-40,-40);
			break ;
			case 1:
			sprite.move(0,-40);
			break ;
			case 2:
			sprite.move(40,-40);
			break ;
			case 3:
			sprite.move(-40,0);
			break ;
			case 4:
			sprite.move(40,0);
			break ;
			case 5:
			sprite.move(-40,40);
			break ;
			case 6:
			sprite.move(0,-40);
			break ;
			case 7:
			sprite.move(40,40);
			break ;
			default:
			sprite.move(0,0);
			break ;
			return;

			}
		}	
	}
	//void npc::move(int x,int y); 1