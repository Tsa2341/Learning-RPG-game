// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MainCharacter_ANIM.generated.h"

/**
 * 
 */
UCLASS()
class LEARNINGPROJECT_API UMainCharacter_ANIM : public UAnimInstance
{
	GENERATED_BODY()

public: 
	
	virtual void NativeInitializeAnimation() override;

	UFUNCTION(BlueprintCallable, Category = Animations)
	void UpdateAnimationProperties();

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Animations)
	float MovementSpeed;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Animations)
	bool IsInAir;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Animations)
	class APawn* Pawn;
	
};
