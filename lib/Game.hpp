#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"

class Game {
private:
	
	sf::RenderWindow* m_Window;
	sf::Text* m_ShowSpeed;
	
	Player m_Player;
	


	sf::Clock m_Clock;
	float m_DeltaTime;

public:
	
	Game();
	~Game();

	void InitWindow();

	void DeltaTimeUpdate();
	void EventHandler();
	void Update();
	void Render();
	void Run();

};

#endif // GAME_HPP