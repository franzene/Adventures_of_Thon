#include <SFML/Graphics.hpp>
#include <iostream>
//#include "texture.cpp"
using namespace std;
using namespace sf;
Vector2f mapcords(int tt,int corner)
{
if(tt ==0)
{
	//border
	if (corner ==0)
	{return Vector2f(40,8 );}
	if(corner == 1)
	{return Vector2f(40,0);}
	if (corner ==2)
	{return Vector2f(48, 0);}
	if (corner == 3)
	{return Vector2f(48, 8);}

}
//grass
else if(tt==1){
	if(corner ==0)
	{return Vector2f(64,40);}
	if(corner == 1)
	{return Vector2f(64,32);}
	if (corner ==2)
	{return Vector2f(72, 32);}
	if (corner == 3)
	{return Vector2f(72, 40);}
}
	//bottom section wood?}
else if(tt==2){
	if(corner ==0)
	{return Vector2f(96,104);}
	if(corner == 1)
	{return Vector2f(96,96);}
	if (corner ==2)
	{return Vector2f(104, 96);}
	if (corner == 3)
	{return Vector2f(104, 104);}
}

else{return Vector2f(72, 40);
}
return Vector2f(0,0);
};

class drawmap : public sf::Drawable, public sf::Transformable
{
public:
	//take(spriteseet,tiletype array,tilesize,rows,collums,num?)
	bool load(const string& tileset,const int* tt, int ts, int r, int c, int num) 
	{
	count =0;row =1;a = 0;	 b = 1;	 d = 2;	 e = 3;y=0;x=0;
	
		if (!tiletex.loadFromFile(tileset))
            return false;
	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(r*c*4 );
		//cout <<endl<<"Row "<<row<<": ";

	while(y < c)
	{
	while(x < r)
	{
		tiletype = tt[count];
		vertices[a].position = sf::Vector2f((0+x)*ts,(1+y)*ts);
		vertices[b].position = sf::Vector2f((0+x)*ts,(0+y)*ts);
		vertices[d].position = sf::Vector2f((1+x)*ts,(0+y)*ts);
		vertices[e].position = sf::Vector2f((1+x)*ts,(1+y)*ts);
		 //   cout << " corner 0 :"<<vertices[a].position.x<<",";
			//cout << vertices[a].position.y;
			//cout << " corner 1 :"<<vertices[b].position.x<<",";
			//cout << vertices[b].position.y;
			//cout << " corner 2 :"<<vertices[d].position.x<<",";
			//cout << vertices[d].position.y;
			//cout <<" corner 3 :"<< vertices[e].position.x<<",";
			//cout << vertices[e].position.y<<endl;
		vertices[a].texCoords = mapcords(tiletype,0);
		vertices[b].texCoords = mapcords(tiletype,1);
		vertices[d].texCoords = mapcords(tiletype,2);
		vertices[e].texCoords = mapcords(tiletype,3);
		 a += 4; b += 4; d += 4; e += 4;count++;x++;
		
	}
	row += 1;
	/*cout <<endl<<"Row "<<row<<": ";*/
	y++;
	x = 0;


	}
	return true;

	}
    
private:
		int row;
		int count;

	int y,x;
		int a,b,d,e;
		int tiletype;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
		states.transform *= getTransform();
        states.texture = &tiletex;
		target.draw(vertices, states);
    }
	sf::VertexArray vertices;
    sf::Texture tiletex;


};
//--------------------