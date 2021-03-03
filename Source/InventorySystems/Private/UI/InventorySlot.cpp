// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InventorySlot.h"
#include "Components/InventoryComponent.h"

UInventorySlot::UInventorySlot(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer) {
	InventoryComp = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComp"));
}

void UInventorySlot::NativeConstruct() {
	Super::NativeConstruct();
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
