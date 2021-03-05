// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Components/SphereComponent.h"
#include "Components/InventoryComponent.h"

#include "BaseCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Components/InventoryComponent.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));

	RootComponent = MeshComp;

	SphereComp->SetupAttachment(MeshComp);
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::Interact(AActor* Interactor) {
	auto InvenComp = static_cast<UInventoryComponent*>((Interactor->GetComponentByClass(UInventoryComponent::StaticClass())));

	if(InvenComp->AddToInventory(SlotStruct)) {
		Destroy();
	}
}
