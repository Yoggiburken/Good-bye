#include"../include/FileManager.hpp"
#include<deque>

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
	deque<deque<Tile>	>	temp;
	temp.push_back(deque<Tile>(1, tiles[0]));
	for(int i=1; i<tiles.size(); i++) {
		Vector2f position = tiles[i].getPosition();
		if(position.y < temp[0][0].getPosition().y) {
			temp.push_front(deque<Tile>(1, tiles[i]));
		} else if(position.y > temp[temp.size()-1][0].getPosition().y) {
			temp.push_back(deque<Tile> (1, tiles[i]));
		} else {
			float last_y, current_y;
			for(int j=0; j<temp.size(); j++) {
				last_y 	= current_y;
				current_y = temp[j][0].getPosition().y;
				if(position.y == temp[j][0].getPosition().y) {
					if(position.x < temp[j][0].getPosition().x || temp[j].size() == 0) {
						temp[j].push_front(tiles[i]);
					} else if(position.x > temp[j][temp[j].size()-1].getPosition().x) {
						temp[j].push_back(tiles[i]);
					} else {
						float last_x = temp[j][0].getPosition().y, current_x;
						for(int k=1; k<temp[j].size(); k++) {
							current_x	= temp[j][k].getPosition().x;
							if(position.x > last_x && position.x < current_x && k!=0) {
								temp[j].insert(temp[j].begin()+k, tiles[i]);
							}
							last_x 		= current_x;
						}
					}
				} else if(position.y > last_y && position.y < current_y && j!=0) { //Check if y coord doesn't exist
					temp.insert(temp.begin()+j, deque<Tile> (1, tiles[i]));
				}
			}
		}
	}
	
	tiles.clear();
	for(int i=0; i<temp.size(); i++) {
		for(int j=0; j<temp[i].size(); j++) {
			tiles.push_back(temp[i][j]);
		}
	}
}

/*
void FileManager::sort(vector<Tile>& tiles)
{
	deque<deque<Tile>	>	temp;
	for(int i=0; i<tiles.size(); i++) {
		Vector2f position = tiles[i].getPosition();
		if(position.y < temp[0][0].getPosition().y) {
			temp.push_front(deque<Tile> (1, tiles[i]));
		} else if(position.y > temp[temp.size()-1][0].getPosition().y) {
			temp.push_back(deque<Tile> (1, tiles[i]));
		} else {
			float last_y, current_y;
			for(int j=0; j<temp.size(); j++) {
				last_y 	= current_y;
				current_y = temp[j][0].getPosition().y;
				if(position.y == temp[j][0].getPosition().y) {
					if(position.x < temp[j][0].getPosition().x || temp[j].size() == 0) {
						temp[j].push_front(tiles[i]);
					} else if(position.x > temp[j][temp[j].size()-1].getPosition().x) {
						temp[j].push_back(tiles[i]);
					} else {
						float last_x = temp[j][0].getPosition().y, current_x;
						for(int k=1; k<temp[j].size(); k++) {
							current_x	= temp[j][k].getPosition().x;
							if(position.x > last_x && position.x < current_x) {
								last_x 		= current_x;
							}
						}
					}
				} else if(position.y > last_y && position.y < current_y && j!=0) { //Check if y coord doesn't exist
					temp.insert(temp.begin()+j-1, deque<Tile> (1, tiles[i]));
				}
			}
		}
	}
}*/
