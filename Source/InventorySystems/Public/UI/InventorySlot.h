// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Structure/SlotStructure.h"
#include "InventorySlot.generated.h"

class UImage;
class UTextBlock;
class UInventoryComponent;

UCLASS()
class INVENTORYSYSTEMS_API UInventorySlot : public UUserWidget
{
	GENERATED_BODY()

protected:
	UInventorySlot(const FObjectInitializer& ObjectInitializer);

	void NativeConstruct() override;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Meta=(BindWidget, ExposeOnSpawn=true))
	int32 SlotIndex;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Meta=(BindWidget, ExposeOnSpawn=true))
	FSlotStructure SlotContents;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Meta = (ExposeOnSpawn = true))
	UInventoryComponent* InventoryComp;

	UPROPERTY(Meta=(BindWidget))
	UImage* ItemThumbnail;

	UPROPERTY(Meta=(BindWidget))
	UTextBlock* ItemQuantity;

public:
	UFUNCTION()
	void SetSlotIndex(int32 Index);

	UFUNCTION()
	int32 GetSlotIndex();
	
	UFUNCTION()
	void SetSlotContents(FSlotStructure Contents);

	UFUNCTION()
	FSlotStructure GetSlotContents();

	UFUNCTION()
	void SetInventoryComp(UInventoryComponent* InvenComp);

	UInventoryComponent* GetInventoryComp();

	UFUNCTION()
	void SetItemQuantity(UTextBlock* Quantity);
};
