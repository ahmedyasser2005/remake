#ifndef GAME_HPP
#define GAME_HPP

#include "Linker.hpp"

class Game {
private:
	
	sf::RenderWindow* window;
	sf::Clock deltaTime;


public:
	
	Game();
	~Game();

	void InitWindow();
	void DeltaTimeUpdate();
	void EventHandler();
	void Update();
	void Run();

};

#endif // GAME_HPP