#include "bubble_manager.h"
#include "bubble/bubble.h"

BubbleManager& BubbleManager::GetInstance(void)
{
	static BubbleManager instance;

	return instance;
}

void BubbleManager::Initialize(void)
{
	m_BubbleList.clear();
}

void BubbleManager::Update(void)
{
	if (m_BubbleList.empty())return;

	BUBBLE_LIST::iterator it = m_BubbleList.begin();

	while (it != m_BubbleList.end())
	{
		CBubble* bubble = (CBubble*)(*it);

		bubble->Update();

		//弾が非アクティブなら削除してリストから外す
		if (!bubble->GetActive())
		{
			bubble->Finalize();
			delete bubble;
			it = m_BubbleList.erase(it);
			continue;
		}

		++it;
	}

}

void BubbleManager::Draw(void)
{
	if (m_BubbleList.empty())return;

	BUBBLE_LIST::iterator it = m_BubbleList.begin();

	while (it != m_BubbleList.end())
	{
		(*it)->Draw();
		++it;
	}
}

void BubbleManager::Finalize(void)
{
	if (m_BubbleList.empty())return;

	BUBBLE_LIST::iterator it = m_BubbleList.begin();

	while (it != m_BubbleList.end())
	{
		(*it)->Finalize();
		delete(*it);
		++it;
	}
	m_BubbleList.clear();
}


void BubbleManager::Create()
{
	CBubble* bubble = nullptr;													//空の箱を生成する

	bubble = new CBubble();														//オブジェクトを作っている

	if (!bubble)return;															//オブジェクトが無かったら返す

	bubble->Initialize();														//CBubbleの型を持ったbubbleというオブジェクトを初期化

	bubble->GetPosition();														//

	m_BubbleList.push_back(bubble);												//生成した泡をリストに追加


}

BubbleManager::BubbleManager(void)
{

}

BubbleManager::BubbleManager(const BubbleManager& rhs)
{
	(void)rhs;
}



BubbleManager& BubbleManager::operator=(const BubbleManager& rhs)
{
	(void)rhs;
	return *this;
}











