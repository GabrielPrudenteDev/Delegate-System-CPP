#pragma once
#include "GameFramework/Pawn.h"

class AWeapon;

class APlayer : public APawn
{
private:

	AWeapon* myWeapon;

public:

	APlayer();

	void BeginPlay() override;

	void Tick(float DeltaTime) override;

	// Debug Call with null pointer
	AWeapon* GetWeapon() const;

	void PlayerFire();

	void PlayerDelegete();

	void PlayerDelegeteOneParam(string param1);

	string PlayerDelegeteRetVal();

	string PlayerDelegeteRetValOneParam(int Age);

};