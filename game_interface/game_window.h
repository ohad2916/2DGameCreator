#pragma once
#include "game_common.h"
class Entity;
class Map;

class GameWindow
{
public:
	GameWindow(dimensions dim, std::string asset_path, std::string title);


	virtual ~GameWindow() = default;

	GameWindow(const GameWindow&) = default;

	void Init(bool fullscreen_flag);
	

	void AddEntity(std::shared_ptr<Entity>& entity);

	void HandleEvents();

	void Update();

	void Render();

	void Run();

	void SetMap(std::shared_ptr<Map>& map);

	void Clean();

	bool IsRunning();

	SDL_Renderer* GetRenderer();

	virtual void HandleKeyDown(SDL_Event& event);

	virtual void HandleKeyUp(SDL_Event& event);

	SDL_Texture* GetTexture(const std::string& name);

	void LoadTextures();

	dimensions m_dimensions;
	uint64_t m_frame_number;
	std::string m_asset_path;

protected:
	std::string m_title = "A game Window";
	SDL_Window* m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;
	bool m_isRunning = false;
	uint16_t m_max_fps = 144;
	std::vector<std::shared_ptr<Entity>> m_entities;
	std::unordered_map<std::string, SDL_Texture*> m_textures;
	std::shared_ptr<Map> m_map;
	std::shared_ptr<Entity> m_main_entity;

};