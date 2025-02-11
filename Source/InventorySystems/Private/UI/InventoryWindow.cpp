﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InventoryWindow.h"
#include "UI/InventorySlot.h"
#include "Components/TextBlock.h"
#include "Components/GridPanel.h"
#include "BaseCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InventoryComponent.h"
#include "Components/Button.h"
#include "Input/Reply.h"

UInventoryWindow::UInventoryWindow(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
	MyCharacter = Cast<ABaseCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
}

void UInventoryWindow::NativeTick(const FGeometry& MyGeometry, float DeltaTime) {
	APlayerController* MyPlayerController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(this, 0));
}

void UInventoryWindow::NativeConstruct() {
	Super::NativeConstruct();

	ButtonClose->OnReleased.AddUniqueDynamic(this, &UInventoryWindow::OnToggleClicked);

	if(InventoryComp) {
		int32 Num = InventoryComp->GetNumberOfSlots();
		TArray<FSlotStructure> InvenArray = InventoryComp->GetInventoryArray();

		for(int i = 0; i < Num; i++) {
			InventorySlotHUD = CreateWidget<UInventorySlot>(GetWorld(), LoadClass<UInventorySlot>(this,
				TEXT("WidgetBlueprint'/Game/UI/WBP_InventorySlot.WBP_InventorySlot_C'")));

			if(InventorySlotHUD) {
				// 设置SoltIndex
				// 设置SlotContents
				InventorySlotHUD->SetSlotIndex(i);
				InventorySlotHUD->SetSlotContents(InvenArray[i]);
				InventorySlotHUD->SetInventoryComp(InventoryComp);

				InventoryGrid->AddChildToGrid(InventorySlotHUD, i / 8, i % 8);
			}
		}
	}
}

FReply UInventoryWindow::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) {
	if(InKeyEvent.GetKey() == EKeys::Tab || InKeyEvent.GetKey() == EKeys::E) {
		HandleToggleInventory();
	}

	return FReply::Handled();
}

void UInventoryWindow::OnToggleClicked() {
	HandleToggleInventory();
}

void UInventoryWindow::HandleToggleInventory() {
	if(InventoryComp) {
		InventoryComp->ToggleInventory();
	}
}

void UInventoryWindow::SetInventoryTitle(FText Title) {
	InventoryTitle->SetText(Title);
}

void UInventoryWindow::SetInventoryComp(UInventoryComponent* InvenComp) {
	InventoryComp = InvenComp;
}
