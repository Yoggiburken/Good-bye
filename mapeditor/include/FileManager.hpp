#include<fstream>
#include<vector>
#include<SFML/Graphics.hpp>
#include"Tile.hpp"

#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP
class 	FileManager {
private:
	void				sort(std::vector<Tile>& tiles);
public:
	void				writeToFile(std::string filename, std::vector<Tile>& tiles);
	void				readFromFile(std::string filename, std::vector<Tile>& tiles);
};
#endif
