#pragma once
#include "game_common.h"
class GameWindow;

class Entity
{
public:
	Entity(GameWindow& game_window, const dimensions dim, const std::string& name = "blank");

	// for tile creation

	Entity(GameWindow& game_window);

	virtual ~Entity() = default;

	Entity(const Entity&) = default;

	virtual void Update();

	void Render();

	void Reposition(uint32_t x, uint32_t y);

	void Move();

	void UpdateSrcRect(dimensions dim);

	void UpdateDestRectFromDim();


	void SetRenderer(SDL_Renderer* renderer);

protected:
	GameWindow& m_game_window;
	dimensions m_dim;
	std::string m_name;
	SDL_Renderer* m_renderer = nullptr;
	SDL_Rect src_rect;
	SDL_Rect dest_rect;
	SDL_Texture* m_texture;
	Vector2<int> m_direction;
	float m_velocity;
	

};
