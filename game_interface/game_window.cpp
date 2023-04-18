#include "game_common.h"


GameWindow::GameWindow(dimensions dim,std::string asset_path,std::string title = " Default")
	:m_dimensions(dim),m_asset_path(std::move(asset_path)),m_title(std::move(title))
{

}

void GameWindow::Init(bool fullscreen_flag)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) > 0)
	{
		std::cerr << "Couldn't initialize game engine Subsystem!\n";
		delete(this);
	}
	std::cout << "Successfully initialized window!\n ";
	const int window_flag = fullscreen_flag ? SDL_WINDOW_FULLSCREEN : 0;
	m_window = SDL_CreateWindow(m_title.c_str(),SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_dimensions.w,
		m_dimensions.h, window_flag);
	if (m_window)
		std::cout << "Created Window!\n";
	else
	{
		std::cerr << "Could not create Window!\n";
		delete(this);
	}
	m_renderer = SDL_CreateRenderer(m_window,-1,0);
	if (m_renderer)
		std::cout << "Created Renderer!\n";
	else
	{
		std::cerr << "Could not create Renderer!\n";
		delete(this);
	}


	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	std::cout << "loading textures!" << std::endl;
	LoadTextures();

	m_isRunning = true;
}

void GameWindow::AddEntity(std::shared_ptr<Entity>& entity)
{
	m_entities.push_back(entity);
}

void GameWindow::HandleEvents()
{

	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		m_isRunning = false;
		break;
	case SDL_KEYDOWN:
		HandleKeyDown(event);
		break;
	case SDL_KEYUP:
		HandleKeyUp(event);
		break;
	default:
		break;
	}

}

void GameWindow::Update()
{
	for (auto& entity : m_entities)
	{
		entity->Update();
	}
}

void GameWindow::Render()
{
	SDL_RenderClear(m_renderer);
	m_map->Render();
	for (auto& entity: m_entities)
	{
		entity->Render();
	}
	SDL_RenderPresent(m_renderer);

}

void GameWindow::Run()
{
	const float frame_delay = 1000 / m_max_fps;


	while (IsRunning())
	{
		if (++m_frame_number % 200 == 0)
			std::cout << "Frame number:" << m_frame_number << std::endl;
		uint32_t frame_start = SDL_GetTicks();

		HandleEvents();
		Update();
		Render();

		uint32_t frame_time = SDL_GetTicks() - frame_start;

		if (frame_delay > frame_time )
		{
			SDL_Delay(frame_delay - frame_time);
		}
		
	}
}

void GameWindow::SetMap(std::shared_ptr<Map>& map)
{
	m_map = map;
}

void GameWindow::Clean()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
	m_isRunning = false;
	std::cout << "Game Cleaned!\n";
}

bool GameWindow::IsRunning()
{
	return m_isRunning;
}

SDL_Renderer* GameWindow::GetRenderer()
{
	return m_renderer;
}

void GameWindow::HandleKeyDown(SDL_Event& event)
{
	switch(event.key.keysym.scancode)
	{
	case SDL_SCANCODE_UP:
		m_main_entity->Move({0,-1});
		break;
	case SDL_SCANCODE_DOWN:
		m_main_entity->Move({0,1});
		break;
	case SDL_SCANCODE_LEFT:
		m_main_entity->Move({ -1,0 });
		break;
	case SDL_SCANCODE_RIGHT:
		m_main_entity->Move({ 1,0 });
		break;
	}
}

void GameWindow::HandleKeyUp(SDL_Event& event)
{
	
}

SDL_Texture* GameWindow::GetTexture(const std::string& name)
{
	auto found = m_textures.find(name);
	if (found == m_textures.end())
		return m_textures["blank"];
	return found->second;
}

void GameWindow::LoadTextures()
{
	for (const auto& entry : std::filesystem::directory_iterator(m_asset_path + "generic/"))
	{
		std::string image_path = entry.path().string();
		std::string image_name = image_path.substr(image_path.find_last_of('/')+1, image_path.find_last_of('.') - image_path.find_last_of('/') - 1);
		m_textures[image_name] = IMG_LoadTexture(m_renderer,image_path.c_str());

	}

}

void GameWindow::SetMainEntity(const std::shared_ptr<Entity>& entity)
{
	m_main_entity = entity;
}
