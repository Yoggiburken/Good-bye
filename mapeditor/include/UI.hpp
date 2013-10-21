#include<SFML/Graphics.hpp>
#include<vector>
#include"Tile.hpp"

#ifndef UI_HPP
#define UI_HPP
class UI : public sf::Drawable {
private:
	std::vector<Tile>			tile_types;

	void						draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
								~UI();
	void						setContent(std::vector<Tile>& tile_types);
	void						setMouseTileOnClick(sf::Event& event);
	void						mouseHover(sf::RenderWindow& window);
};
#endif
