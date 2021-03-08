// Fill out your copyright notice in the Description page of Project Settings.


#include "Containers/Container.h"
#include "Structure/ItemStructure.h"
#include "Structure/SlotStructure.h"
#include "Components/BoxComponent.h"
#include "Components/InventoryComponent.h"

// Sets default values
AContainer::AContainer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	InventoryComp = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComp"));
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));

	RootComponent = MeshComp;

	BoxComponent->SetupAttachment(MeshComp);

	FItemStructure ItemStructure;
	FSlotStructure SlotStructure(ItemStructure, 0);

	InvenArray.Init(SlotStructure, SlotNumber);

	InventoryComp->SetInventoryName(FText::FromString("ContainerInventory"));
	InventoryComp->SetNumberOfSlots(SlotNumber);
	InventoryComp->SetInventoryArray(InvenArray);
}

// Called when the game starts or when spawned
void AContainer::BeginPlay()
{
	Super::BeginPlay();
	
	for(int i = 0; i < InvenItem.Num(); i++) {
		InvenArray[i] = InvenItem[i];
	}

	InventoryComp->SetInventoryArray(InvenArray);
}

void AContainer::OnInteracts(AActor* Interactor) {
	InventoryComp->ToggleInventory();
}

void AContainer::OnInteracts_Implementation(AActor* Interactor) {
	InventoryComp->ToggleInventory();
}

// Called every frame
void AContainer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
