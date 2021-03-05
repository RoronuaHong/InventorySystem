// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/InventoryComponent.h"
#include "UI/InventoryWindow.h"
#include "MyPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "UI/MyHUD.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

#include "BaseCharacter.h"
#include "Kismet/KismetArrayLibrary.h"
#include "Components/InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Index = -1;
	NumberOfSlots = 16;
	
	InventoryName = FText::FromString("Backpack");

	position = FVector2D(500.0f, 0.0f);
}

// Called when the game starts
void UInventoryComponent::BeginPlay() {
	Super::BeginPlay();

	// FIXME: 待优化
	ABaseCharacter* MyCharacter = Cast<ABaseCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if(MyCharacter) {
		InventoryComp = MyCharacter->InventoryComp;

		InvenNum = InventoryComp->GetNumberOfSlots();
		InventoryArray = InventoryComp->GetInventoryArray();
	}

	PrepareInventory();

	FSlotStructure SlotCont;

	CreateStack(SlotCont);
}

// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UInventoryComponent::SetInventoryName(FText Name) {
	InventoryName = Name;
}

FText UInventoryComponent::GetInventoryName() {
	return InventoryName;
}

void UInventoryComponent::SetNumberOfSlots(int32 NumbOfSlots) {
	NumberOfSlots = NumbOfSlots;
}

void UInventoryComponent::SetInventoryArray(TArray<FSlotStructure> Array) {
	InventoryArray = Array;
}

void UInventoryComponent::ToggleInventory() {
	AMyPlayerController* MyPlayerController = Cast<AMyPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	if(!InventoryWindowHUD) {
		InventoryWindowHUD = CreateWidget<UInventoryWindow>(GetWorld(), LoadClass<UInventoryWindow>(this,
			TEXT("WidgetBlueprint'/Game/UI/WBP_InventoryWindows.WBP_InventoryWindows_C'")));

		InventoryWindowHUD->bIsFocusable = true;
		InventoryWindowHUD->SetInventoryTitle(FText::FromString("MyInventory"));

		if(MyPlayerController) {
			UMyHUD* CurrentHUD = MyPlayerController->GetWidgetHUD();

			if(CurrentHUD && InventoryWindowHUD) {
				UCanvasPanel* CurrentPanel = CurrentHUD->GetHUDCanvas();

				if(CurrentPanel) {
					UCanvasPanelSlot* CurrentPanelSlot = CurrentPanel->AddChildToCanvas(InventoryWindowHUD);

					CurrentPanelSlot->SetAutoSize(true);
					CurrentPanelSlot->SetAlignment(FVector2D(0.5, 0.5));
					CurrentPanelSlot->SetAnchors(FAnchors(0.5, 0.5, 0.5, 0.5));
					CurrentPanelSlot->SetPosition(position);

					UWidgetBlueprintLibrary::SetInputMode_UIOnly(MyPlayerController, InventoryWindowHUD, true);
				}
			}
		}
	} else {
		InventoryWindowHUD->RemoveFromParent();
		InventoryWindowHUD = nullptr;

		UWidgetBlueprintLibrary::SetInputMode_GameOnly(MyPlayerController);
	}
}

bool UInventoryComponent::AddToInventory(FSlotStructure SlotCont) {
	if(!SlotCont.ItemStructure.bStackable) {
		return CreateStack(SlotCont);
	}

	return true;
}

// TODO: 需要修改
bool UInventoryComponent::CreateStack(FSlotStructure SlotCont) {
	if(Index < InvenNum && Index >= 0) {
		InventoryArray[Index] = SlotCont;
	}
	
	if(Index >= InvenNum || Index < -1) {
		Index = -2;

		UE_LOG(LogTemp, Log, TEXT("exceed!!!!"));

		return false;
	}

	Index++;

	return true;
}

// TODO: Resize
void UInventoryComponent::PrepareInventory() {
	InventoryArray.SetNum(InvenNum);
}
