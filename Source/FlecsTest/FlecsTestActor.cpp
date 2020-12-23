// Fill out your copyright notice in the Description page of Project Settings.


#include "FlecsTestActor.h"
#include "SimpleModule.h"

AFlecsTestActor::AFlecsTestActor()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AFlecsTestActor::BeginPlay()
{
    Super::BeginPlay();

	//without this, unreal engine will crash when entering play the second time
    flecs::_::component_info<SimpleModule>::reset();

    world = flecs::world();
    world.import<SimpleModule>();

    world.entity("MyEntity")
        .set<Position>({ 0, 0 })
        .set<Velocity>({ 1, 1 });
}

void AFlecsTestActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    world.progress();
}