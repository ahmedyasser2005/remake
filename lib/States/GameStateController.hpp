#ifndef GAMESTATECONTROLLER_HPP
#define GAMESTATECONTROLLER_HPP

#include "../Linker.hpp"

enum state {
	Play,
	Pause,
	Back,
	Exit
};

class GameStateController {
private:

	std::stack<State*> gameStates;

public:

	void Init();
	void Update() const;
	void Transition(const state&);
	const State& GetCurrentState() const;

};

#endif // GAMESTATECONTROLLER_HPP