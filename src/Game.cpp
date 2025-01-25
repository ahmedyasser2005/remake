#include "../lib/Game.hpp"

const std::filesystem::path FONT_PATH = "C:\\Users\\ahmed\\OneDrive\\Desktop\\Zombie Escape CO-OP Indie Game\\assets\\fonts\\calibri.ttf";
const sf::Font FONT(FONT_PATH);

Game::Game(): m_Window(nullptr), m_ShowSpeed(nullptr) {
	this->InitWindow();
    m_ShowSpeed = new sf::Text(FONT);
    m_ShowSpeed->setPosition({ static_cast<float>(this->m_Window->getSize().x) / 2.f, 0.f });
}



Game::~Game() {
    delete this->m_ShowSpeed;
    delete this->m_Window;
}



/*
    Initilizing game window settings such as dimentions, max framerate, vsync on off...
*/
void Game::InitWindow() {

    std::string key;
    uint16_t framerate = 144;
    bool vSyncEnable = false;
    sf::Vector2u WindowSize = { 1920, 1080 };

    std::ifstream file("../config/m_Window.ini");
    if (file.is_open()) {
        while (!file.eof()) {
            file >> key;

            if (key == "WIDTH_HEIGHT") {
                file >> WindowSize.x;
                file >> WindowSize.y;
            }
            else if (key == "MAX_FRAMERATE")
                file >> framerate;
            else if (key == "ENABLE_VSYNC")
                file >> vSyncEnable;
        }
    }

    this->m_Window = new sf::RenderWindow(sf::VideoMode(WindowSize), "Zombie Escape CO-OP Indie Game");

    this->m_Window->setFramerateLimit(framerate);
    this->m_Window->setVerticalSyncEnabled(vSyncEnable);

}


/*
    Delta time is the time taken to transition from one frame to the next one.
    When it comes to movements and speed etc.
    you have to multiply deltaTime with the speed.

    High FPS -> Low DeltaTime
    Low FPS -> High DeltaTime
*/
void Game::DeltaTimeUpdate() {
    this->m_DeltaTime = this->m_Clock.restart().asSeconds();
    std::cout << this->m_DeltaTime << std::endl;
}



/*
    Catches events.
*/
void Game::EventHandler() {
    while (const std::optional event = this->m_Window->pollEvent()) {

        if (event->is<sf::Event::Closed>())
            this->m_Window->close();

        if (auto key = event->getIf<sf::Event::KeyPressed>()) {
            switch (key->scancode) {
            case (sf::Keyboard::Scancode::W):
                this->m_Player.m_isMovingUp = true;
                break;

            case (sf::Keyboard::Scancode::A):
                this->m_Player.m_isMovingLeft = true;
                break;

            case (sf::Keyboard::Scancode::S):
                this->m_Player.m_isMovingDown = true;
                break;

            case (sf::Keyboard::Scancode::D):
                this->m_Player.m_isMovingRight = true;
                break;
            case (sf::Keyboard::Scancode::LShift):
                this->m_Player.m_isRunning = true;
                break;
            }
        }

        if (auto key = event->getIf<sf::Event::KeyReleased>()) {
            switch (key->scancode) {
            case (sf::Keyboard::Scancode::W):
                this->m_Player.m_isMovingUp = false;
                break;

            case (sf::Keyboard::Scancode::A):
                this->m_Player.m_isMovingLeft = false;
                break;

            case (sf::Keyboard::Scancode::S):
                this->m_Player.m_isMovingDown = false;
                break;

            case (sf::Keyboard::Scancode::D):
                this->m_Player.m_isMovingRight = false;
                break;
            case (sf::Keyboard::Scancode::LShift):
                this->m_Player.m_isRunning = false;
                break;
            }
        }

    }
}


void Game::Render() {
    this->m_Player.Render(this->m_Window);
    this->m_Window->draw(*this->m_ShowSpeed);
}



/*
    Game Loop that keeps game running.
*/
void Game::Update() {

    this->DeltaTimeUpdate();

    this->EventHandler();

    this->m_Player.Update(m_DeltaTime);

    m_ShowSpeed->setString(std::to_string(m_Player.GetSpeed()));

    this->m_Window->clear();
    this->Render();
    this->m_Window->display();

}



/*
    Start the first frame of the game.
*/
void Game::Run() {
    while (this->m_Window->isOpen())
        this->Update();
}