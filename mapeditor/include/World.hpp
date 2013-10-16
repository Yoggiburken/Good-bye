#include<map>
#include<vector>
#include<SFML/Graphics.hpp>

#ifndef VECTOR_COMPARATOR
#define VECTOR_COMPARATOR
struct VectorComparator {
	bool operator() (sf::Vector2f lhs, sf::Vector2f rhs) const
	{
		return lhs.x + lhs.y > rhs.x + rhs.y;
	}
};
#endif

#ifndef WORLD_HPP
#define WORLD_HPP
class World {
private:
	sf::RenderWindow					app;
	sf::Event							event;

	int									tilenumber;
	sf::Texture							sprite_sheet;	
	std::vector<sf::Sprite>				tile_types;
	std::vector<sf::Sprite>				tilemap;
	void								addTile();
	void								drawMouseTile();
public:
										World();
	void								main();
};
#endif
