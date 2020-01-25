// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomeStaticMesh"));
	PlacedLocation = FVector(0.f);
	InitialLocation = FVector(0.f);
	WorldOrgin = FVector(0.f, 0.f, 0.f);
	InitialDirection = FVector(0.f, 0.f, 0.f);
	InitialForce = FVector(200000.f, 0.f, 0.f);
	InitialTorque = FVector(200000.f, 0.f, 0.f);
	bInitializedFloaterLocations = false;
	bShouldFloat = false;
	RunningTime = 0.f;
	Amplitude = 1.f;
	TimeStretch = 1.f;
	RangeJump = 1.f;
}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();

	float InitialX = FMath::FRandRange(-500.f, 500.f);
	float InitialY = FMath::FRandRange(-500.f, 500.f);
	float InitialZ = FMath::FRandRange(0.f, 500.f);

	InitialLocation.X = InitialX;
	InitialLocation.Y = InitialY;
	InitialLocation.Z = InitialZ;

	// InitialLocation *= 500.f;

	PlacedLocation = GetActorLocation();
	if(bInitializedFloaterLocations) {
		SetActorLocation(InitialLocation);
	}

	// StaticMesh->AddForce(InitialForce);
	// StaticMesh->AddTorque(InitialTorque);

	// FVector LocalOffset = FVector(200.f, 0.f, 0.f);
	// FHitResult HitResault;
	// AddActorWorldOffset(LocalOffset, true, &HitResault);
	// AddActorLocalOffset(LocalOffset, true, &HitResault);
	// FRotator Rotation = FRotator(1.f, 0.f, 0.f);
	// AddActorLocalRotation(Rotation);
	// AddActorWorldRotation(Rotation);
}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(bShouldFloat) {
		FVector NewLocation = GetActorLocation();
		NewLocation.X = NewLocation.X + (Amplitude) * FMath::Sin((TimeStretch) * RunningTime) + RangeJump;
		NewLocation.Y = NewLocation.Y + (Amplitude) * FMath::Cos((TimeStretch) * RunningTime) + RangeJump;

		SetActorLocation(NewLocation);
		RunningTime += DeltaTime;
		// FHitResult HitResault;
		// AddActorLocalOffset(InitialDirection, true, &HitResault);
		// FVector HitLocation = HitResault.Location;
		// UE_LOG(LogTemp, Warning, TEXT("Hit locatio: x:%f, y:%f, z:%f"), HitLocation.X, HitLocation.Y, HitLocation.Z);
	}
	// FRotator Rotation = FRotator(1.f, 0.f, 0.f);
	// AddActorLocalRotation(Rotation);
	// AddActorWorldRotation(Rotation);


}

