// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Critter.generated.h"

UCLASS()
class LEARNINGPROJECT_API ACritter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACritter();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnyWhere, Category = "mesh")
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnyWhere)
	class UCameraComponent* Camera;

	UPROPERTY(EditAnyWhere)
	float MaxSpeed;

private:

	void MoveHorizontal(float value);
	void MoveVertical(float value);

	FVector CurrentSpeed;

};
