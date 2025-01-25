#include "../lib/Player.hpp"

Player::Player() : Entity("uNluCky"),
	m_Character({ 100.f, 100.f }),

	m_WalkingVelocity(300.f),
	m_RunningVelocity(500.f),
	m_Acceleration(9.8f),
	m_CurrentXVelocity(0.f),
	m_CurrentYVelocity(0.f),
	m_Stamina(10.f)

{
	m_isMovingUp	= false;
	m_isMovingLeft	= false;
	m_isMovingDown	= false;
	m_isMovingRight	= false;

	m_isIdle		= true;
	m_isRunning		= false;
}

Player::~Player()
{
}

void Player::Update(const float& dt) {

	const float MAX_SPEED = (m_isRunning ? m_RunningVelocity : m_WalkingVelocity);


// X Axis ------------------------------------------------------------------------------------------
	if (m_CurrentXVelocity && !(m_isMovingLeft || m_isMovingRight)) {
		if (m_CurrentXVelocity < 0) {	// Moving Left
			if (m_CurrentXVelocity + m_Acceleration >= 0)
				m_CurrentXVelocity = 0;
			else
				m_CurrentXVelocity += m_Acceleration;
		}
		else if (m_CurrentXVelocity > 0) {	// Moving Right
			if (m_CurrentXVelocity - m_Acceleration <= 0)
				m_CurrentXVelocity = 0;
			else
				m_CurrentXVelocity -= m_Acceleration;
		}
	}
// Y Axis ------------------------------------------------------------------------------------------
	if (m_CurrentYVelocity && !(m_isMovingUp || m_isMovingDown)) {
		if (m_CurrentYVelocity < 0) {	// Moving Up
			if (m_CurrentYVelocity + m_Acceleration >= 0)
				m_CurrentYVelocity = 0;
			else
				m_CurrentYVelocity += m_Acceleration;
		}
		else if (m_CurrentYVelocity > 0) {	// Moving Down
			if (m_CurrentYVelocity - m_Acceleration <= 0)
				m_CurrentYVelocity = 0;
			else
				m_CurrentYVelocity -= m_Acceleration;
		}
	}

	if (m_isMovingUp) {
		if (m_CurrentYVelocity - m_Acceleration <= -MAX_SPEED)
			m_CurrentYVelocity = -MAX_SPEED;
		else
			m_CurrentYVelocity -= m_Acceleration;
	}
	if (m_isMovingLeft) {
		if (m_CurrentXVelocity - m_Acceleration <= -MAX_SPEED)
			m_CurrentXVelocity = -MAX_SPEED;
		else
			m_CurrentXVelocity -= m_Acceleration;
	}
	if (m_isMovingDown) {
		if (m_CurrentYVelocity + m_Acceleration >= MAX_SPEED)
			m_CurrentYVelocity = MAX_SPEED;
		else
			m_CurrentYVelocity += m_Acceleration;
	}
	if (m_isMovingRight) {
		if (m_CurrentXVelocity + m_Acceleration >= MAX_SPEED)
			m_CurrentXVelocity = MAX_SPEED;
		else
			m_CurrentXVelocity += m_Acceleration;
	}

	// Compute the total movement vector
	const float LENGTH = GetSpeed();

	// Normalize if moving diagonally
	if (GetSpeed() > MAX_SPEED) {
		m_CurrentXVelocity = (m_CurrentXVelocity / LENGTH) * MAX_SPEED;
		m_CurrentYVelocity = (m_CurrentYVelocity / LENGTH) * MAX_SPEED;
	}
	
	m_Character.move({ m_CurrentXVelocity * dt, m_CurrentYVelocity * dt });
}


const float& Player::GetSpeed() const {
	return std::sqrt(m_CurrentXVelocity * m_CurrentXVelocity + m_CurrentYVelocity * m_CurrentYVelocity);
}

void Player::Render(sf::RenderWindow* window)
{
	if (window)
		window->draw(m_Character);
	else
		throw std::runtime_error("No window to render character sprite!");
}
