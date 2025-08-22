#include "Elsctriceel.h"


const float Elsctriceel::SkillSize = 300;
const float Elsctriceel::AbilityTime = 5;


void Elsctriceel::Initialize(int playernumber)
{
	Timer = 0;
	m_CenterPosition = vivid::Vector2(0,0);
	m_PlayerNumber = playernumber;
}

void Elsctriceel::Update(vivid::Vector2 Pos)
{
	Timer += vivid::GetDeltaTime();

	m_CenterPosition = vivid::Vector2(Pos.x + CharacterManager::GetInstance().CharacterWIDTH (CHARACTER_ID::ELSCTRICEEL) / 2,
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
	for (int i = 0; i < 2; i++)
	{
		if (i != m_PlayerNumber)
		{
			//回転した状態の四角形の頂点の座標
			vivid::Vector2 vertex[4];

			//対象の座標
			vivid::Vector2 targetposition = playermanager::GetInstance().GetPosition(i);
			//対象の角度
			float targetangle = playermanager::GetInstance().GetAngle(i);
			//対象のキャラクター
			CHARACTER_ID targetcharacter = playermanager::GetInstance().GetCharacter(i);
			//キャラクターの横幅と立幅
			float width = CharacterManager::GetInstance().CharacterWIDTH(targetcharacter);
			float height = CharacterManager::GetInstance().CharacterHEIGHT(targetcharacter);
			//対象の中心点
			vivid::Vector2 targetcenterpos = vivid::Vector2(targetposition.x + width / 2, targetposition.y + height / 2);
			//対象の対角線の長さを求める
			float diagonal = sqrt(pow(targetposition.x - targetcenterpos.x,2)+pow(targetposition.y - targetcenterpos.y,2));
			
			for (int j = 0; j < 4; j++)
			{
				//回転した状態の頂点の座標を求める
				vertex[j].x = cos((targetangle + 135 + 90 * j) * 3.14 / 180) * diagonal + targetcenterpos.x;
				vertex[j].y = sin((targetangle + 135 + 90 * j) * 3.14 / 180) * diagonal + targetcenterpos.y;

				float px = m_CenterPosition.x - vertex[j].x;
				float py = m_CenterPosition.y - vertex[j].y;

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

			//四角形の辺の最大値・最小値
			float xmax = fmax(fmax(vertex[0].x, vertex[1].x), fmax(vertex[2].x, vertex[3].x));
			float xmin = fmin(fmin(vertex[0].x, vertex[1].x), fmin(vertex[2].x, vertex[3].x));

			float ymax = fmax(fmax(vertex[0].y, vertex[1].y), fmax(vertex[2].y, vertex[3].y));
			float ymin = fmin(fmin(vertex[0].y, vertex[1].y), fmin(vertex[2].y, vertex[3].y));

			vivid::Vector2 shortpos = m_CenterPosition;

			//キャラクターを円の最短距離を求める
			if		(m_CenterPosition.x < xmin)shortpos.x = xmin;
			else if (xmax < m_CenterPosition.x)shortpos.x = xmax;

			if		(m_CenterPosition.y < ymin)shortpos.y = ymin;
			else if (ymax < m_CenterPosition.y)shortpos.y = ymax;

			//距離を求める
			float difference = sqrt(
				pow((shortpos.x - m_CenterPosition.x), 2.0)
				+ pow((shortpos.y - m_CenterPosition.y), 2.0));

			//比較
			if (difference < SkillSize / 2)
			{
				vivid::DrawText(40, "attateru", vivid::Vector2(640.0f, 0.0f), 0xffffffff);
			}

		}
	}
}
