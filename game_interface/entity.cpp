#include "game_common.h"

Entity::Entity(GameWindow& game_window, const dimensions dim, const std::string& name)
	:m_game_window(game_window),m_dim(dim),m_name(name)
{
	m_renderer = game_window.GetRenderer();
	m_base_texture = game_window.GetTexture(name);
	LoadTextures();
	UpdateDestRectFromDim();
}

// for tile creation

Entity::Entity(GameWindow&  game_window)
	:m_game_window(game_window)
{

}

void Entity::LoadTextures()
{
	for (const auto& entry : std::filesystem::directory_iterator(m_game_window.m_asset_path +  m_name + "/Idle"))
	{
		std::string image_path = entry.path().string();
		std::string image_name = image_path.substr(image_path.find_last_of('/') + 1, image_path.find_last_of('.') - image_path.find_last_of('/') - 1);
		m_idle_textures.push_back(IMG_LoadTexture(m_renderer, image_path.c_str()));
	}
}

void Entity::Update()
{
	if(m_game_window.m_frame_number % 12 == 0)
	{
		m_base_texture = m_idle_textures[m_animation_counter++ % m_idle_textures.size()];
	}
}

void Entity::Render()
{
	SDL_RenderCopy(m_renderer, m_base_texture, &src_rect, &dest_rect);
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


