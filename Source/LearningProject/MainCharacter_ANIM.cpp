// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter_ANIM.h"
#include "GameFramework/CharacterMovementComponent.h"

void UMainCharacter_ANIM::NativeInitializeAnimation()
{
	if (Pawn == nullptr) {
		Pawn = TryGetPawnOwner();
	}
}

void UMainCharacter_ANIM::UpdateAnimationProperties()
{
	if (Pawn == nullptr) {
		Pawn = TryGetPawnOwner();
	}

	if (Pawn) {
		FVector Speed = Pawn->GetVelocity();
		FVector LateralSpeed = FVector(Speed.X, Speed.Y, 0.f);

		MovementSpeed = LateralSpeed.Size();
		IsInAir = Pawn->GetMovementComponent()->IsFalling();
	}
}
