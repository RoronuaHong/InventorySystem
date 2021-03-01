// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Structure/SlotStructure.h"
#include "InventorySlot.generated.h"

UCLASS()
class INVENTORYSYSTEMS_API UInventorySlot : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UInventorySlot(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Meta=(BindWidget, ExposeOnSpawn=true))
	int32 SlotIndex;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Meta=(BindWidget, ExposeOnSpawn=true))
	FSlotStructure SlotContents;
};
