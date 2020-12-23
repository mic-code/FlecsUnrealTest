#pragma once

#include "flecs.h"

struct Position {
    float x;
    float y;
};

struct Velocity {
    float x;
    float y;
};

struct SimpleModule {
    SimpleModule(flecs::world& world);
    flecs::entity position;
    flecs::entity velocity;
    flecs::entity move;
};