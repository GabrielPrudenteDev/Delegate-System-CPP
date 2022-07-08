#pragma once
#include <iostream>
#include <string>
#include "../../Files/DynamicDelegate.h"

using std::string;
using std::cout;
using std::endl;

class UObject : public IObserver
{
public:

	virtual void BeginPlay() = 0;

	virtual void Tick(float DeltaTime) = 0;
};