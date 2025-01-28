#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"

class Player : private Entity
{
private:

	/*
		Hey don't uncomment this,
		it just a referece to tell that
		these member data and methods
		exist inside the Entity class and was inherited here!


		std::string		m_Name;
		uint16_t		m_CurrentHealth;
		const uint16_t	m_MaxHealth;

		Entity(std::string name);
	*/

	sf::RectangleShape m_Character;

	const float m_Acceleration;

	float m_WalkingVelocity;
	float m_RunningVelocity;
	sf::Vector2f m_CurrentVelocity;
	
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

	void VelocityUpdate();
	void Movements(const float& dt) override;

	const float& GetSpeed() const;

	void Render(sf::RenderWindow* window);

};

#endif // PLAYER_HPP