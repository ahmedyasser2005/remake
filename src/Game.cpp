class Game {
private:
  sf::RenderWindow window;     // SFML window object
  sf::Texture playerTexture;   // Texture for the player sprite
  Player player;               // Player instance

public:
  void Run() {
    window.create(sf::VideoMode(1280, 720), "Shooter Game"); // Create window
    window.setFramerateLimit(60); // Cap at 60 FPS

    // Load player texture
    if (!playerTexture.loadFromFile("player.png")) {
      std::cerr << "Error: Missing player.png!\n"; // Error handling
      return;
    }

    player.Initialize(playerTexture, sf::Vector2f(640, 360)); // Initialize player

    sf::Clock clock; // Game clock
    while (window.isOpen()) { // Main game loop
      sf::Time dt = clock.restart(); // Calculate delta time
      ProcessInput();  // Handle events (e.g., window close)
      Update(dt);      // Update game state (player movement)
      Render();        // Draw everything
    }
  }

private:
  void ProcessInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close(); // Close window when user clicks X
    }
  }

  void Update(sf::Time dt) {
    // Get keyboard input:
    bool sprinting = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
    sf::Vector2f direction(
      sf::Keyboard::isKeyPressed(sf::Keyboard::D) - 
      sf::Keyboard::isKeyPressed(sf::Keyboard::A), // X-axis (A/D)
      sf::Keyboard::isKeyPressed(sf::Keyboard::S) - 
      sf::Keyboard::isKeyPressed(sf::Keyboard::W)  // Y-axis (W/S)
    );

    // Normalize direction vector to prevent diagonal speed boost
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length > 0) direction /= length;

    player.UpdateMovementState(dt, sprinting, direction); // Update player
  }

  void Render() {
    window.clear(sf::Color(30, 30, 30)); // Dark gray background
    player.Draw(window);                 // Draw player
    window.display();                    // Show rendered frame
  }
};
