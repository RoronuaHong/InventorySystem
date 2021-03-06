// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InventorySlot.h"
#include "Components/Image.h"
#include "BaseCharacter.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InventoryComponent.h"

UInventorySlot::UInventorySlot(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer) {
	
}

void UInventorySlot::NativeConstruct() {
	Super::NativeConstruct();

	ItemThumbnail->SetBrushFromTexture(SlotContents.ItemStructure.Thumbnail);

	ItemQuantity->SetText(FText::AsNumber(SlotContents.Quantity));
}

void UInventorySlot::SetSlotIndex(int32 Index) {
	SlotIndex = Index;
}

int32 UInventorySlot::GetSlotIndex() {
	return SlotIndex;
}

void UInventorySlot::SetSlotContents(FSlotStructure Contents) {
	SlotContents = Contents;
}

FSlotStructure UInventorySlot::GetSlotContents() {
	return SlotContents;
}

void UInventorySlot::SetInventoryComp(UInventoryComponent* InvenComp) {
	InventoryComp = InvenComp;
}

UInventoryComponent* UInventorySlot::GetInventoryComp() {
	return InventoryComp;
}

void UInventorySlot::SetItemQuantity(UTextBlock* Quantity) {

}
