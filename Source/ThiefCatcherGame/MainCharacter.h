// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS()
class THIEFCATCHERGAME_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category = "Stamina", meta = (ClampMin = "0", ClampMax = "100"))
	float Stamina;

	bool bIsTired;

	bool StaminaIsZero();

	UPROPERTY(EditDefaultsOnly, Category = "Stamina")
	USoundBase* TiredSound;

	UPROPERTY(EditDefaultsOnly, Category = "Stamina")
	UAnimMontage* VertigoAnimation;

protected:
	void IncreaseStamina(float AddStamina = 1);
	void DecreaseStamina(float SubtractStamina = 1);

public:
	// Sets default values for this character's properties
	AMainCharacter();

	float GetStamina();
	
};
