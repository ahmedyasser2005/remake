#include "../lib/HealthComponent.hpp"

void HealthComponent::Damage(const uint16_t amount) {
	if (amount < 1 || amount > 500)
		throw std::out_of_range("Error!, Damage Amount must be in between '1' to '500'");

	else if (amount >= currentHealth) {
		currentHealth = 0;
		Down();
	}

	else
		currentHealth -= amount;
}

const uint16_t& HealthComponent::GetMaxHealth() const {
	return maxHealth;
}

const uint16_t& HealthComponent::GetCurrentHealth() const {
	return currentHealth;
}

const float& HealthComponent::GetHealthPercentage() const {
	return static_cast<float>(currentHealth / maxHealth) * 100;
}