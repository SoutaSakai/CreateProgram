#include "Charactermanager.h"

//Elsctriceel		電気うなぎ
const float CharacterManager::ElsctriceelWIDTH = 200;
const float CharacterManager::ElsctriceelHEIGHT = 30;
const float CharacterManager::ElsctriceelSpeed = 5;
const vivid::Rect CharacterManager::ElsctriceelRect = { 0,0,ElsctriceelWIDTH,ElsctriceelHEIGHT };
const std::string CharacterManager::ElsctriceelFilePath = "data\\Elsctriceel.png";
const vivid::Vector2 CharacterManager::ElsctriceelMouthPos = { 0,0 };
const float CharacterManager::ElsctriceelMouthRadius = 0;

//Porcupinefish		ハリセンボン
const float CharacterManager::PorcupinefishWIDTH = 80;
const float CharacterManager::PorcupinefishHEIGHT = 70;
const float CharacterManager::PorcupinefishSpeed = 5;
const vivid::Rect CharacterManager::PorcupinefishRect = { 0,0,PorcupinefishWIDTH,PorcupinefishHEIGHT };
const std::string CharacterManager::PorcupinefishFilePath = "data\\Porcupinefish.png";
const vivid::Vector2 CharacterManager::PorcupinefishMouthPos = { 0,0 };
const float CharacterManager::PorcupinefishMouthRadius = 0;

//Shark				サメ
const float CharacterManager::SharkWIDTH = 210;
const float CharacterManager::SharkHEIGHT = 80;
const float CharacterManager::SharkSpeed = 5;
const vivid::Rect CharacterManager::SharkRect = { 0,0,SharkWIDTH ,SharkHEIGHT };
const std::string CharacterManager::SharkFilePath = "data\\Shark.png";
const vivid::Vector2 CharacterManager::SharkMouthPos = { 0,0 };
const float CharacterManager::SharkMouthRadius = 0;

//Lionfish			ミノカサゴ
const float CharacterManager::LionfishWIDTH = 90;
const float CharacterManager::LionfishHEIGHT = 90;
const float CharacterManager::LionfishSpeed = 5;
const vivid::Rect CharacterManager::LionfishRect = { 0,0,LionfishWIDTH ,LionfishHEIGHT };
const std::string CharacterManager::LionfishFilePath = "data\\Lionfish.png";
const vivid::Vector2 CharacterManager::LionfishMouthPos = { 0,0 };
const float CharacterManager::LionfishMouthRadius = 0;

//Mirrormoray		ミラーウツボ
const float CharacterManager::MirrormorayellWIDTH = 170;
const float CharacterManager::MirrormorayellHEIGHT = 50;
const float CharacterManager::MirrormorayellSpeed = 5;
const vivid::Rect CharacterManager::MirrormorayellRect = { 0,0,MirrormorayellWIDTH ,MirrormorayellHEIGHT };
const std::string CharacterManager::MirrormorayellFilePath = "data\\Mirrormoray.png";
const vivid::Vector2 CharacterManager::MirrormorayellMouthPos = { 0,0 };
const float CharacterManager::MirrormorayellMouthRadius = 0;

//Turtle			カメ
const float CharacterManager::TurtleWIDTH = 130;
const float CharacterManager::TurtleHEIGHT = 90;
const float CharacterManager::TurtleSpeed = 5;
const vivid::Rect CharacterManager::TurtleRect = { 0,0,TurtleWIDTH ,TurtleHEIGHT };
const std::string CharacterManager::TurtleFilePath = "data\\Turtle.png";
const vivid::Vector2 CharacterManager::TurtleMouthPos = { 0,0 };
const float CharacterManager::TurtleMouthRadius = 0;

//Octopus			タコ
const float CharacterManager::OctopusWIDTH = 80;
const float CharacterManager::OctopusHEIGHT = 90;
const float CharacterManager::OctopusSpeed = 5;
const vivid::Rect CharacterManager::OctopusRect = { 0,0,OctopusWIDTH ,OctopusHEIGHT };
const std::string CharacterManager::OctopusFilePath = "data\\Octopus.png";
const vivid::Vector2 CharacterManager::OctopusMouthPos = { 0,0 };
const float CharacterManager::OctopusMouthRadius = 0;

