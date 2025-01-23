#ifndef GAMESTATES_HPP
#define GAMESTATES_HPP

#include "../Linker.hpp"

class MenuState : public State {
public:

	MenuState();
	~MenuState();

	void Update() override;

};

class PlayState : public State {
public:

	PlayState();
	~PlayState();

	void Update() override;
};

class PauseState : public State {
public:

	PauseState();
	~PauseState();

	void Update() override;
};

#endif // GAMESTATES_HPP