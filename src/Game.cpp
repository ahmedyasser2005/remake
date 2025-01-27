class Game {
public:
    Game() : window(sf::VideoMode(1280, 720), "SFML Shooter") {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        window.setFramerateLimit(60);
        loadResources();
        spawnEntities();
    }

    void run() {
        sf::Clock clock;
        while (window.isOpen()) {
            sf::Time dt = clock.restart();
            handleInput();
            update(dt);
            render();
        }
    }

private:
    sf::RenderWindow window;
    sf::Font font;
    
    // Resources
    sf::Texture playerTex;
    sf::Texture enemyTex;
    sf::Texture shooterTex;
    sf::Texture bulletTex;
    
    // Sound
    sf::SoundBuffer shootSound;
    sf::SoundBuffer hitSound;
    sf::Sound sound;
    
    // Entities
    Player player;
    std::vector<std::unique_ptr<Entity>> enemies;
    std::vector<std::unique_ptr<Entity>> bullets;
    std::vector<Particle> particles;
    
    // Game state
    int score = 0;

    void loadResources() {
        // Load textures with relative paths
        if (!playerTex.loadFromFile("player.png")) 
            std::cerr << "Missing player.png! Place in executable folder.\n";
        if (!enemyTex.loadFromFile("enemy.png")) 
            std::cerr << "Missing enemy.png! Place in executable folder.\n";
        if (!shooterTex.loadFromFile("shooter.png")) 
            std::cerr << "Missing shooter.png! Place in executable folder.\n";
        if (!bulletTex.loadFromFile("bullet.png")) 
            std::cerr << "Missing bullet.png! Place in executable folder.\n";

        // Load font
        if (!font.loadFromFile("arial.ttf")) {
            std::cerr << "Using fallback font.\n";
            font.loadFromMemory(&arial_ttf, arial_ttf_size); // Implement fallback
        }

        // Load sounds
        if (!shootSound.loadFromFile("shoot.wav")) 
            std::cerr << "Missing shoot.wav!\n";
        if (!hitSound.loadFromFile("hit.wav")) 
            std::cerr << "Missing hit.wav!\n";
    }

    void spawnEntities() {
        player.Initialize(playerTex);
        player.setPosition(640, 360);

        // Spawn enemies
        for (int i = 0; i < 5; ++i) {
            auto enemy = std::make_unique<ChasingEnemy>();
            enemy->Initialize(enemyTex, sf::Vector2f(100.f * i, 100.f));
            enemies.push_back(std::move(enemy));
        }

        // Spawn shooting enemies
        for (int i = 0; i < 3; ++i) {
            auto shooter = std::make_unique<ShootingEnemy>();
            shooter->Initialize(shooterTex, bulletTex, sf::Vector2f(1200.f - i*100, 600.f));
            enemies.push_back(std::move(shooter));
        }
    }

    void handleInput() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
