#include "../../lib/States/GameStateController.hpp"

void GameStateController::Init() {
	gameStates.push(new MenuState());
}

void GameStateController::Update() const {
	gameStates.top->Update();
}

void GameStateController::Transition(const state& choice) {
	switch (choice) {
	case (state::Play):
		gameStates.push(new PlayState());
		break;
	
	case (state::Pause):
		gameStates.push(new PauseState());
		break;

	case (state::Back):
		while (gameStates.size() != 1)
			delete gameStates.top();
			gameStates.pop();
		break;

	case (state::Exit):
		while (gameStates)
			delete gameStates.top();
			gameStates.pop();
		break;
	}
}

const state& GameStateController::GetCurrentState() const {
	return *gameStates.top();
}


