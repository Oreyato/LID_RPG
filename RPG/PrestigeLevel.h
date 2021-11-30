#pragma once

namespace Prestige {
    enum Level {
        Lowest = 1 << 0, //1
        Low = 1 << 1, //2
        Intermediate = 1 << 2, //4
        High = 1 << 3, //8
        Highest = 1 << 4,
        Pinnacle = 1 << 5
    };
}