#include "Actor.h"

AActor::AActor()
{

}

void AActor::BeginPlay()
{

}

void AActor::Tick(float DeltaTime)
{

}

void AActor::PrintScren(string Message, bool bEndLine /*= true*/)
{
	bEndLine ? cout << Message << endl : cout << Message << ": ";
}