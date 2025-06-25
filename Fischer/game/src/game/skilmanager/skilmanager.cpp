#include "skilmanager.h"

SkilManager& SkilManager::Getinstance(void)
{
	static SkilManager Instance;

	return Instance;
}

void SkilManager::Initialize(int PlayerNumber, CHARACTER_ID Character)
{
	switch (Character)
	{
	case CHARACTER_ID::DUMMY:
		break;
	case CHARACTER_ID::ELSCTRICEEL:
		elsctriceel[PlayerNumber]->Initialize();
		break;
	case CHARACTER_ID::PORCUPINEFISH:
		break;
	case CHARACTER_ID::SHARK:
		break;
	case CHARACTER_ID::LIONFISH:
		break;
	case CHARACTER_ID::MIRRORMORAYELL:
		break;
	case CHARACTER_ID::TURTLE:
		turtle[PlayerNumber]->Initialize();
		break;
	case CHARACTER_ID::OCTOPUS:
		break;
	case CHARACTER_ID::POINTUNA:
		break;
	case CHARACTER_ID::TUNA:
		tuna[PlayerNumber]->Initialize();
		break;
	default:
		break;
	}
}

vivid::Vector2 SkilManager::Update(int PlayerNumber, CHARACTER_ID Character, vivid::Vector2 Pos, float Angle, float ScaleX)
{
	switch (Character)
	{
	case CHARACTER_ID::DUMMY:
		break;
	case CHARACTER_ID::ELSCTRICEEL:
		elsctriceel[PlayerNumber]->Update(Pos);
		break;
	case CHARACTER_ID::PORCUPINEFISH:
		break;
	case CHARACTER_ID::SHARK:
		break;
	case CHARACTER_ID::LIONFISH:
		break;
	case CHARACTER_ID::MIRRORMORAYELL:
		break;
	case CHARACTER_ID::TURTLE:
		turtle[PlayerNumber]->Update(Pos);
		break;
	case CHARACTER_ID::OCTOPUS:
		break;
	case CHARACTER_ID::POINTUNA:
		break;
	case CHARACTER_ID::TUNA:
		return tuna[PlayerNumber]->Update(Pos,Angle,ScaleX);
		break;
	default:
		break;
	}
}

void SkilManager::Draw(void)
{
}

void SkilManager::CreateObj(int PlayerNumber, CHARACTER_ID Character)
{
	switch (Character)
	{
	case CHARACTER_ID::DUMMY:
		break;
	case CHARACTER_ID::ELSCTRICEEL:
		if (elsctriceel[PlayerNumber] == nullptr)elsctriceel[PlayerNumber] = new Elsctriceel();
		break;
	case CHARACTER_ID::PORCUPINEFISH:
		break;
	case CHARACTER_ID::SHARK:
		break;
	case CHARACTER_ID::LIONFISH:
		break;
	case CHARACTER_ID::MIRRORMORAYELL:
		break;
	case CHARACTER_ID::TURTLE:
		if (turtle[PlayerNumber] == nullptr)turtle[PlayerNumber] = new Turtle();
		break;
	case CHARACTER_ID::OCTOPUS:
		break;
	case CHARACTER_ID::POINTUNA:
		break;
	case CHARACTER_ID::TUNA:
		if (tuna[PlayerNumber] == nullptr)tuna[PlayerNumber] = new Tuna();
		break;
	default:
		break;
	}
}

void SkilManager::DeleteObj(void)
{
	for (int i = 0; i < MAXPlayer; i++)
	{
		if (elsctriceel[i] != nullptr)	delete elsctriceel[i];
		if (turtle[i] != nullptr)		delete turtle[i];
		if (tuna[i] != nullptr)			delete tuna[i];
	}
}
