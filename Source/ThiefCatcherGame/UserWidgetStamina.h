// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserWidgetStamina.generated.h"

class AThiefCatcher;

UCLASS()
class THIEFCATCHERGAME_API UUserWidgetStamina : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetCharacterStamina();
};
