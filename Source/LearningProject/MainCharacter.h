// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS()
class LEARNINGPROJECT_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnyWhere, Blueprintable, Meta = (AllowPrivateAccess = true), Category = Camera)
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnyWhere, Blueprintable, Meta = (AllowPrivateAccess = true), Category = Camera)
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnyWhere, Blueprintable, Category = Camera)
	float BaseTurnAtRate;

	UPROPERTY(VisibleAnyWhere, Blueprintable, Category = Camera)
	float BaseLookUpAtRate;

	void MoveVertical(float value);
	void MoveHorizontal(float value);
	void TurnAtRate(float rate);
	void LookUpAtRate(float rate);

};
