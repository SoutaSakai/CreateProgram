#include "Elsctriceel.h"

#include"../../../maxplayer_manager/maxplayer_manager.h"
#include"../../../score_manager/score_manager.h"

const float Elsctriceel::SkillSize = 300;
const float Elsctriceel::AbilityTime = 5;
const int	Elsctriceel::m_stan_time = 90;
const int	Elsctriceel::m_score = 20;

void Elsctriceel::Initialize(int playernumber)
{
	m_MaxPlayer = CMaxPlayerManager::GetInstance().GetMaxPlayer();

	Timer = 0;
	m_CenterPosition = vivid::Vector2(0, 0);
	m_PlayerNumber = playernumber;

	for (int i = 0; i < (int)vivid::controller::DEVICE_ID::MAX; i++)
		m_Flag[i] = true;
}

void Elsctriceel::Update(vivid::Vector2 Pos)
{
	Timer += vivid::GetDeltaTime();

	m_CenterPosition = vivid::Vector2(Pos.x + CharacterManager::GetInstance().CharacterWIDTH(CHARACTER_ID::ELSCTRICEEL) / 2,
		Pos.y + CharacterManager::GetInstance().CharacterHEIGHT(CHARACTER_ID::ELSCTRICEEL) / 2);

	//当たり判定
	CheckHitSkill();

	//効果時間内
	if (Timer <= AbilityTime)
	{
		DxLib::DrawCircle(m_CenterPosition.x, m_CenterPosition.y,
			SkillSize / 2, 0xffffff00, true);
	}
	//効果時間外
	else
	{
		playermanager::GetInstance().ChangeSkilFlagFalse(m_PlayerNumber);
	}
}

void Elsctriceel::CheckHitSkill(void)
{
	for (int i = 0; i < m_MaxPlayer; i++)
	{
		//自分以外 && スキルが一回も当たってない場合
		if (i != m_PlayerNumber && m_Flag[i])
		{
			//カメ && スキル使用中だったら
			if (playermanager::GetInstance().GetCharacter(i) == CHARACTER_ID::TURTLE &&
				playermanager::GetInstance().GetSkilFlag(i) == true)
			{
			}
			else
			{
				CollisionDetection(i, 0);
			}

			//ミラーウツボだったら
			if (playermanager::GetInstance().GetCharacter(i) == CHARACTER_ID::MIRRORMORAYELL &&
				playermanager::GetInstance().GetSkilFlag(i) == true)
			{
				CollisionDetection(i, 1);
			}
		}
	}
}

void Elsctriceel::CollisionDetection(int number, int pattern)
{
	//回転した状態の四角形の頂点の座標
	vivid::Vector2 vertex[4];

	CHARACTER_ID targetcharacter;
	vivid::Vector2 targetposition;
	vivid::Vector2 targetcenterpos;
	float targetangle;
	float width, height;
	float diagonal;

	if (pattern == 0)
	{
		//対象の座標
		targetposition = playermanager::GetInstance().GetPosition(number);
		//対象の角度
		targetangle = playermanager::GetInstance().GetAngle(number);
		//対象のキャラクター
		targetcharacter = playermanager::GetInstance().GetCharacter(number);
	}
	else
	{
		//対象の座標
		targetposition = SkilManager::Getinstance().GetMirrormorayDecoyPos(number);
		//対象の角度
		targetangle = SkilManager::Getinstance().GetMirrormorayDecoyAngle(number);
		//対象のキャラクター
		targetcharacter = CHARACTER_ID::MIRRORMORAYELL;
	}

	//キャラクターの横幅と立幅
	width = CharacterManager::GetInstance().CharacterWIDTH(targetcharacter);
	height = CharacterManager::GetInstance().CharacterHEIGHT(targetcharacter);
	//対象の中心点
	targetcenterpos = vivid::Vector2(targetposition.x + width / 2, targetposition.y + height / 2);
	//対象の対角線の長さを求める
	diagonal = sqrt(pow(targetposition.x - targetcenterpos.x, 2) + pow(targetposition.y - targetcenterpos.y, 2));

	for (int j = 0; j < 4; j++)
	{
		//回転した状態の頂点の座標を求める
		vertex[j].x = cos((targetangle + 135 + 90 * j) * 3.14 / 180) * diagonal + targetcenterpos.x;
		vertex[j].y = sin((targetangle + 135 + 90 * j) * 3.14 / 180) * diagonal + targetcenterpos.y;

		float px = vertex[j].x - m_CenterPosition.x;
		float py = vertex[j].y - m_CenterPosition.y;

		//頂点と円の中心の距離と角度
		float distance = sqrt(pow(px, 2) + pow(py, 2));
		float angle = atan2(py, px);

		//角度を逆回転させる
		angle = angle - targetangle * 3.14 / 180;

		px = distance * cos(angle);
		py = distance * sin(angle);

		vertex[j].x = px + m_CenterPosition.x;
		vertex[j].y = py + m_CenterPosition.y;

	}


	DxLib::DrawBox(vertex[1].x, vertex[1].y, vertex[3].x, vertex[3].y, 0xffff0000, true);

	//四角形の辺の最大値・最小値
	float xmax = fmax(fmax(vertex[0].x, vertex[1].x), fmax(vertex[2].x, vertex[3].x));
	float xmin = fmin(fmin(vertex[0].x, vertex[1].x), fmin(vertex[2].x, vertex[3].x));

	float ymax = fmax(fmax(vertex[0].y, vertex[1].y), fmax(vertex[2].y, vertex[3].y));
	float ymin = fmin(fmin(vertex[0].y, vertex[1].y), fmin(vertex[2].y, vertex[3].y));

	vivid::Vector2 shortpos = m_CenterPosition;

	//キャラクターを円の最短距離を求める
	if (m_CenterPosition.x < xmin)shortpos.x = xmin;
	else if (xmax < m_CenterPosition.x)shortpos.x = xmax;

	if (m_CenterPosition.y < ymin)shortpos.y = ymin;
	else if (ymax < m_CenterPosition.y)shortpos.y = ymax;

	//距離を求める
	float difference = sqrt(
		pow((shortpos.x - m_CenterPosition.x), 2.0)
		+ pow((shortpos.y - m_CenterPosition.y), 2.0));

	//比較
	if (difference < SkillSize / 2)
	{
		//スタンさせる
		playermanager::GetInstance().SetStanTime(number, m_stan_time);
		//ポイント付与
		ScoreManager::GetInstance().AddScore(m_score, m_PlayerNumber);
		//フラグをfalseにする
		m_Flag[number] = false;
	}
}
