#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"

class Player : private Entity {
private:

	/*
		std::string		m_Name;
		uint16_t		m_CurrentHealth;
		const uint16_t	m_MaxHealth;

		Entity(std::string name);
	*/

	sf::RectangleShape m_Character;

	float m_WalkingVelocity;
	float m_RunningVelocity;
	const float m_Acceleration;
	float m_CurrentXVelocity;
	float m_CurrentYVelocity;
	uint16_t m_Stamina;

public:
	
	bool m_isMovingUp;
	bool m_isMovingLeft;
	bool m_isMovingDown;
	bool m_isMovingRight;

	bool m_isIdle;
	bool m_isRunning;
	
	Player();
	~Player();

	void Init();

	/*
		updates the player's position based on movement inputs and speed
		which varies depending on whether the player is running or walking
		and takes a time delta parameter to ensure smooth movement for everyone.
	*/
	void Update(const float& dt) override;

	//void Idle() override;
	//void Walk() override;
	//void Run() override;
	//void Die() override;

	const float& GetSpeed() const;

	void Render(sf::RenderWindow* window);

};

#endif // PLAYER_HPP