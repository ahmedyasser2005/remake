#include "../lib/Player.hpp"

Player::Player() : Entity("uNluCky"),
	m_Character({ 100.f, 100.f }),
	m_WalkingVelocity(300.f),
	m_RunningVelocity(500.f),
	m_Acceleration(9.8f),
	m_CurrentVelocity({ 0.f, 0.f }),
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

void Player::Update(const float& dt)
{
	Movements(dt);
}

void Player::VelocityUpdate()
{
	if (m_CurrentVelocity.y && !(m_isMovingUp || m_isMovingDown))
	{
		if (m_CurrentVelocity.y < 0) // Moving Up
		{
			if (m_CurrentVelocity.y + m_Acceleration >= 0)
				m_CurrentVelocity.y = 0;
			else
				m_CurrentVelocity.y += m_Acceleration;
		}
		else if (m_CurrentVelocity.y > 0)	// Moving Down
		{
			if (m_CurrentVelocity.y - m_Acceleration <= 0)
				m_CurrentVelocity.y = 0;
			else
				m_CurrentVelocity.y -= m_Acceleration;
		}
	}
}

/*
	Controls player's movements.
	It contains Velocity(direction & speed) and Acceleration.

	It takes delta time as an argument.
	It returns nothing.

	must be updated each frame.
*/
void Player::Movements(const float& dt)
{

	const float MAX_SPEED = (m_isRunning ? m_RunningVelocity : m_WalkingVelocity);


	// X Axis ------------------------------------------------------------------------------------------
	if (m_CurrentVelocity.x && !(m_isMovingLeft || m_isMovingRight))
	{
		if (m_CurrentVelocity.x < 0)		// Moving Left
		{
			if (m_CurrentVelocity.x + m_Acceleration >= 0)
				m_CurrentVelocity.x = 0;
			else
				m_CurrentVelocity.x += m_Acceleration;
		}
		else if (m_CurrentVelocity.x > 0)	// Moving Right
		{
			if (m_CurrentVelocity.x - m_Acceleration <= 0)
				m_CurrentVelocity.x = 0;
			else
				m_CurrentVelocity.x -= m_Acceleration;
		}
	}
	// Y Axis ------------------------------------------------------------------------------------------
	if (m_CurrentVelocity.y && !(m_isMovingUp || m_isMovingDown))
	{
		if (m_CurrentVelocity.y < 0) // Moving Up
		{
			if (m_CurrentVelocity.y + m_Acceleration >= 0)
				m_CurrentVelocity.y = 0;
			else
				m_CurrentVelocity.y += m_Acceleration;
		}
		else if (m_CurrentVelocity.y > 0)	// Moving Down
		{
			if (m_CurrentVelocity.y - m_Acceleration <= 0)
				m_CurrentVelocity.y = 0;
			else
				m_CurrentVelocity.y -= m_Acceleration;
		}
	}

	if (m_isMovingUp)
	{
		if (m_CurrentVelocity.y - m_Acceleration <= -MAX_SPEED)
			m_CurrentVelocity.y = -MAX_SPEED;
		else
			m_CurrentVelocity.y -= m_Acceleration;
	}
	if (m_isMovingLeft)
	{
		if (m_CurrentVelocity.x - m_Acceleration <= -MAX_SPEED)
			m_CurrentVelocity.x = -MAX_SPEED;
		else
			m_CurrentVelocity.x -= m_Acceleration;
	}
	if (m_isMovingDown)
	{
		if (m_CurrentVelocity.y + m_Acceleration >= MAX_SPEED)
			m_CurrentVelocity.y = MAX_SPEED;
		else
			m_CurrentVelocity.y += m_Acceleration;
	}
	if (m_isMovingRight)
	{
		if (m_CurrentVelocity.x + m_Acceleration >= MAX_SPEED)
			m_CurrentVelocity.x = MAX_SPEED;
		else
			m_CurrentVelocity.x += m_Acceleration;
	}

	// Compute the total movement vector
	const float LENGTH = GetSpeed();

	// Normalize if moving diagonally
	if (GetSpeed() > MAX_SPEED)
	{
		m_CurrentVelocity.x = (m_CurrentVelocity.x / LENGTH) * MAX_SPEED;
		m_CurrentVelocity.y = (m_CurrentVelocity.y / LENGTH) * MAX_SPEED;
	}

	m_Character.move({ m_CurrentVelocity.x * dt, m_CurrentVelocity.y * dt });
}


const float& Player::GetSpeed() const
{
	return std::sqrt(m_CurrentVelocity.x * m_CurrentVelocity.x + m_CurrentVelocity.y * m_CurrentVelocity.y);
}

void Player::Render(sf::RenderWindow* window)
{
	if (window)
		window->draw(m_Character);
	else
		throw std::runtime_error("No window to render character sprite!");
}