//Pointuna			ポインツナ
const float CharacterManager::PointunaWIDTH = 150;
const float CharacterManager::PointunaHEIGHT = 80;
const float CharacterManager::PointunaSpeed = 5;
const vivid::Rect CharacterManager::PointunaRect = { 0,0,PointunaWIDTH ,PointunaHEIGHT };
const std::string CharacterManager::PointunaFilePath = "data\\Pointuna.png";
const vivid::Vector2 CharacterManager::PointunaMouthPos = { 0,0 };
const float CharacterManager::PointunaMouthRadius = 0;

//Tuna				マグロ
const float CharacterManager::TunaWIDTH = 150;
const float CharacterManager::TunaHEIGHT = 80;
const float CharacterManager::TunaSpeed = 5;
const vivid::Rect CharacterManager::TunaRect = { 0,0,TunaWIDTH ,TunaHEIGHT };
const std::string CharacterManager::TunaFilePath = "data\\Tuna.png";
const vivid::Vector2 CharacterManager::TunaMouthPos = { 130.0f,40.0f };
const float CharacterManager::TunaMouthRadius = 25.0f;


CharacterManager& CharacterManager::GetInstance(void)
{
	static CharacterManager instance;

	return instance;
}

float CharacterManager::CharacterWIDTH(CHARACTER_ID Character)
{
	switch (Character)
	{
	case CHARACTER_ID::DUMMY:
		break;

	case CHARACTER_ID::ELSCTRICEEL:
		return ElsctriceelWIDTH;
		break;

	case CHARACTER_ID::PORCUPINEFISH:
		return PorcupinefishWIDTH;
		break;

	case CHARACTER_ID::SHARK:
		return SharkWIDTH;
		break;

	case CHARACTER_ID::LIONFISH:
		return LionfishWIDTH;
		break;

	case CHARACTER_ID::MIRRORMORAYELL:
		return MirrormorayellWIDTH;
		break;

	case CHARACTER_ID::TURTLE:
		return TurtleWIDTH;
		break;

	case CHARACTER_ID::OCTOPUS:
		return OctopusWIDTH;
		break;

	case CHARACTER_ID::POINTUNA:
		return PointunaWIDTH;
		break;

	case CHARACTER_ID::TUNA:
		return TunaWIDTH;
		break;

	default:
		break;
	}

}

float CharacterManager::CharacterHEIGHT(CHARACTER_ID Character)
{
	switch (Character)
	{
	case CHARACTER_ID::DUMMY:
		break;

	case CHARACTER_ID::ELSCTRICEEL:
		return ElsctriceelHEIGHT;
		break;

	case CHARACTER_ID::PORCUPINEFISH:
		return PorcupinefishHEIGHT;
		break;

	case CHARACTER_ID::SHARK:
		return SharkHEIGHT;
		break;

	case CHARACTER_ID::LIONFISH:
		return LionfishHEIGHT;
		break;

	case CHARACTER_ID::MIRRORMORAYELL:
		return MirrormorayellHEIGHT;
		break;

	case CHARACTER_ID::TURTLE:
		return TurtleHEIGHT;
		break;

	case CHARACTER_ID::OCTOPUS:
		return OctopusHEIGHT;
		break;

	case CHARACTER_ID::POINTUNA:
		return PointunaHEIGHT;
		break;

	case CHARACTER_ID::TUNA:
		return TunaHEIGHT;
		break;

	default:
		break;
	}
}

float CharacterManager::CharacterSpeed(CHARACTER_ID Character)
{
	switch (Character)
	{
	case CHARACTER_ID::DUMMY:
		break;

	case CHARACTER_ID::ELSCTRICEEL:
		return ElsctriceelSpeed;
		break;

	case CHARACTER_ID::PORCUPINEFISH:
		return PorcupinefishSpeed;
		break;

	case CHARACTER_ID::SHARK:
		return SharkSpeed;
		break;

	case CHARACTER_ID::LIONFISH:
		return LionfishSpeed;
		break;

	case CHARACTER_ID::MIRRORMORAYELL:
		return MirrormorayellSpeed;
		break;

	case CHARACTER_ID::TURTLE:
		return TurtleSpeed;
		break;

	case CHARACTER_ID::OCTOPUS:
		return OctopusSpeed;
		break;

	case CHARACTER_ID::POINTUNA:
		return PointunaSpeed;
		break;

	case CHARACTER_ID::TUNA:
		return TunaSpeed;
		break;

	default:
		break;
	}
}

