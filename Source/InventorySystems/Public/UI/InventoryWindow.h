// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWindow.generated.h"

class UButton;
class UTextBlock;
class UGridPanel;
class UInventorySlot;
class UInventoryComponent;

UCLASS()
class INVENTORYSYSTEMS_API UInventoryWindow : public UUserWidget
{
	GENERATED_BODY()

protected:
	UInventoryWindow(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Meta=(BindWidget, ExposeOnSpawn=true))
	UButton* ButtonClose;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Meta=(BindWidget, ExposeOnSpawn=true))
	UGridPanel* InventoryGrid;

	UPROPERTY(Meta=(BindWidget))
	UTextBlock* InventoryTitle;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Meta=(ExposeOnSpawn = true))
	UInventoryComponent* InventoryComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Meta=(ExposeOnSpawn = true))
	UInventorySlot* InventorySlotHUD;

	void NativeConstruct() override;

	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent);

	UFUNCTION()
	void OnToggleClicked();

	UFUNCTION()
	void HandleToggleInventory();

public:
	// Called every frame
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;

	void SetInventoryTitle(FText Title);

};
