// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Components/SphereComponent.h"
#include "Components/InventoryComponent.h"

#include "UI/MyHUD.h"
#include "UI/ItemInfo.h"
#include "BaseCharacter.h"
#include "MyPlayerController.h"
#include "Components/CanvasPanel.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/InventoryComponent.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));

	RootComponent = MeshComp;

	SphereComp->SetupAttachment(MeshComp);

	SlotStruct = FSlotStructure(ItemStruct, 1);
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	MyPlayerController = Cast<AMyPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnOverlapBegin);
	SphereComp->OnComponentEndOverlap.AddDynamic(this, &AItem::OnOverlapEnd);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
		
		ACharacter* MyCharacter = Cast<ACharacter>(OtherActor);

		if(MyCharacter) {
			if(!ItemInfoHUD) {
				ItemInfoHUD = CreateWidget<UItemInfo>(GetWorld(), LoadClass<UItemInfo>(this,
					TEXT("WidgetBlueprint'/Game/UI/WBP_ItemInfo.WBP_ItemInfo_C'")));

				ItemInfoHUD->SetItemName(SlotStruct.ItemStructure.Name);
				ItemInfoHUD->SetItemNumber(FText::AsNumber(SlotStruct.Quantity));

				UMyHUD* CurrentHUD = MyPlayerController->GetWidgetHUD();

				if(CurrentHUD && ItemInfoHUD) {
					UCanvasPanel* CurrentPanel = CurrentHUD->GetHUDCanvas();

					if(CurrentPanel) {
						UCanvasPanelSlot* CurrentPanelSlot = CurrentPanel->AddChildToCanvas(ItemInfoHUD);

						position = FVector2D(500.0f, 0.0f);

						CurrentPanelSlot->SetAutoSize(true);
						CurrentPanelSlot->SetPosition(position);
						CurrentPanelSlot->SetAlignment(FVector2D(0.5, 0.5));
						CurrentPanelSlot->SetAnchors(FAnchors(0.5, 0.5, 0.5, 0.5));
					} else {
						ItemInfoHUD->RemoveFromParent();
						ItemInfoHUD = nullptr;
					}
				}
			}
		}

}

void AItem::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
	ItemInfoHUD->RemoveFromParent();

	ItemInfoHUD = nullptr;
}

void AItem::OnInteracts(AActor* Interactor) {
	auto InvenComp = static_cast<UInventoryComponent*>((Interactor->GetComponentByClass(UInventoryComponent::StaticClass())));

	if(InvenComp->AddToInventory(SlotStruct)) {
		Destroy();
	}
}

void AItem::OnInteracts_Implementation(AActor* Interactor) {
	auto InvenComp = static_cast<UInventoryComponent*>((Interactor->GetComponentByClass(UInventoryComponent::StaticClass())));

	// FIXME: 由蓝图继承来的SlotStruct无法显示.
	if(InvenComp->AddToInventory(SlotStruct)) {
		Destroy();
	}
}
