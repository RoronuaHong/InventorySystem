// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces.h"
#include "Structure/SlotStructure.h"
#include "Structure/ItemStructure.h"
#include "Item.generated.h"

class UItemInfo;
class USphereComponent;
class UInventoryComponent;
class AMyPlayerController;

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

	UPROPERTY(Instanced, VisibleDefaultsOnly, Category="Component")
	USphereComponent* SphereComp;

	UPROPERTY(Instanced, VisibleDefaultsOnly, Category="Component")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(Instanced, EditInstanceOnly, BlueprintReadOnly, Meta=(ExposeOnSpawn = true))
	UInventoryComponent* InventoryComp;

	UPROPERTY()
	FItemStructure ItemStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default")
	FSlotStructure SlotStruct;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Meta = (ExposeOnSpawn = true))
	UItemInfo* ItemInfoHUD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	FVector2D position;

	AMyPlayerController* MyPlayerController;

	virtual void OnInteracts(AActor* Interactor);
	virtual void OnInteracts_Implementation(AActor* Interactor);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	FItemStructure GetItemStruct() {
		return ItemStruct;
	}

	virtual bool OnUseItem() PURE_VIRTUAL(AItem::OnUseItem, return false;);

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
