#pragma once
#include "GameFramework/Actor.h"
DECLARE_DELEGATE(FOnWeaponFire)
DECLARE_DELEGATE_OneParam(FOnWeaponOneParam, string)
DECLARE_DELEGATE_RetVal(FOnWeaponRetVal, string)
DECLARE_DELEGATE_RetVal_OneParam(FOnWeaponRetValOneParam, string, int);

class AWeapon : public AActor
{
private:

	string playerName;
	string returnDelegateOneParam;

public:

	AWeapon();

	FOnWeaponFire OnWeaponFire;

	FOnWeaponOneParam OnWeaponOneParam;

	FOnWeaponRetVal OnWeaponRetVal;

	FOnWeaponRetValOneParam OnWeaponRetValOneParam;

	void BeginPlay() override;

	void Tick(float DeltaTime) override;

	void WeaponFire();

};