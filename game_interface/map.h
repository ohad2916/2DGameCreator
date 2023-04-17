#pragma once
#include "game_common.h"

class Map
{
public:
	Map() = default;

	Map(uint8_t arr[20][25], GameWindow& game_window, uint32_t width, uint32_t height);

	Map(const Map&) = default;

	void Load(const std::string& path);

	void Render();

	void UpdateRenderer();

private:
	uint8_t m_arr[20][25];
	std::vector<Tile> m_tiles;
	GameWindow& m_game_window;
	SDL_Renderer* m_renderer = nullptr;
	uint32_t m_width = 0;
	uint32_t m_height = 0;



};