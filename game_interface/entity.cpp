#include "game_common.h"

Entity::Entity(GameWindow& game_window, const dimensions dim, const std::string& name)
	:m_game_window(game_window),m_dim(dim),m_name(name)
{
	m_renderer = game_window.GetRenderer();
	m_texture = game_window.GetTexture(name);
	UpdateDestRectFromDim();
}

// for tile creation

Entity::Entity(GameWindow&  game_window)
	:m_game_window(game_window)
{

}


void Entity::Update()
{

}

void Entity::Render()
{
	SDL_RenderCopy(m_renderer, m_texture, &src_rect, &dest_rect);
}

void Entity::Reposition(uint32_t x, uint32_t y)
{
	dest_rect.x = x;
	dest_rect.y = y;
}

void Entity::Move()
{

}


void Entity::UpdateSrcRect(dimensions dim)
{
	src_rect.x = dim.x;
	src_rect.y = dim.y;
	src_rect.h = dim.h;
	src_rect.w = dim.w;
}
void Entity::UpdateDestRectFromDim()
{
	dest_rect.x = m_dim.x;
	dest_rect.y = m_dim.y;
	dest_rect.h = m_dim.h;
	dest_rect.w = m_dim.w;
}


void Entity::SetRenderer(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}


