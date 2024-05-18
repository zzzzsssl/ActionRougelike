// Fill out your copyright notice in the Description page of Project Settings.


#include "SLCharacter.h"
// 为了编译更快，在.h中声明弹簧臂和相机的class，在.cpp引用相应头文件
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ASLCharacter::ASLCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 创建相应实例 <创建的class>("UE中显示的该控件的名字")
	//<> 表示引入c++自带的文件
	//"" 表示引入自定义的文件
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	// 将相应对象attach，RootComponent是根控件，即角色的胶囊体组件
	SpringArmComp->SetupAttachment(RootComponent);

	// 创建相应实例 <创建的class>("UE中显示的该控件的名字")
	// -> 是指向内存中引用的指针
	// ::是用于访问静态方法或者成员
	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void ASLCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// 实现角色向前移动
void ASLCharacter::MoveForward(float Value)
{
	// 朝某个方向前进value，GetActorForwardVector指向角色正前方
	AddMovementInput(GetActorForwardVector(), Value);
}

// 实现角色左右移动
void ASLCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
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

	// “UE中调用的名称”，this指针表示移动这个角色，&自定义移动方法
	PlayerInputComponent->BindAxis("MoveForward", this, &ASLCharacter::MoveForward);

	PlayerInputComponent->BindAxis("MoveRight", this, &ASLCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput); //Yaw控制转向
}

