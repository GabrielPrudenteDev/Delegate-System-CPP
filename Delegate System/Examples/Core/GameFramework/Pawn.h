#pragma once
#include "Actor.h"

class APawn : public AActor
{
public:

	APawn();

	void BeginPlay() override;

	void Tick(float DeltaTime) override;
};