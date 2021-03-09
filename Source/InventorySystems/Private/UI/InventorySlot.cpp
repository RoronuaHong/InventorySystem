// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InventorySlot.h"
#include "Components/Image.h"
#include "BaseCharacter.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InventoryComponent.h"
#include "Input/Reply.h"
#include "Item.h"
#include "Structure/SlotStructure.h"
#include "Structure/ItemStructure.h"

UInventorySlot::UInventorySlot(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer) {

}

void UInventorySlot::NativeConstruct() {
	Super::NativeConstruct();

	ItemThumbnail->SetBrushFromTexture(SlotContents.ItemStructure.Thumbnail);

	ItemQuantity->SetText(FText::AsNumber(SlotContents.Quantity));

	SetItemNumHidden(SlotContents);
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

FReply UInventorySlot::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) {
	if(InMouseEvent.IsMouseButtonDown(EKeys::RightMouseButton)) {
		MyCharacter = Cast<ABaseCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

		if(InventoryComp == MyCharacter->InventoryComp) {
			CurrentInvenArray = MyCharacter->InventoryComp->GetInventoryArray();
			
			if(CurrentInvenArray[SlotIndex].Quantity > 0) {
				DefaultClass = SlotContents.ItemStructure.ItemClass;
				DefaultActor = Cast<AItem>(DefaultClass->GetDefaultObject());

				bool bConsumable = SlotContents.ItemStructure.bComsumable;
				bool bUseItem = DefaultActor->OnUseItem();

				if(bUseItem == bConsumable) {
					DefaultActor->Destroy();

					CurrentInvenArray[SlotIndex].Quantity = CurrentInvenArray[SlotIndex].Quantity - 1;
				}

				ItemQuantity->SetText(FText::AsNumber(CurrentInvenArray[SlotIndex].Quantity));

				if(CurrentInvenArray[SlotIndex].Quantity <= 0) {
					RefreshSlot();
				}
			}
		} else {
			CurrentInvenArray = InventoryComp->GetInventoryArray();

			if(CurrentInvenArray[SlotIndex].Quantity > 0) {
				// FIXME: 一次性全部获取
				if(MyCharacter->InventoryComp->AddToInventory(CurrentInvenArray[SlotIndex])) {
					RefreshSlot();
				}
			}
		}

		InventoryComp->SetInventoryArray(CurrentInvenArray);
	}

	return FReply::Handled();
}

void UInventorySlot::RefreshSlot() {
	FItemStructure ItemStructure;
	FSlotStructure SlotStructure(ItemStructure, 0);

	CurrentInvenArray[SlotIndex] = SlotStructure;

	ItemThumbnail->SetBrushFromTexture(CurrentInvenArray[SlotIndex].ItemStructure.Thumbnail);

	SetItemNumHidden(CurrentInvenArray[SlotIndex]);
}

void UInventorySlot::SetItemNumHidden(FSlotStructure SlotStruct) {
	if(SlotStruct.Quantity <= 0) {
		ItemQuantity->SetVisibility(ESlateVisibility::Hidden);
	}
}
