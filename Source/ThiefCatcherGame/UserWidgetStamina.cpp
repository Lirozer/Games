// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidgetStamina.h"
#include "ThiefCatcher.h"
#include "Kismet/GameplayStatics.h"

float UUserWidgetStamina::GetCharacterStamina()
{
	AThiefCatcher* Player = Cast<AThiefCatcher>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	return Player->GetStamina() / 100.0f;
}
