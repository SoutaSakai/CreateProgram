#include "speed_type.h"
#include"../Player.h"

const float Speed_type::Speed_type_speed = 7.0f;
namespace keyboard = vivid::keyboard;






Speed_type::Speed_type()
	
{
}
void Speed_type::Initialize(void)
{
	vivid::Point m = vivid::mouse::GetCursorPos();

}

void Speed_type::Update(void)
{

	if (keyboard::Button(keyboard::KEY_ID::W))
	{
		Player_speed.y = -Speed_type_speed;

	}
	else if (keyboard::Button(keyboard::KEY_ID::S))
	{
		Player_speed.y = +Speed_type_speed;

	}
	else
	{
		Player_speed.y = 0.0f;
	}

	if (keyboard::Button(keyboard::KEY_ID::A))
	{
		Player_speed.x = -Speed_type_speed;


	}
	else if (keyboard::Button(keyboard::KEY_ID::D))
	{

		Player_speed.x = +Speed_type_speed;

	}
	else
	{
		Player_speed.x = 0.0f;
	}


}

void Speed_type::Draw(void)
{


}

void Speed_type::Finalize(void)
{


}