vivid::Rect CharacterManager::CharacterRect(CHARACTER_ID Character)
{
	switch (Character)
	{
	case CHARACTER_ID::DUMMY:
		break;

	case CHARACTER_ID::ELSCTRICEEL:
		return ElsctriceelRect;
		break;

	case CHARACTER_ID::PORCUPINEFISH:
		return PorcupinefishRect;
		break;

	case CHARACTER_ID::SHARK:
		return SharkRect;
		break;

	case CHARACTER_ID::LIONFISH:
		return LionfishRect;
		break;

	case CHARACTER_ID::MIRRORMORAYELL:
		return MirrormorayellRect;
		break;

	case CHARACTER_ID::TURTLE:
		return TurtleRect;
		break;

	case CHARACTER_ID::OCTOPUS:
		return OctopusRect;
		break;

	case CHARACTER_ID::POINTUNA:
		return PointunaRect;
		break;

	case CHARACTER_ID::TUNA:
		return TunaRect;
		break;

	default:
		break;
	}
}

std::string CharacterManager::CharacterFilePath(CHARACTER_ID Character)
{
	switch (Character)
	{
	case CHARACTER_ID::DUMMY:
		break;

	case CHARACTER_ID::ELSCTRICEEL:
		return ElsctriceelFilePath;
		break;

	case CHARACTER_ID::PORCUPINEFISH:
		return PorcupinefishFilePath;
		break;

	case CHARACTER_ID::SHARK:
		return SharkFilePath;
		break;

	case CHARACTER_ID::LIONFISH:
		return LionfishFilePath;
		break;

	case CHARACTER_ID::MIRRORMORAYELL:
		return MirrormorayellFilePath;
		break;

	case CHARACTER_ID::TURTLE:
		return TurtleFilePath;
		break;

	case CHARACTER_ID::OCTOPUS:
		return OctopusFilePath;
		break;

	case CHARACTER_ID::POINTUNA:
		return PointunaFilePath;
		break;

	case CHARACTER_ID::TUNA:
		return TunaFilePath;
		break;

	default:
		break;
	}
}

vivid::Vector2 CharacterManager::CharacterMouthPos(CHARACTER_ID Character, vivid::Vector2 CharacterPosition)
{
	switch (Character)
	{
	case CHARACTER_ID::DUMMY:
		break;

	case CHARACTER_ID::ELSCTRICEEL:
		return ElsctriceelMouthPos;
		break;

	case CHARACTER_ID::PORCUPINEFISH:
		return PorcupinefishMouthPos;
		break;

	case CHARACTER_ID::SHARK:
		return SharkMouthPos;
		break;

	case CHARACTER_ID::LIONFISH:
		return LionfishMouthPos;
		break;

	case CHARACTER_ID::MIRRORMORAYELL:
		return MirrormorayellMouthPos;
		break;

	case CHARACTER_ID::TURTLE:
		return TurtleMouthPos;
		break;

	case CHARACTER_ID::OCTOPUS:
		return OctopusMouthPos;
		break;

	case CHARACTER_ID::POINTUNA:
		return PointunaMouthPos;
		break;

	case CHARACTER_ID::TUNA:
		return  CharacterPosition + TunaMouthPos;
		break;

	default:
		break;
	}
}

float CharacterManager::CharacterMouthRadius(CHARACTER_ID Character)
{
	switch (Character)
	{
	case CHARACTER_ID::DUMMY:
		break;

	case CHARACTER_ID::ELSCTRICEEL:
		return ElsctriceelMouthRadius;
		break;

	case CHARACTER_ID::PORCUPINEFISH:
		return PorcupinefishMouthRadius;
		break;

	case CHARACTER_ID::SHARK:
		return SharkMouthRadius;
		break;

	case CHARACTER_ID::LIONFISH:
		return LionfishMouthRadius;
		break;

	case CHARACTER_ID::MIRRORMORAYELL:
		return MirrormorayellMouthRadius;
		break;

	case CHARACTER_ID::TURTLE:
		return TurtleMouthRadius;
		break;

	case CHARACTER_ID::OCTOPUS:
		return OctopusMouthRadius;
		break;

	case CHARACTER_ID::POINTUNA:
		return PointunaMouthRadius;
		break;

	case CHARACTER_ID::TUNA:
		return TunaMouthRadius;
		break;

	default:
		break;
	}
}

void CharacterManager::Finalize(void)
{
}

