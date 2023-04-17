
#include "game_common.h"



Map::Map(uint8_t arr[20][25], GameWindow& game_window , uint32_t width, uint32_t height)
	:m_game_window(game_window),m_width(width),m_height(height)
{
	UpdateRenderer();
	m_tiles.clear();
	m_tiles.emplace_back(WaterTile(m_game_window));
	m_tiles.emplace_back(DirtTile(m_game_window));
	m_tiles.emplace_back(GrassTile(m_game_window));

	for (auto& tile : m_tiles)
	{
		tile.UpdateSrcRect({0, 0, 32, 32});
		tile.SetRenderer(m_renderer);
	}
	std::memcpy(m_arr, arr, width * height * sizeof(uint8_t));

}

void Map::UpdateRenderer()
{
	m_renderer = m_game_window.GetRenderer();
}

void Map::Load(const std::string & path)
{
	
}

void Map::Render()
{

	for (uint32_t i = 0; i < m_height; ++i)
	{
		for (uint32_t j = 0; j < m_width;j++)
		{
			m_tiles[m_arr[i][j]].Reposition(j*32, i*32);
			m_tiles[m_arr[i][j]].Render();
		}
	}
}

