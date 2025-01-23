#ifndef STATE_HPP
#define STATE_HPP

#include "Linker.hpp"

class State {
public:
	virtual void Update() = 0;
};

#endif // STATE_HPP