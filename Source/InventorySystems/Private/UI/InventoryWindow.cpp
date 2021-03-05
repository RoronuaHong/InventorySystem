// Fill out your copyright notice in the Description page of Project Settings.


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
	
}

void UInventoryWindow::NativeTick(const FGeometry& MyGeometry, float DeltaTime) {
	// FIXME: 待优化
	APlayerController* MyPlayerController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	if(!HasUserFocus(MyPlayerController)) {
		SetUserFocus(MyPlayerController);
	}
}

void UInventoryWindow::NativeConstruct() {
	Super::NativeConstruct();

	ButtonClose->OnReleased.AddUniqueDynamic(this, &UInventoryWindow::OnToggleClicked);

	// FIXME: 待优化
	ABaseCharacter* MyCharacter = Cast<ABaseCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if(MyCharacter) {
		InventoryComp = MyCharacter->InventoryComp;

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
}

FReply UInventoryWindow::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) {
	if(InKeyEvent.GetKey() == EKeys::Tab) {
		HandleToggleInventory();

		return FReply::Handled();
	}

	return FReply::Handled();
}

void UInventoryWindow::OnToggleClicked() {
	HandleToggleInventory();
}

void UInventoryWindow::HandleToggleInventory() {
	// FIXME: 待优化
	ABaseCharacter* MyCharacter = Cast<ABaseCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if(MyCharacter) {
		InventoryComp = MyCharacter->InventoryComp;

		if(InventoryComp) {
			InventoryComp->ToggleInventory();
		}
	}
}

void UInventoryWindow::SetInventoryTitle(FText Title) {
	InventoryTitle->SetText(Title);
}
