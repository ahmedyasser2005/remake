class Player : public sf::Sprite {
  // ... (private variables)
public:
  void Initialize(const sf::Texture& texture, sf::Vector2f startPos) {
    setTexture(texture);       // Assign texture to the sprite
    setPosition(startPos);     // Set starting position
    setOrigin(texture.getSize() / 2.f); // Center the sprite
  }

  void UpdateMovementState(sf::Time dt, bool isSprinting, sf::Vector2f direction) {
    // Handle movement logic:
    // - Update velocity based on input direction and sprinting
    // - Rotate the sprite toward movement direction
    // - Change state (Idle/Walk/Run)
  }

  void Draw(sf::RenderWindow& window) {
    window.draw(*this); // Render the sprite to the window
  }
};
