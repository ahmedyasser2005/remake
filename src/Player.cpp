#include "../lib/Player.hpp"

Player::Player() : 
	name("Player"),
	isIdle(true), isWalking(false), isRunning(false), isReviving(false),
	isDown(false), isDead(false),
	cash(0), // uint16_t max value 65,535
	level(1), xp(0),
	stamina(100)
{}

Player::~Player() {
}

void Player::Update(sf::RenderWindow* window) {
	window->draw(body);
}

void Player::Down(float timeToDie) {

	isIdle = false;
	isWalking = false;
	isRunning = false;
	isReviving = false;
	isDead = false;

	isDown = true;

	while (isDown) {
		if (!timeToDie--) {
			isDown = false;
			isDead = true;
		}
	}

}

void Player::Move() {


}