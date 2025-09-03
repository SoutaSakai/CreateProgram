#pragma once
#include "..\scene.h"

class Gamemain : public IScene
{
public:
	Gamemain(void);
	~Gamemain(void) = default;

	void Initialize(void) override;
	void Update(void) override;
	void Draw(void) override;
	void Finalize(void) override;

private:
	struct UseCharacter
	{
		CHARACTER_ID* Character;
	};

	static const int		m_max_player;
	static const int		m_max_fish;
	static const float		m_water_surface;

	UseCharacter*	m_UseCharacter;

	//{ {CHARACTER_ID::TUNA,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY}/*,*/
	//	//{CHARACTER_ID::ELSCTRICEEL,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY},
	//	//{CHARACTER_ID::SHARK,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY},
	//	//{CHARACTER_ID::TURTLE,CHARACTER_ID::DUMMY,CHARACTER_ID::DUMMY}
	//};
};