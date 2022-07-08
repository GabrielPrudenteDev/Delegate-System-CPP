#include "Player.h"
#include "Weapon.h"

APlayer::APlayer()
{
	myWeapon = new AWeapon;
}

void APlayer::BeginPlay()
{
	this->PrintScren("APlayer::BeginPlay");
	if (myWeapon) myWeapon->BeginPlay();
	
	// Binds

	myWeapon->OnWeaponFire.BindUFunction(this, &APlayer::PlayerDelegete);
	myWeapon->OnWeaponOneParam.BindUFunction(this, &APlayer::PlayerDelegeteOneParam);


	myWeapon->OnWeaponRetVal.BindUFunction(this, &APlayer::PlayerDelegeteRetVal);
	myWeapon->OnWeaponRetValOneParam.BindUFunction(this, &APlayer::PlayerDelegeteRetValOneParam);

	// Ignore
	this->PrintScren("");
	this->PrintScren("===Gameplay===");
	this->PrintScren("");
}

void APlayer::Tick(float DeltaTime)
{
	if (myWeapon) myWeapon->Tick(DeltaTime);
}

AWeapon* APlayer::GetWeapon() const
{
	return myWeapon;
}

void APlayer::PlayerFire()
{
	this->PrintScren("APlayer::PlayerFire");
	if (myWeapon) myWeapon->WeaponFire();
}

void APlayer::PlayerDelegete()
{
	this->PrintScren("Call in APlayer::PlayerDelegete");
	this->PrintScren("PlayerDelegete No Parameters");
	this->PrintScren("");
}

void APlayer::PlayerDelegeteOneParam(string param1)
{
	this->PrintScren("Call in APlayer::PlayerDelegeteOneParam");
	this->PrintScren(param1);
	this->PrintScren("");
}

string APlayer::PlayerDelegeteRetVal()
{
	string text = "MyName: Oliveira Dev";
	return text;
}

string APlayer::PlayerDelegeteRetValOneParam(int Age)
{
	string ToReturn = "My Age: " + std::to_string(Age);
	return ToReturn;
}

