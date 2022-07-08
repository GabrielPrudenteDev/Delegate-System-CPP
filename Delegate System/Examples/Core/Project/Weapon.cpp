#include "Weapon.h"

AWeapon::AWeapon()
{

}

void AWeapon::BeginPlay()
{
	this->PrintScren("AWeapon::BeginPlay");
}

void AWeapon::Tick(float DeltaTime)
{
	
}

void AWeapon::WeaponFire()
{
	this->PrintScren("AWeapon::WeaponFire");

	this->PrintScren("");
	this->PrintScren("===Delegates Call===");
	this->PrintScren("");
	

	this->PrintScren("==Delegate No Return==");
	this->PrintScren("");

	this->OnWeaponFire.Execute();

	this->OnWeaponOneParam.Execute("PlayerDelegate One Param");

	this->PrintScren("");

	this->PrintScren("==Delegate With Return==");
	this->PrintScren("");

	this->PrintScren("Call in AWeapon::WeaponFire");

	playerName = this->OnWeaponRetVal.Execute();//

	this->PrintScren(playerName);// Print Variable
	this->PrintScren("");

	this->PrintScren("Call in AWeapon::WeaponFire");

	this->returnDelegateOneParam = this->OnWeaponRetValOneParam.Execute(25);//

	this->PrintScren(returnDelegateOneParam);// Print Variable
	this->PrintScren("");
}

