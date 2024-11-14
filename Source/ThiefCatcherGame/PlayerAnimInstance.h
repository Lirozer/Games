// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class THIEFCATCHERGAME_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

private:
	APawn* Character;

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly);
	float Speed;
};