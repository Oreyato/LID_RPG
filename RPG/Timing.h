#pragma once

#include <chrono>
#include <thread>

using namespace std::this_thread;
using namespace std::chrono;

namespace Timing
{
	static int littleDelay = 1000;
	static int mediumDelay = 3000;
	static int hugeDelay = 6000;
}