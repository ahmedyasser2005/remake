#ifndef PLAYERSTATECONTROLLER_HPP
#define PLAYERSTATECONTROLLER_HPP

#include "../Linker.hpp"

enum States {
	Idle,
	Walking,
	Running,
	Down,
	Dead
};

class PlayerStateController {
private:

	State* state;

public:

	PlayerStateController();
	~PlayerStateController();

	void Init();
	void Update();
	void Transition(const States&);

};


#endif // PLAYERSTATECONTROLLER_HPP