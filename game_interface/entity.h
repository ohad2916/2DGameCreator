#pragma once
#include "game_common.h"
class GameWindow;
class Vector2;
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

	void LoadTextures();

	void SetRenderer(SDL_Renderer* renderer);

protected:
	GameWindow& m_game_window;
	dimensions m_dim;
	std::string m_name;
	SDL_Renderer* m_renderer = nullptr;
	SDL_Rect src_rect;
	SDL_Rect dest_rect;
	SDL_Texture* m_base_texture;
	Vector2 m_direction;
	std::vector<SDL_Texture*> m_idle_textures;
	std::vector<SDL_Texture*> m_moving_textures;
	float m_velocity;
	size_t m_animation_counter{0};
	

};
