// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemInfo.generated.h"

class UTextBlock;

UCLASS()
class INVENTORYSYSTEMS_API UItemInfo : public UUserWidget
{
	GENERATED_BODY()

public:
	UItemInfo(const FObjectInitializer& ObjectInitializer);

	void NativeConstruct() override;

	UPROPERTY(Meta=(BindWidget))
	UTextBlock* ItemName;

	UPROPERTY(Meta=(BindWidget))
	UTextBlock* ItemNumber;

	void SetItemName(FText Name);
	void SetItemNumber(FText Number);
};
