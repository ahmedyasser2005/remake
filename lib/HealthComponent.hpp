#ifndef HEALTHCOMPONENT_HPP
#define HEALTHCOMPONENT_HPP

#include "Linker.hpp"

class HealthComponent {
private:

	uint16_t maxHealth;
	uint16_t currentHealth;

public:

	HealthComponent(uint16_t maxHealth = 100) : currentHealth(maxHealth), isDead(false) {
		if (maxHealth > 500 || maxHealth < 1)
			throw std::out_of_range("Error!, Max Health must be in between '1' to '500'");
	}

	void Damage(uint16_t amount);

	virtual void Down() = 0;

	const uint16_t& GetMaxHealth() const;
	const uint16_t& GetCurrentHealth() const;
	const float& GetHealthPercentage() const;

};

#endif // HEALTHCOMPONENT_HPP