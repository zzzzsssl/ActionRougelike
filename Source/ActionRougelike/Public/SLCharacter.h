// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SLCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class ACTIONROUGELIKE_API ASLCharacter : public ACharacter    // A:Actor
{
	GENERATED_BODY()  //宏

public:
	// Sets default values for this character's properties 设置此字符属性的默认值
	ASLCharacter();

protected:

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;
	
	// Called when the game starts or when spawned 在游戏开始或生成时调用
	virtual void BeginPlay() override;

public:	
	// Called every frame 调用每一帧
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input 调用以将功能绑定到输入
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
