// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

class UMyHUD;

UCLASS()
class INVENTORYSYSTEMS_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMyPlayerController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UMyHUD* WidgetHUD;

public:
	UFUNCTION()
	UMyHUD* GetWidgetHUD();

};
