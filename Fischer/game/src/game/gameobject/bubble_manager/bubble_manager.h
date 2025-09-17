#pragma once
#include<list>
#include"vivid.h"
#include"../bubble_manager/bubble/bubble.h"
using namespace std;

class BubbleManager
{
public:
	static BubbleManager& GetInstance(void);
	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);
	void Create(void);


private:
	//コンストラクタ
	BubbleManager(void);

	//コピーコンストラクタ
	BubbleManager(const BubbleManager& rhs);
	//デストラクタ
	~BubbleManager(void) = default;

	//代入演算子
	BubbleManager& operator = (const BubbleManager& rhs);

	//泡のリスト型
	using BUBBLE_LIST = list<CBubble*>;

	BUBBLE_LIST  m_BubbleList;			//弾リスト


};