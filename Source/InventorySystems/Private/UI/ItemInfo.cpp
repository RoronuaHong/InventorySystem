// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ItemInfo.h"
#include "Components/TextBlock.h"

UItemInfo::UItemInfo(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer) {

}

void UItemInfo::NativeConstruct() {
	Super::NativeConstruct();
}

void UItemInfo::SetItemName(FText Name) {
	ItemName->SetText(Name);
}

void UItemInfo::SetItemNumber(FText Number) {
	ItemNumber->SetText(Number);
}
