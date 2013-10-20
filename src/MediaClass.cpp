#include<fstream>
#include<iostream>
#include"../include/MediaClass.hpp"

using namespace std;

MediaClass::MediaClass()
{
    string filepath, hashname;
    ifstream file;
    file.open("textures.txt");
    
    sf::Texture temp;

    while(!file.eof())
    {   
        file>>filepath>>hashname; 
        temp.loadFromFile(filepath);
        textures.insert( std::pair<std::string, sf::Texture>(hashname, temp));
    }
}

sf::Texture& MediaClass::getTexture(std::string& textureID)
{
    return textures[textureID.c_str()];
}
