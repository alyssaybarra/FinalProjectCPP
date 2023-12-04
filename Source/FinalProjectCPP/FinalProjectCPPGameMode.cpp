// Copyright Epic Games, Inc. All Rights Reserved.

#include "FinalProjectCPPGameMode.h"
#include "FinalProjectCPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFinalProjectCPPGameMode::AFinalProjectCPPGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
