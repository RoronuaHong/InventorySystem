// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InventoryWindow.h"
#include "UI/InventorySlot.h"
#include "Components/TextBlock.h"
#include "Components/GridPanel.h"
#include "Components/InventoryComponent.h"

UInventoryWindow::UInventoryWindow(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
	InventoryComp = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComp"));
}

void UInventoryWindow::NativeConstruct() {
	Super::NativeConstruct();

	UE_LOG(LogTemp, Log, TEXT("%s"), *GetNameSafe(InventoryComp));

	// TODO: InventoryComp is nullptr.
	//if(InventoryComp) {

	//	int32 Num = InventoryComp->GetNumberOfSlots();
	//	TArray<FSlotStructure> InvenArray = InventoryComp->GetInventoryArray();

	//	for(int i = 0; i < Num - 1; i++) {
	//		InventorySlotHUD = CreateWidget<UInventorySlot>(GetWorld(), LoadClass<UInventorySlot>(this, 
	//			TEXT("WidgetBlueprint'/Game/UI/WBP_InventorySlot.WBP_InventorySlot_C'")));

	//		// 设置SoltIndex
	//		// 设置SlotContents
	//		InventorySlotHUD->SetSlotIndex(i);
	//		InventorySlotHUD->SetSlotContents(InvenArray[i]);
	//		InventorySlotHUD->SetInventoryComp(InventoryComp);

	//		InventoryGrid->AddChildToGrid(InventorySlotHUD, i % Num, i / Num);
	//	}
	//}
}
