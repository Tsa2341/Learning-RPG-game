// Fill out your copyright notice in the Description page of Project Settings.


#include "Critter.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

// Sets default values
ACritter::ACritter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(GetRootComponent());

	Camera->SetRelativeLocation(FVector(-300.f, 0.f, 300.f));
	Camera->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));

	CurrentSpeed = FVector(0.f);
	MaxSpeed = 100.f;

}

// Called when the game starts or when spawned
void ACritter::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void ACritter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector InitialLocation = GetActorLocation();

	FVector NewLocation = InitialLocation + (CurrentSpeed * DeltaTime);
	SetActorRelativeLocation(NewLocation);

}

// Called to bind functionality to input
void ACritter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveHorizontal"), this, &ACritter::MoveHorizontal);
	PlayerInputComponent->BindAxis(TEXT("MoveVertical"), this, &ACritter::MoveVertical);

}

void ACritter::MoveHorizontal(float value)
{
	CurrentSpeed.Y = FMath::Clamp(value, -1.f, 1.f) * MaxSpeed;
}

void ACritter::MoveVertical(float value)
{
	CurrentSpeed.X = FMath::Clamp(value, -1.f, 1.f) * MaxSpeed;
}

