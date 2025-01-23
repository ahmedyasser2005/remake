#include "../lib/Game.hpp"

Game::Game() {
	InitWindow();
}

Game::~Game() {
	delete window;
}

void Game::InitWindow() {

    window = new sf::RenderWindow(sf::VideoMode({ 1920u, 1080u }), "Zombie Escape CO-OP Indie Game");
    window->setFramerateLimit(144);
    window->setVerticalSyncEnabled(false);

}

void Game::DeltaTimeUpdate() {
    float dt = deltaTime.restart().asSeconds();
    std::cout << dt << std::endl;
}

void Game::EventHandler() {
    while (const std::optional event = window->pollEvent()) {

        if (event->is<sf::Event::Closed>())
            window->close();
        


    }
}

void Game::Update() {

    DeltaTimeUpdate();
    
    EventHandler();

    window->clear();


    window->display();

}

void Game::Run() {
    while (window->isOpen())
        Update();
}