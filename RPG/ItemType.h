#pragma once

namespace ItemType {
    enum Type {
        Basic = 1 << 0, //1
        Potion = 1 << 1, //2
        Weapon = 1 << 2, //4
        Equipment = 1 << 3 //8
    };
}
