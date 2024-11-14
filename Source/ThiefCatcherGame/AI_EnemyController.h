// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "ThiefCatcher.h"
#include "Enemy.h"

#include "AI_EnemyController.generated.h"

/**
 * 
 */
UCLASS()
class THIEFCATCHERGAME_API AAI_EnemyController : public AAIController
{
	GENERATED_BODY()

public:
	void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void RandomPatrol();

	UFUNCTION(BlueprintCallable)
	void RunAwayFromPlayer();

	UFUNCTION(BlueprintCallable)
	void ClearTimer();
	
private:
	class UNavigationSystemV1* NavigationMesh;

	FVector RandomLocation;
	bool PlayerIsNear;
	FTimerHandle RunAway;
	FTimerHandle PointDelay;
};
