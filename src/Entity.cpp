#include "../lib/Entity.hpp"

// Add this before the Player class
class Entity : public sf::Sprite {
public:
    virtual void Update(sf::Time dt) = 0; // Pure virtual function
    sf::Vector2f velocity;
    float speed = 100.0f;
};

// Enemy Class

class Enemy : public Entity {
public:
    void Initialize(const sf::Texture& texture, sf::Vector2f startPos) {
        setTexture(texture);
        setPosition(startPos);
        setOrigin(sf::Vector2f(texture.getSize()) / 2.0f);
    }

    void Update(sf::Time dt) override {
        // Example: Move toward the player
        sf::Vector2f direction = targetPosition - getPosition();
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        if (length > 0.001f) direction /= length;

        velocity = direction * speed;
        move(velocity * dt.asSeconds());
    }

    sf::Vector2f targetPosition; // Would point to player's position
};
