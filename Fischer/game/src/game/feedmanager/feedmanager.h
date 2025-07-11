#pragma once
#include <list>
#include "vivid.h"

class Feed;

class FeedManager
{
public:
	static FeedManager& GetInstance(void);

	// 初期化
	void Initialize(int);

	// 更新
	void Update(void);

	// 描画
	void Draw(void);

	// 解放
	void Finalize(void);

	// プレイヤーの口とのアタリ判定
	bool CheckHit(vivid::Vector2, float, int);

	// 餌の生成
	void Create(vivid::Vector2, int);

	// 餌の削除
	void Destroy(int);

	// 位置の設定
	void SetPosition(vivid::Vector2, int);

private:
	Feed	*m_Feeds;			// 餌のオブジェクト配列
	int		m_Max;				// 餌の最大値
	vivid::Vector2	m_Range;	// 釣り人から餌までの距離

	FeedManager(void);
	~FeedManager(void) = default;
	FeedManager(const FeedManager& rhs) = delete;
	FeedManager& operator=(const FeedManager& rhs) = delete;
};