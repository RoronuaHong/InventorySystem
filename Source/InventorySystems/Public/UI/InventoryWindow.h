// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWindow.generated.h"

class UButton;
class UGridPanel;
class UInventoryComponent;

UCLASS()
class INVENTORYSYSTEMS_API UInventoryWindow : public UUserWidget
{
	GENERATED_BODY()

protected:
	UInventoryWindow(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	UButton* ButtonClose;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	UGridPanel* InventoryGrid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	FText InventoryTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInventoryComponent* InventoryComp;
};
