#pragma once
#include "CoreMinimal.h"

class AActor : public UObject
{
public:

	AActor();

	void BeginPlay() override;

	void Tick(float DeltaTime) override;

	void PrintScren(string Message, bool bEndLine = true);

};