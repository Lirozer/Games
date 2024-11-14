// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CharacterHUD.generated.h"

/**
 * 
 */
UCLASS()
class THIEFCATCHERGAME_API ACharacterHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	ACharacterHUD();

	virtual void BeginPlay() override;

	TSubclassOf<class UUserWidget> MainHUD;
};
