#include "Project/Player.h"
#include "Project/Weapon.h"

int main()
{
	APlayer* myPlayer = new APlayer;
	AWeapon* testWeapon;

    std::cout << "Hello World!\n";

	myPlayer->BeginPlay();

	testWeapon = myPlayer->GetWeapon(); // Debug

	delete (myPlayer); // Debug

	//myPlayer->PlayerFire(); 

	testWeapon->WeaponFire(); // Debug

	return 0;
}
