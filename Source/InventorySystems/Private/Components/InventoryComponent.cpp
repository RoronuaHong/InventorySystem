// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InventoryComponent.h"
#include "UI/InventoryWindow.h"
#include "MyPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "UI/MyHUD.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	NumberOfSlots = 8;
}


// Called when the game starts
void UInventoryComponent::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UInventoryComponent::SetNumberOfSlots(int32 NumbOfSlots) {
	NumbOfSlots = NumbOfSlots;
}

void UInventoryComponent::SetInventoryArray(TArray<FSlotStructure> Array) {
	InventoryArray = Array;
}

void UInventoryComponent::ToggleInventory() {
	if(!bInventoryVisible) {
		bInventoryVisible = true;

		InventoryWindowHUD = CreateWidget<UInventoryWindow>(GetWorld(), LoadClass<UInventoryWindow>(this,
			TEXT("WidgetBlueprint'/Game/UI/WBP_InventoryWindows.WBP_InventoryWindows_C'")));

		AMyPlayerController* MyPlayerController = Cast<AMyPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

		if(MyPlayerController) {
			UMyHUD* CurrentHUD = MyPlayerController->GetWidgetHUD();

			if(CurrentHUD && InventoryWindowHUD) {
				UCanvasPanel* CurrentPanel = CurrentHUD->GetHUDCanvas();

				if(CurrentPanel) {
					UCanvasPanelSlot* CurrentPanelSlot = CurrentPanel->AddChildToCanvas(InventoryWindowHUD);

					CurrentPanelSlot->SetAutoSize(true);
				}
			}
		}
	}
}
