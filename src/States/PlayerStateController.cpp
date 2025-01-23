#include "../../lib/States/PlayerStateController.hpp"

PlayerStateController::PlayerStateController() {
	Init();
}

PlayerStateController::~PlayerStateController() {
	delete state;
}

void PlayerStateController::Init() {
	state = new IdleState();
}

void PlayerStateController::Update() {
	state->Update();
}

void PlayerStateController::Transition(const States& newState) {
	
	delete state;
	
	switch (newState) {
	case (States::Idle):
		state = new IdleState();
		break;
	
	case (States::Walking):
		state = new WalkState();
		break;

	case (States::Running):
		state = new RunState();
		break;
	
	case (States::Down):
		state = new DownState();
		break;
	
	case (States::Dead):
		state = new DeadState();
		break;
	}

}

