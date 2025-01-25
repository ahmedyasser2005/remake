#ifndef ENTITY_HPP
#define ENTITY_HPP

// Internal
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <cmath>

// SFML
#include <SFML/Graphics.hpp>

class Entity {
protected:
	std::string		m_Name;
	uint16_t		m_CurrentHealth;
	const uint16_t	m_MaxHealth;

	Entity(std::string name);

	virtual void Update(const float& dt) = 0;

	//virtual void Idle() = 0;
	//virtual void Walk() = 0;
	//virtual void Run() = 0;
	//virtual void Die() = 0;
};

#endif // ENTITY_HPP