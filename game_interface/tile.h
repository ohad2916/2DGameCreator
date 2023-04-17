#pragma once
#include "game_common.h"

class Tile : public Entity
{
public:
	explicit Tile(GameWindow& game_window);

};

class WaterTile : public Tile
{
public:

	explicit WaterTile(GameWindow& game_window);
};

class DirtTile : public Tile
{
public:

	explicit DirtTile(GameWindow& game_window);
};

class GrassTile : public Tile
{
public:
	explicit GrassTile(GameWindow& game_window);
};