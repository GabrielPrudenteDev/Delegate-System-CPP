#pragma once
/*
1 - Inherit the "IObserver" interface
2 - add "DynamicDelegate.h" header in your Base class
3 - Declare the Delegates and create a variable with the same name given to it
4 - Point to a function using BindUFunction()
5 - Call the pointed function with Execute()

Obs

	In the Last delegate you need to put ";" not to accuse false negative
	Works without but member functions apparently didn't find their implementation

*/

#include "DelegateBase.h"
#include <iostream>

template<typename TRetVal, typename ... TParams>
struct FDynamicDelegete
{
private:

	typedef TRetVal(IObserver::*FMethoPtrResolver)(TParams...);

	IObserver* target;

	FMethoPtrResolver functionPtr;

public:

	template<typename TUseClass>
	void BindUFunction(TUseClass* Target, TRetVal(TUseClass::*FMethoPtr)(TParams...))
	{
		this->target = Target;
		this->functionPtr = static_cast<FMethoPtrResolver>(FMethoPtr);
	}

	TRetVal Execute(TParams... params)
	{
		std::cout << "Debug ReturnType: " << typeid(TRetVal).name() << std::endl;

		return (*target.*functionPtr)(params...);
	}

};

// "__VA_ARGS__" Parameter Counter

#define FUNC_DECLARE(DelegateName, ReturnValue, ... ) typedef FDynamicDelegete<ReturnValue, __VA_ARGS__> DelegateName;

#define DECLARE_DELEGATE(DelegateName) FUNC_DECLARE(DelegateName, void)
#define DECLARE_DELEGATE_OneParam(DelegateName, ParamType_1) FUNC_DECLARE(DelegateName, void, ParamType_1)
#define DECLARE_DELEGATE_TwoParams(DelegateName, ParamType_1, ParamType_2) FUNC_DECLARE(DelegateName, void, ParamType_1, ParamType_2)

#define DECLARE_DELEGATE_RetVal(DelegateName, ReturnValue) FUNC_DECLARE(DelegateName, ReturnValue)
#define DECLARE_DELEGATE_RetVal_OneParam(DelegateName, ReturnValue, ParamType_1) FUNC_DECLARE(DelegateName, ReturnValue, ParamType_1)
