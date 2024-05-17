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
	GENERATED_BODY()  //��

public:
	// Sets default values for this character's properties ���ô��ַ����Ե�Ĭ��ֵ
	ASLCharacter();

protected:

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;
	
	// Called when the game starts or when spawned ����Ϸ��ʼ������ʱ����
	virtual void BeginPlay() override;

public:	
	// Called every frame ����ÿһ֡
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input �����Խ����ܰ󶨵�����
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
