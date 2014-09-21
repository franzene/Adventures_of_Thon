#include <SFML/Graphics.hpp>
#include <iostream>
#include "drawmap.h"
#include "map.h"
#include "object.h"
#include "object_player.h"
#include "player_projectile.h"
#include "object_npc.h"
//#include "texture.cpp"
using namespace std;
using namespace sf;
Vector2f mapcords(int tt,int corner);
int main()
{
	 
	drawmap map;
	player player;
	projectile player_arrows;
	npc npc_test;
	sf::RenderWindow window;
	window.create(sf::VideoMode(640,640),"oryx");
	//creates window size 640 by 640 labled oryx
		
	    if (!map.load("lofi_environment.png", level,40, 16, 16,9))
			return -1;
		if(!player_arrows.load("lofi_obj.png",1, 16,0, 0, 16,16))
		{
			cout <<"error loading image\n";
		}
		if(!player.load("lofi_char.png",1, 16,0, 0, 16,16))
		{
			cout <<"error loading image\n";
		}
		if(!npc_test.load("lofi_char.png",2, 16,320, 280, 16,16))
		{
			cout <<"error loading image\n";
		}
		//loads three image files spites default size 40 px
		player.lastdir='d';
		player.moveto(80,80);
	while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
			switch(event.type)
			{
            // "close requested" event: we close the window
            case sf::Event::Closed:
					window.close();
			break;
				case sf::Event::KeyPressed:
					if(event.key.code == sf::Keyboard::Space)
					{
						
					}

					if(event.key.code == sf::Keyboard::W)
					{
						player.up();

					}
					if(event.key.code == sf::Keyboard::S)
					{
						player.down();

					}
					if(event.key.code == sf::Keyboard::D)
					{
						player.right();

					}
					if(event.key.code == sf::Keyboard::A)
					{
						player.left();

					}
					if(event.key.code == sf::Keyboard::Up)
					{
						player_arrows.set(player.reportPos('x'),player.reportPos('y'),'u');

					}
					if(event.key.code == sf::Keyboard::Down)
					{
						player_arrows.set(player.reportPos('x'),player.reportPos('y'),'d');

					}
					if(event.key.code == sf::Keyboard::Right)
					{
						player_arrows.set(player.reportPos('x'),player.reportPos('y'),'r');

					}
					if(event.key.code == sf::Keyboard::Left)
					{
						player_arrows.set(player.reportPos('x'),player.reportPos('y'),'l');

					}
					cout<<player.lastdir;


			}
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

		player_arrows.move();
		npc_test.move();
		window.draw(map);
		window.draw(player_arrows);
		window.draw(player);
		window.draw(npc_test);
        // end the current frame
        window.display();
    }

    return 0;

} 



