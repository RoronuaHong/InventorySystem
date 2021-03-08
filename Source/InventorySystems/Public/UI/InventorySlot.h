// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Structure/SlotStructure.h"
#include "InventorySlot.generated.h"

class AItem;
class UClass;
class UImage;
class UTextBlock;
class ABaseCharacter;
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

	TArray<FSlotStructure> CurrentInvenArray;

	UClass* DefaultClass;

	AItem* DefaultActor;

	ABaseCharacter* MyCharacter;

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

	UFUNCTION()
	void RefreshSlot();

	UFUNCTION()
	void SetItemNumHidden(FSlotStructure SlotStruct);

	UFUNCTION()
	UInventoryComponent* GetInventoryComp();

	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent);
};
