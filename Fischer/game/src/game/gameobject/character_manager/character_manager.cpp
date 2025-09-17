#include "Character_manager.h"

//Elsctriceel		電気うなぎ
const float CharacterManager::ElsctriceelWIDTH = 200;
const float CharacterManager::ElsctriceelHEIGHT = 30;
const float CharacterManager::ElsctriceelSpeed = 5;
const vivid::Rect CharacterManager::ElsctriceelRect = { 0,0,ElsctriceelWIDTH,ElsctriceelHEIGHT };
const std::string CharacterManager::ElsctriceelFilePath = "data\\Elsctriceel.png";
const vivid::Vector2 CharacterManager::ElsctriceelMouthPos = { 175.0f,25.0f };
const float CharacterManager::ElsctriceelMouthRadius = 20.0f;
const int CharacterManager::ElsctriceelUsagelimit = 3;

//Porcupinefish		ハリセンボン
const float CharacterManager::PorcupinefishWIDTH = 80;
const float CharacterManager::PorcupinefishHEIGHT = 70;
const float CharacterManager::PorcupinefishSpeed = 6;
const vivid::Rect CharacterManager::PorcupinefishRect = { 0,0,PorcupinefishWIDTH,PorcupinefishHEIGHT };
const std::string CharacterManager::PorcupinefishFilePath = "data\\Porcupinefish.png";
const vivid::Vector2 CharacterManager::PorcupinefishMouthPos = { 60.0f,35.0f };
const float CharacterManager::PorcupinefishMouthRadius = 20;
const int CharacterManager::PorcupinefishUsagelimit = 3;

//Shark				サメ
const float CharacterManager::SharkWIDTH = 210;
const float CharacterManager::SharkHEIGHT = 80;
const float CharacterManager::SharkSpeed = 3;
const vivid::Rect CharacterManager::SharkRect = { 0,0,SharkWIDTH ,SharkHEIGHT };
const std::string CharacterManager::SharkFilePath = "data\\Shark.png";
const vivid::Vector2 CharacterManager::SharkMouthPos = { 155.0f,50.0f };
const float CharacterManager::SharkMouthRadius = 50.0f;
const int CharacterManager::SharkUsagelimit = 3;

//Lionfish			ミノカサゴ
const float CharacterManager::LionfishWIDTH = 90;
const float CharacterManager::LionfishHEIGHT = 90;
const float CharacterManager::LionfishSpeed = 5;
const vivid::Rect CharacterManager::LionfishRect = { 0,0,LionfishWIDTH ,LionfishHEIGHT };
const std::string CharacterManager::LionfishFilePath = "data\\Lionfish.png";
const vivid::Vector2 CharacterManager::LionfishMouthPos = { 80.0f,55.0f };
const float CharacterManager::LionfishMouthRadius = 25.0f;
const int CharacterManager::LionfishUsagelimit = 3;

//Mirrormoray		ミラーウツボ
const float CharacterManager::MirrormorayellWIDTH = 170;
const float CharacterManager::MirrormorayellHEIGHT = 50;
const float CharacterManager::MirrormorayellSpeed = 5;
const vivid::Rect CharacterManager::MirrormorayellRect = { 0,0,MirrormorayellWIDTH ,MirrormorayellHEIGHT };
const std::string CharacterManager::MirrormorayellFilePath = "data\\Mirrormoray.png";
const vivid::Vector2 CharacterManager::MirrormorayellMouthPos = { 0,0 };
const float CharacterManager::MirrormorayellMouthRadius = 0;
const int CharacterManager::MirrormorayellUsagelimit = 2;

//Turtle			カメ
const float CharacterManager::TurtleWIDTH = 130;
const float CharacterManager::TurtleHEIGHT = 90;
const float CharacterManager::TurtleSpeed = 5;
const vivid::Rect CharacterManager::TurtleRect = { 0,0,TurtleWIDTH ,TurtleHEIGHT };
const std::string CharacterManager::TurtleFilePath = "data\\Turtle.png";
const vivid::Vector2 CharacterManager::TurtleMouthPos = { 110.0f,45.0f };
const float CharacterManager::TurtleMouthRadius = 15.0f;
const int CharacterManager::TurtleUsagelimit = 3;

//Octopus			タコ
const float CharacterManager::OctopusWIDTH = 80;
const float CharacterManager::OctopusHEIGHT = 90;
const float CharacterManager::OctopusSpeed = 5;
const vivid::Rect CharacterManager::OctopusRect = { 0,0,OctopusWIDTH ,OctopusHEIGHT };
const std::string CharacterManager::OctopusFilePath = "data\\Octopus.png";
const vivid::Vector2 CharacterManager::OctopusMouthPos = { 0,0 };
const float CharacterManager::OctopusMouthRadius = 0;
const float CharacterManager::SlowSpeed = OctopusSpeed * 0.3;
const int CharacterManager::OctopusUsagelimit = 2;

//Pointuna			ポインツナ
const float CharacterManager::PointunaWIDTH = 150;
const float CharacterManager::PointunaHEIGHT = 80;
const float CharacterManager::PointunaSpeed = 5;
const vivid::Rect CharacterManager::PointunaRect = { 0,0,PointunaWIDTH ,PointunaHEIGHT };
const std::string CharacterManager::PointunaFilePath = "data\\Pointuna.png";
const vivid::Vector2 CharacterManager::PointunaMouthPos = { 130.0f,45.0f };
const float CharacterManager::PointunaMouthRadius = 20.0f;
const int CharacterManager::PointunaUsagelimit = 0;

//Tuna				マグロ
const float CharacterManager::TunaWIDTH = 150;
const float CharacterManager::TunaHEIGHT = 80;
const float CharacterManager::TunaSpeed = 6;
const vivid::Rect CharacterManager::TunaRect = { 0,0,TunaWIDTH ,TunaHEIGHT };
const std::string CharacterManager::TunaFilePath = "data\\tuna.png";
const vivid::Vector2 CharacterManager::TunaMouthPos = { 130.0f,40.0f };
const float CharacterManager::TunaMouthRadius = 25.0f;
const int CharacterManager::TunaUsagelimit = 3;


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
		return nullptr;
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

vivid::Vector2 CharacterManager::CharacterMouthPos(CHARACTER_ID Character)
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
		return  TunaMouthPos;
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

int CharacterManager::CharacterUsagelimit(CHARACTER_ID Character)
{
	switch (Character)
	{
	case CHARACTER_ID::DUMMY:
		break;

	case CHARACTER_ID::ELSCTRICEEL:
		return ElsctriceelUsagelimit;
		break;

	case CHARACTER_ID::PORCUPINEFISH:
		return PorcupinefishUsagelimit;
		break;

	case CHARACTER_ID::SHARK:
		return SharkUsagelimit;
		break;

	case CHARACTER_ID::LIONFISH:
		return LionfishUsagelimit;
		break;

	case CHARACTER_ID::MIRRORMORAYELL:
		return MirrormorayellUsagelimit;
		break;

	case CHARACTER_ID::TURTLE:
		return TurtleUsagelimit;
		break;

	case CHARACTER_ID::OCTOPUS:
		return OctopusUsagelimit;
		break;

	case CHARACTER_ID::POINTUNA:
		return PointunaUsagelimit;
		break;

	case CHARACTER_ID::TUNA:
		return TunaUsagelimit;
		break;

	default:
		break;
	}
}

void CharacterManager::Finalize(void)
{
}

