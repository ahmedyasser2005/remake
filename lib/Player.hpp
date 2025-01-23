#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Linker.hpp"

class Player : public MovementsComponent, public HealthComponent {
private:

	std::string name;
	sf::Sprite body;

	bool isIdle, isWalking, isRunning, isReviving;
	bool isDown, isDead;
	//bool isShooting, isReloading;

	uint16_t cash; // uint16_t max value 65,535
	uint16_t level, xp;
	uint16_t stamina;
	
public:

	Player();
	~Player();

	//void LoadPlayerData();
	
	void Update(sf::RenderWindow*);
	
	void Down(float);

	void Move();
	void Do();

};

#endif // PLAYER_HPP