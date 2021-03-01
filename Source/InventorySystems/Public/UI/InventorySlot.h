// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventorySlot.generated.h"

UCLASS()
class INVENTORYSYSTEMS_API UInventorySlot : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UInventorySlot(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(Meta=(BindWidget))
	int32 SlotIndex;


};
