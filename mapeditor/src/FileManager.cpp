#include"../include/FileManager.hpp"

using namespace sf;
using namespace std;

void FileManager::readFromFile(string filename, vector<Tile>& tiles)
{
	this->file.open(filename.c_str());
	
	while(!file.eof())
	{
		Vector2f 	position;
		int			type;
		this->file>>position.x>>position.y>>type;
	}
}

void FileManager::writeToFile(string filename, vector<Tile>& tiles)
{
	this->file.open(filename.c_str());
	this->sort(tiles);
	
	for(int i=0; i<tiles.size(); i++) {
		Vector2f 	position 	= tiles[i].getPosition();
		std::string type		= tiles[i].getType();
		this->file<<position.x<<" "<<position.y<<" "<<type<<endl;
	}
}

void FileManager::sort(vector<Tile>& tiles)
{
	vector<vector<Sprite> > temp;

	for(int i=0; i<tiles.size(); i++) {
		
	}
}
