#include "DxLib.h"
#include "game.h"
#include "SceneTest.h"

namespace
{
	const char* const kPlayerFilename = "Data/player.bmp";
	const char* const kEnemyFilename = "Data/enemy.bmp";

	// 同時に登場する敵の最大数
	constexpr int kEnemyMax = 32;

	// 敵の生成間隔(フレーム数)
	constexpr int kEnemyInterval = 30;
}

SceneTest::SceneTest():
	m_hPlayer(-1),
	m_hEnemy(-1),
	m_pPlayer(nullptr),
	m_pEnemy(kEnemyInterval, nullptr),
	m_enemyInterval(0)
{
	m_pPlayer = new ObjectPlayer;
}

SceneTest::~SceneTest()
{
	delete m_pPlayer;
	for (auto& pEnemy : m_pEnemy)
	{
		if (pEnemy)
		{
			delete pEnemy;
			pEnemy = nullptr;
		}
	}
}

void SceneTest::init()
{
	m_hPlayer = LoadGraph(kPlayerFilename);
	m_hEnemy = LoadGraph(kEnemyFilename);

	m_pPlayer->init();
	m_pPlayer->setHandle(m_hPlayer);
	for (auto& pEnemy : m_pEnemy)
	{
		/*pEnemy->init();
		pEnemy->setHandle(m_hEnemy);*/
		pEnemy = nullptr;
	}

	m_enemyInterval = 0;
}

void SceneTest::end()
{
	DeleteGraph(m_hPlayer);
	DeleteGraph(m_hEnemy);
}

SceneBase* SceneTest::update()
{
	m_pPlayer->update();
	for (auto& pEnemy : m_pEnemy)
	{
		if (!pEnemy)
		{
			continue;
		}
		pEnemy->update();
#if true
		if (!pEnemy->isExist())
		{
			delete pEnemy;
			pEnemy = nullptr;
		}
#else
		// ↓自己流
		// メモリの解放
		if (!pEnemy->isExist())
		{
			if (pEnemy)
			{
				delete pEnemy;
				pEnemy = nullptr;
			}
		}
#endif
	}

	m_enemyInterval++;
	if (m_enemyInterval >= kEnemyInterval)
	{
		// 使用されていない敵を探してそれを使う
		for (auto& pEnemy : m_pEnemy)
		{
#if true
			// nullptrを探して新しい弾を生成する
			if (pEnemy)	continue;

			pEnemy = new ObjectEnemy;
			pEnemy->init();
			pEnemy->setHandle(m_hEnemy);
			pEnemy->setExist(true);
			Vec2 pos{ Game::kScreenWidth + 16, static_cast<float>(GetRand(Game::kScreenHeight)) };
			pEnemy->setPos(pos);
			break;
#else
			// ↓自己流
			// メモリの確保
			if (!pEnemy)
			{
				pEnemy = new ObjectEnemy;
			}

			if (pEnemy->isExist())	continue;

			pEnemy->init();
			pEnemy->setHandle(m_hEnemy);

			pEnemy->setExist(true);

			Vec2 pos{Game::kScreenWidth+16, static_cast<float>(GetRand(Game::kScreenHeight))};
			pEnemy->setPos(m_pos);
			break;
#endif
		}
		m_enemyInterval = 0;
	}
	return this;
}

void SceneTest::draw()
{
	m_pPlayer->draw();
	for (auto& pEnemy : m_pEnemy)
	{
		if (pEnemy)
		{
			pEnemy->draw();
		}
	}

	int num = 0;
	for (auto& pEnemy : m_pEnemy)
	{
		if ((pEnemy) && (pEnemy->isExist()))
		{
			num++;
		}
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "敵の数:%d", num);

}