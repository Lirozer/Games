// Fill out your copyright notice in the Description page of Project Settings.


#include "BoxSpawner.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ABoxSpawner::ABoxSpawner()
{
	SpawnObjectCount = 5;

	BoxSpawner = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxSpawner"));
	BoxSpawner->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

// Called when the game starts or when spawned
void ABoxSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	FTimerHandle SpawnDelay;

	GetWorldTimerManager().SetTimer(SpawnDelay, this, &ABoxSpawner::SpawnActor, 5, bShouldSpawnLoop, 1);
}

void ABoxSpawner::SpawnActor()
{
	FRotator Rotation(0, 0, 0);
	FVector RandomLocation;

	for (int i = 0; i < SpawnObjectCount; i++)
	{
		RandomLocation = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), BoxSpawner->GetScaledBoxExtent());
		GetWorld()->SpawnActor<AActor>(SpawnerClass, RandomLocation, Rotation);
	}

}

