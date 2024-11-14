// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractInterface.h"

#include "EnergyDrink.generated.h"

UCLASS()
class THIEFCATCHERGAME_API AEnergyDrink : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnergyDrink();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* DrinkStaticMesh;

	UPROPERTY(EditDefaultsOnly)
	float AddStamina = 5.0f;

	USoundBase* DrinkSound;


	UFUNCTION()
	void Overlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool FromSweep, const FHitResult& HitResult);
};
