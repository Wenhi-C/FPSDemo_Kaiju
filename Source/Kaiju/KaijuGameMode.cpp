// Copyright Epic Games, Inc. All Rights Reserved.

#include "KaijuGameMode.h"
#include "KaijuCharacter.h"
#include "UObject/ConstructorHelpers.h"

AKaijuGameMode::AKaijuGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
