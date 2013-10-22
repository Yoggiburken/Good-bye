#include<fstream>
#include<iostream>
#include<iomanip>
#include"../include/MediaClass.hpp"

using namespace std;

MediaClass::MediaClass()
{
    string filetype, filepath, hashname;
    ifstream file;
    file.open("resources.txt");
    
    while(true)
    {   
        file>>filetype>>filepath>>hashname;
		if(file.eof()) {
			break;
		}
		cout<<left<<setfill(' ')<<setw(20)<<filetype<<setw(40)<<filepath<<setw(20)<<hashname<<endl;
        if(filetype == "TEXTURE") {
    		sf::Texture temp;
        				temp.loadFromFile(filepath);
			textures.insert( std::pair<std::string, sf::Texture>(hashname, temp));
		} else if(filetype == "SOUND") {
			sf::SoundBuffer temp;
        					temp.loadFromFile(filepath);
			soundbuffers.insert( std::pair<std::string, sf::SoundBuffer>(hashname, temp));
		} else if(filetype == "FONT") {
			sf::Font	temp;
        				temp.loadFromFile(filepath);
			fonts.insert( std::pair<std::string, sf::Font>(hashname, temp));
		}
    }
}

MediaClass::~MediaClass()
{
	textures.clear();
	soundbuffers.clear();
	fonts.clear();
}

sf::Texture& MediaClass::getTexture(std::string textureID)
{
    return textures[textureID.c_str()];
}

sf::SoundBuffer& MediaClass::getSoundBuffer(std::string soundbufferID)
{
    return soundbuffers[soundbufferID.c_str()];
}

sf::Font& MediaClass::getFont(std::string fontID)
{
    return fonts[fontID.c_str()];
}
