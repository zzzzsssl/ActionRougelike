// Fill out your copyright notice in the Description page of Project Settings.


#include "SLCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ASLCharacter::ASLCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void ASLCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASLCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASLCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

