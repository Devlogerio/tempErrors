// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyObject.generated.h"

/**
 * 
 */
UCLASS(BLUEPRINTABLE)
class TESTPROJECT3RD_API UMyObject : public UObject
{
	GENERATED_BODY()
	
	public:
		UMyObject();

		UPROPERTY(BlueprintReadWrite, Category = "My variables")
		float MyFloat;

		UFUNCTION(BlueprintCallable, Category = "My functions")
		void MyFunction();
};
