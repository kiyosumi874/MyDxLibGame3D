//-----------------------------------------------------------------------------
// @brief  Timerクラス
// 2022 Kiyosumi Shiihara All Rights Reserved.
//-----------------------------------------------------------------------------
#pragma once
#include <chrono>

using namespace std::chrono;

class Timer
{
public:
	Timer(); // コンストラクタ.
	~Timer(); // デストラクタ.

	void Start(); // 計測開始.

	const long long Elapsed() const; // 計測開始からの秒数をミリ秒で返す.
	
private:
	system_clock::time_point startTime; // 計測開始時間.
};
