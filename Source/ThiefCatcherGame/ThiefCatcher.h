// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Math/UnrealMathUtility.h"
#include "InteractInterface.h"

#include "ThiefCatcher.generated.h"

/**
 * 
 */
UCLASS()
class THIEFCATCHERGAME_API AThiefCatcher : public AMainCharacter, public IInteractInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

protected:
	void MoveForwardBackward(float Value);
	void MoveRightLeft(float Value);

	void Jump();
	void StopJump();

	void Sprint();
	void StopSprint();

	bool bIsSprint;
	
public:
	AThiefCatcher();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JumpAnimation")
	UAnimMontage* JumpAnimation;

	virtual void SetupPlayerInputComponent(class UInputComponent* MyPlayerInput) override;

	virtual void Tick(float DeltaTime) override;


	virtual void AddStamina_Implementation(float AddStamina) override;

	UFUNCTION()
	void TouchEnemy();
};
