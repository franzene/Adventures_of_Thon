#include "object_npc.h"
#include "map.h"
#include <random>

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
		dir = 0;
		
		sf::Vector2f npc_pos = sprite.getPosition();
		int npc_x = sprite.getPosition().x;
		int npc_y = sprite.getPosition().y;
		not_working = true;
		while (not_working)
		{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 7);
	
		switch (dis(gen))
		{
			case 0:
			if(checkPos(npc_x-40, npc_y-40))
			{
				dir = 0;
				not_working = false;
			}
			 
			break ;
			case 1:
			if(checkPos(npc_x+0, npc_y-40))
			{
				dir = 1;
				not_working = false;
			}
			 
			break ;
			case 2:
			if(checkPos(npc_x+40, npc_y-40))
			{
				dir = 2;
				not_working = false;
			} 
			break ;
			case 3:
			if(checkPos(npc_x-40, npc_y+0))
			{
				dir = 3;
				not_working = false;
			} 
			break ;
			case 4:
			if(checkPos(npc_x+40, npc_y+0))
			{
				dir = 4;
				not_working = false;
			} 
			break ;
			case 5:
			if(checkPos(npc_x-40, npc_y+40))
			{
				dir = 5;
				not_working = false;
			} 
			break ;
			case 6:
			if(checkPos(npc_x+0, npc_y+40))
			{
				dir = 6;
				not_working = false;
			} 
			break ;
			case 7:
			if(checkPos(npc_x+40, npc_y+40))
			{
				dir = 7;
				not_working = false;
			} 
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
		bool first_run = true;
		if(first_run)
		{elapsedTime = clock.restart();}

	tempSpeed = elapsedTime.asSeconds()*10000;
	/*cout <<tempSpeed<<endl;*/
	sf::Vector2f cord(sprite.getPosition());
	if(tempSpeed>50)
	{
	not_working = true;
	find_dir();
	cout<<dir<<endl;
		/*cout<<cord.x<<" , "<<cord.y<<endl;*/
		sf::Vector2f arrowcords=sprite.getPosition();		
		//cout<<arrowcords.x<<" , "<<arrowcords.y<<endl;

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
			sprite.move(0,40);
			break ;
			case 7:
			sprite.move(40,40);
			break ;
			default:
			sprite.move(0,0);
			break ;
			elapsedTime = clock.restart();
			//cout<<"reset clock\n";

			}
					elapsedTime = clock.restart();
			//cout<<"reset clock\n";
		}	
	}
	//void npc::move(int x,int y); 1