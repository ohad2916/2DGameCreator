#include <game_common.h>

#ifdef main
#undef main
#endif


class ExampleGameWindow : public GameWindow
{
public:
	ExampleGameWindow(dimensions dim, std::string asset_path, std::string title = "A game") : GameWindow(dim, asset_path,title)
	{
		
	}
};

int main()
{
	dimensions window_dim = {0, 0, 640, 800};
	std::string asset_path = "assets/";
	ExampleGameWindow ex_game(window_dim,asset_path,"a game");

	uint8_t ex_map[20][25] = {
							{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							{2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};

	ex_game.Init(false);
	Map map(ex_map,ex_game, 25, 20);
	ex_game.SetMap(&map);

	Entity zombie{ ex_game,{0,0,64,64},"zombie"};
	Entity zombie2{ ex_game,{80,80,64,64},"zombie"};
	Entity blank{ ex_game,{200,200,100,100},"sadas" };

	zombie.UpdateSrcRect({0, 0, 847, 604});
	zombie2.UpdateSrcRect({0, 0, 847, 604});
	blank.UpdateSrcRect({ 0,0,500,500});
	ex_game.AddEntity(std::move(zombie));
	ex_game.AddEntity(std::move(zombie2));
	
	ex_game.AddEntity(std::move(blank));
	

	ex_game.Run();

	ex_game.Clean();

	return 0;

}