// Fill out your copyright notice in the Description page of Project Settings.


#include "ThiefCatcher.h"
#include "Kismet/KismetSystemLibrary.h"
#include <Kismet/GameplayStatics.h>

AThiefCatcher::AThiefCatcher() : Super()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 500.0f;


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	Camera->SetupAttachment(SpringArm);

	SpringArm->bUsePawnControlRotation = true;
	Camera->bUsePawnControlRotation = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	
}

void AThiefCatcher::SetupPlayerInputComponent(UInputComponent* MyPlayerInput)
{
	Super::SetupPlayerInputComponent(MyPlayerInput);

	MyPlayerInput->BindAxis("MoveForwardBackward", this, &AThiefCatcher::MoveForwardBackward);
	MyPlayerInput->BindAxis("MoveRightLeft", this, &AThiefCatcher::MoveRightLeft);

	MyPlayerInput->BindAxis("Turn", this, &AThiefCatcher::AddControllerYawInput);
	MyPlayerInput->BindAxis("LookUpDown", this, &AThiefCatcher::AddControllerPitchInput);

	MyPlayerInput->BindAction("Jump", IE_Pressed, this, &AThiefCatcher::Jump);
	MyPlayerInput->BindAction("Jump", IE_Released, this, &AThiefCatcher::StopJump);



	MyPlayerInput->BindAction("Sprint", IE_Pressed, this, &AThiefCatcher::Sprint);
	MyPlayerInput->BindAction("Sprint", IE_Released, this, &AThiefCatcher::StopSprint);



}

void AThiefCatcher::MoveForwardBackward(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void AThiefCatcher::MoveRightLeft(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void AThiefCatcher::Jump()
{
	bPressedJump = true;

	if (JumpAnimation)
	{
		PlayAnimMontage(JumpAnimation, 1.0f, NAME_None);
	}
}

void AThiefCatcher::StopJump()
{
	bPressedJump = false;
}

void AThiefCatcher::Sprint()
{
	bIsSprint = true;
	GetCharacterMovement()->MaxWalkSpeed = 1200.0f;
}

void AThiefCatcher::StopSprint()
{
	bIsSprint = false;
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;
}

void AThiefCatcher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TouchEnemy();


	if (bIsSprint && GetStamina() > 0.0f)
	{
		DecreaseStamina(0.5f);
	}
	else if (!bIsSprint && GetStamina() < 100.0f)
	{
		IncreaseStamina();
	}

	if (FMath::IsNearlyZero(GetStamina()))
	{
		StopSprint();
	}
}

void AThiefCatcher::AddStamina_Implementation(float AddStamina)
{
	IncreaseStamina(AddStamina);
}

void AThiefCatcher::TouchEnemy()
{
	FVector TraceStart = GetActorLocation();
	FRotator CharacterRotation = GetActorRotation();

	FVector TraceEnd = TraceStart + CharacterRotation.Vector() * 300.f;
	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	bool bIsHit = GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECC_Visibility, QueryParams);

	if (HitResult.bBlockingHit)
	{
		AActor* Target = HitResult.GetActor();

		if (Target->ActorHasTag(FName(TEXT("Thief"))))
		{
			UKismetSystemLibrary::QuitGame(this, UGameplayStatics::GetPlayerController(this, 0), EQuitPreference::Quit, true);
		}
	}
}
