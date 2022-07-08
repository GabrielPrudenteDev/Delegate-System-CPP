#pragma once
#include "GameFramework/Pawn.h"

class AEnemy : public APawn
{
private:

	float myHealt;

	bool Alive;

public:

	AEnemy();

	void BeginPlay() override;

	void Tick(float DeltaTime) override;

};