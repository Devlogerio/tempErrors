// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floater.generated.h"

UCLASS()
class TESTPROJECT3RD_API AFloater : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloater();

	UPROPERTY(BluePrintReadWrite, VisibleAnywhere, Category = "Actor mesh components")
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Floater variables")
	FVector InitialLocation;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Floater variables")
	FVector PlacedLocation;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Floater variables")
	FVector WorldOrgin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floater variables")
	FVector InitialDirection;

	UPROPERTY(BluePrintReadWrite, EditInstanceOnly, Category = "Floater variables")
	FVector InitialForce;

	UPROPERTY(BluePrintReadWrite, EditInstanceOnly, Category = "Floater variables")
	FVector InitialTorque;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floater variables")
	bool bShouldFloat;

	UPROPERTY(EditDefaultsOnly ,BluePrintReadWrite, Category = "Floater variables")
	bool bInitializedFloaterLocations;

private:
	float RunningTime;
	UPROPERTY(EditAnywhere, Category = "Floater variables | Wave parameters")
	float Amplitude;
	UPROPERTY(EditAnywhere, Category = "Floater variables | Wave parameters")
	float TimeStretch;
	UPROPERTY(EditAnywhere, Category = "Floater variables | Wave parameters")
	float RangeJump;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
