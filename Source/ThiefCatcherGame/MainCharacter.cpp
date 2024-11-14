// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Stamina = 100.0f;

	bIsTired = false;
}

float AMainCharacter::GetStamina()
{
	return Stamina;
}


void AMainCharacter::IncreaseStamina(float AddStamina)
{
	Stamina += AddStamina;
}

void AMainCharacter::DecreaseStamina(float SubtractStamina)
{
	Stamina -= SubtractStamina;
}

bool AMainCharacter::StaminaIsZero()
{
	if (Stamina <= 0)
	{
		bIsTired = true;

		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	UGameplayStatics::SpawnSoundAtLocation(this, TiredSound, GetActorLocation());

	return bIsTired;
}


