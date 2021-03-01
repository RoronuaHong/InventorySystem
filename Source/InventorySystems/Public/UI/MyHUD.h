// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyHUD.generated.h"

class UCanvasPanel;

UCLASS()
class INVENTORYSYSTEMS_API UMyHUD : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UMyHUD(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Meta=(BindWidget, ExposeOnSpawn=true))
	UCanvasPanel* HUDCanvas;

};
