// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Structure/SlotStructure.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class AActor;
class UInventoryWindow;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INVENTORYSYSTEMS_API UInventoryComponent: public UActorComponent {
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	FText InventoryName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 NumberOfSlots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TArray<FSlotStructure> InventoryArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	UObject* InventoryWindow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Meta = (ExposeOnSpawn = true))
	UInventoryWindow* InventoryWindowHUD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	FVector2D position;

	UPROPERTY(Instanced, EditInstanceOnly, BlueprintReadOnly, Meta = (ExposeOnSpawn = true))
	UInventoryComponent* InventoryComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Meta = (ExposeOnSpawn = true), Category = "Items")
	TArray<FSlotStructure> InvenItem;

	int32 InvenNum;

	int32 Index;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void SetInventoryName(FText Name);

	FText GetInventoryName();

	UFUNCTION()
	int32 GetNumberOfSlots() {
		return NumberOfSlots;
	}

	UFUNCTION()
	void SetNumberOfSlots(int32 NumbOfSlots);

	UFUNCTION()
	TArray<FSlotStructure> GetInventoryArray() {
		return InventoryArray;
	}

	UFUNCTION()
	void SetInventoryArray(const TArray<FSlotStructure>& Array);

	UFUNCTION(BlueprintCallable)
	void ToggleInventory();

	UFUNCTION(BlueprintCallable)
	bool AddToInventory(FSlotStructure SlotCont);

	UFUNCTION(BlueprintCallable)
	void PrepareInventory();

	UFUNCTION(BlueprintCallable)
	bool OnInventoryQuery(TSubclassOf<AActor> QueryItemClass, int32 QueryAmount);

	bool CreateStack(FSlotStructure SlotCont);
	bool AddToStack(FSlotStructure SlotStruct, int32 SlotIndex);
};
