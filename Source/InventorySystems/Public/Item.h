// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces.h"
#include "Structure/SlotStructure.h"
#include "Structure/ItemStructure.h"
#include "Item.generated.h"

class USphereComponent;
class UInventoryComponent;

UCLASS()
class INVENTORYSYSTEMS_API AItem : public AActor, public IInterfaces
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, Category="Component")
	USphereComponent* SphereComp;

	UPROPERTY(VisibleDefaultsOnly, Category="Component")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Meta=(ExposeOnSpawn = true))
	UInventoryComponent* InventoryComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	FSlotStructure SlotStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	FItemStructure ItemStruct;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact(AActor* Interactor);
};
