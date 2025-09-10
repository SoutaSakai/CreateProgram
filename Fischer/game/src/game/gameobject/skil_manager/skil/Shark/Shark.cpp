#include "Shark.h"

const int CShark::m_time = 5;

void CShark::Initialize(int playernumber, vivid::Vector2 position)
{
	m_PlayerNumber = playernumber;
	m_Position = position;

	m_RMouthPos = CharacterManager::GetInstance().CharacterMouthPos(CHARACTER_ID::SHARK);
	m_MouthRadius = CharacterManager::GetInstance().CharacterMouthRadius(CHARACTER_ID::SHARK);

	m_Width = CharacterManager::GetInstance().CharacterWIDTH(CHARACTER_ID::SHARK);
	m_Height = CharacterManager::GetInstance().CharacterHEIGHT(CHARACTER_ID::SHARK);

	m_CenterPosition = m_Position + vivid::Vector2(m_Width / 2, m_Height / 2);
	m_WMouthPos = m_Position + m_RMouthPos;

	vivid::Vector2 test = m_WMouthPos - m_CenterPosition;
	m_MouthAngle = atan2(test.y, test.x);

	m_Diagonal = sqrt(pow(test.x, 2) + pow(test.y, 2));

	m_Timer = 0;
}

void CShark::Update(vivid::Vector2 pos, float angle, float scaleX)
{
	m_Angle = angle;
	//座標更新
	m_Position = pos;
	//中心点更新
	m_CenterPosition = m_Position + vivid::Vector2(m_Width / 2, m_Height / 2);
	//口の位置更新
	if (scaleX > 0)
	{
		m_WMouthPos.x = cos(m_MouthAngle + (angle)) * m_Diagonal + m_CenterPosition.x;
		m_WMouthPos.y = sin(m_MouthAngle + (angle)) * m_Diagonal + m_CenterPosition.y;
	}
	else if (scaleX < 0)
	{
		m_WMouthPos.x = cos(m_MouthAngle + (angle)) * -m_Diagonal + m_CenterPosition.x;
		m_WMouthPos.y = sin(m_MouthAngle + (angle)) * m_Diagonal + m_CenterPosition.y;
	}

	CheckHitSkill();

	if (++m_Timer >= m_time)
		playermanager::GetInstance().ChangeSkilFlagFalse(m_PlayerNumber);
}

void CShark::CheckHitSkill(void)
{
	DxLib::DrawCircle(m_WMouthPos.x, m_WMouthPos.y, m_MouthRadius, 0xffff0000, true);

	for (int i = 0; i < 2; i++)
	{
		if (i != m_PlayerNumber)
		{
			//カメ && スキル使用中だったら
			if (playermanager::GetInstance().GetCharacter(i) == CHARACTER_ID::TURTLE &&
				playermanager::GetInstance().GetSkilFlag(i) == true)
			{
				return;
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

void CShark::CollisionDetection(int number, int pattern)
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

		float px = vertex[j].x - m_WMouthPos.x;
		float py = vertex[j].y - m_WMouthPos.y;

		/*float px = m_WMouthPos.x - vertex[j].x;
		float py = m_WMouthPos.y - vertex[j].y;*/

		//頂点と円の中心の距離と角度
		float distance = sqrt(pow(px, 2) + pow(py, 2));
		float angle = atan2(py, px);

		//角度を逆回転させる
		angle = angle - targetangle * 3.14 / 180;

		px = distance * cos(angle);
		py = distance * sin(angle);

		vertex[j].x = px + m_WMouthPos.x;
		vertex[j].y = py + m_WMouthPos.y;

	}

	DxLib::DrawBox(vertex[0].x, vertex[0].y, vertex[2].x, vertex[2].y, 0xffff0000, true);

	//四角形の辺の最大値・最小値
	float xmax = fmax(fmax(vertex[0].x, vertex[1].x), fmax(vertex[2].x, vertex[3].x));
	float xmin = fmin(fmin(vertex[0].x, vertex[1].x), fmin(vertex[2].x, vertex[3].x));

	float ymax = fmax(fmax(vertex[0].y, vertex[1].y), fmax(vertex[2].y, vertex[3].y));
	float ymin = fmin(fmin(vertex[0].y, vertex[1].y), fmin(vertex[2].y, vertex[3].y));

	vivid::Vector2 shortpos = m_WMouthPos;

	//キャラクターを円の最短距離を求める
	if (m_WMouthPos.x < xmin)shortpos.x = xmin;
	else if (xmax < m_WMouthPos.x)shortpos.x = xmax;

	if (m_WMouthPos.y < ymin)shortpos.y = ymin;
	else if (ymax < m_WMouthPos.y)shortpos.y = ymax;

	//距離を求める
	float difference = sqrt(
		pow((shortpos.x - m_WMouthPos.x), 2.0)
		+ pow((shortpos.y - m_WMouthPos.y), 2.0));

	//比較
	if (difference < m_MouthRadius)
	{
		vivid::DrawText(40, "attateru", vivid::Vector2(640.0f, 0.0f), 0xffffffff);
	}

}
