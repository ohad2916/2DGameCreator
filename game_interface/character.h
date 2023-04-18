#pragma once
#include "game_common.h"

class Character : public Entity
{
public:
	Character(GameWindow& game_window, const std::string& name) : Entity(game_window, { 400,300,200,200 }, name)
	{
	}

	void LoadTextures(const std::string& asset_path)
	{
		for (const auto& entry : std::filesystem::directory_iterator(asset_path + m_name + "/idle"))
		{
			std::string image_path = entry.path().string();
			std::string image_name = image_path.substr(image_path.find_last_of('/') + 1, image_path.find_last_of('.') - image_path.find_last_of('/') - 1);
			m_idle_textures.push_back(IMG_LoadTexture(m_renderer, image_path.c_str()));
			if (m_idle_textures.back() == nullptr)
				std::cout << "Error loading texture!" << std::endl;
			else
				std::cout << "LOADED TEXTURE:" << image_name << std::endl;

		}
	}

	void Update() override
	{
		if (m_game_window.frame_number % 5 == 0)
		{
			m_base_texture = m_idle_textures[(m_animation_counter++) % m_idle_textures.size()];
			dest_rect.x += m_direction.x;
			dest_rect.y += m_direction.y;
			if (dest_rect.x < 0)
				dest_rect.x = 0;
			if (dest_rect.x > m_game_window.m_dimensions.w)
				dest_rect.x = m_game_window.m_dimensions.w - src_rect.w;
			if (dest_rect.y < 0)
				dest_rect.y = 0;
			if (dest_rect.y > m_game_window.m_dimensions.h)
				dest_rect.y = m_game_window.m_dimensions.h;

		}

	}


	std::vector<SDL_Texture*> m_idle_textures;
	std::vector<SDL_Texture*> m_run_textures;
	std::vector<SDL_Texture*> m_dead_textures;
protected:
	uint8_t m_animation_counter{ 0 };

};