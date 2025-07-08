#pragma once
#include <list>
#include "vivid.h"

class Feed;

class FeedManager
{
public:
	static FeedManager& GetInstance(void);

	// 初期化
	void Initialize(void);

	// 更新
	void Update(void);

	// 描画
	void Draw(void);

	// 解放
	void Finalize(void);

	// プレイヤーの口とのアタリ判定
	bool CheckHit(vivid::Vector2, float, int);

	// 餌の生成
	void Create(vivid::Vector2, int, int);

	// 餌の削除
	void Destroy(int);

private:
	static const vivid::Vector2	m_range;	// 釣り人から餌までの距離
	static const int	m_max;				// 餌の最大値

	Feed*	m_Feeds[5];			// 餌のオブジェクト配列
	bool	m_ActiveFlag[5];	// アクティブフラグ

	FeedManager(void) = default;
	~FeedManager(void) = default;
	FeedManager(const FeedManager& rhs) = delete;
	FeedManager& operator=(const FeedManager& rhs) = delete;
};