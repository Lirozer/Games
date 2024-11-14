// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"

#include "BoxSpawner.generated.h"

UCLASS()
class THIEFCATCHERGAME_API ABoxSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoxSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UBoxComponent* BoxSpawner;

public:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> SpawnerClass;

	UPROPERTY(EditDefaultsOnly)
	int SpawnObjectCount;

	UPROPERTY(EditDefaultsOnly)
	bool bShouldSpawnLoop;

	void SpawnActor();
};
