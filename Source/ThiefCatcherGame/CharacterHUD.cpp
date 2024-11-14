// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterHUD.h"
#include "Blueprint/UserWidget.h"

ACharacterHUD::ACharacterHUD() : Super()
{
	ConstructorHelpers::FClassFinder<UUserWidget> WBPStamina(TEXT("/Game/Widgets/WBP_Stamina"));

	MainHUD = WBPStamina.Class;
}

void ACharacterHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* CharacterWidget = CreateWidget(GetWorld(), MainHUD);
	CharacterWidget->AddToViewport();
}
