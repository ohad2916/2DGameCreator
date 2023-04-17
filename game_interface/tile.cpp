
#include "game_common.h"


Tile::Tile(GameWindow& game_window) : Entity(game_window)
{
	src_rect.x = src_rect.y = 0;
	src_rect.w = dest_rect.w = 32;
	src_rect.h = dest_rect.h = 32;
}




WaterTile::WaterTile(GameWindow& game_window) : Tile(game_window)
{
	m_name = "WaterTile";
	m_texture = game_window.GetTexture(m_name);
}


DirtTile::DirtTile(GameWindow& game_window) : Tile(game_window)
{
	m_name = "DirtTile";
	m_texture = game_window.GetTexture(m_name);
}



GrassTile::GrassTile(GameWindow & game_window) : Tile(game_window)
{
	m_name = "GrassTile";
	m_texture = game_window.GetTexture(m_name);
}
