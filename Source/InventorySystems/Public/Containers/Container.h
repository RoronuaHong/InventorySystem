// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces.h"
#include "GameFramework/Actor.h"
#include "Structure/SlotStructure.h"
#include "Container.generated.h"

class UBoxComponent;
class UInventoryComponent;

UCLASS()
class INVENTORYSYSTEMS_API AContainer : public AActor, public IInterfaces
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AContainer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Meta = (ExposeOnSpawn = true))
	UInventoryComponent* InventoryComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Meta = (ExposeOnSpawn = true))
	UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Meta = (ExposeOnSpawn = true), Category = "Items")
	TArray<FSlotStructure> InvenItem;

	TArray<FSlotStructure> InvenArray;

	int SlotNumber = 16;

	virtual void OnInteracts(AActor* Interactor);
	virtual void OnInteracts_Implementation(AActor* Interactor);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
