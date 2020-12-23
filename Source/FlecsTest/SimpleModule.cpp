#include "SimpleModule.h"

#include "Logging/LogMacros.h"

SimpleModule::SimpleModule(flecs::world& ecs)
{
	/* Register module with world */
	ecs.module<SimpleModule>();

	/* Register components */
	this->position = ecs.component<Position>();
	this->velocity = ecs.component<Velocity>();

	/* Register system */
	this->move = ecs.system<Position, const Velocity>("Move")
		.each([](flecs::entity e, Position& p, const Velocity& v) {
		p.x += v.x;
		p.y += v.y;

		FString entityName(e.name().c_str());
		UE_LOG(LogTemp, Warning, TEXT("Moved %s to {%f,%f}"), *entityName, p.x, p.y);
		});
}
