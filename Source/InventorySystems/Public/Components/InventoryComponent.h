// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INVENTORYSYSTEMS_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	FText InventoryName;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	int32 NumberOfSlots;

	//UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	//FText Inventory;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	UObject* InventoryWindow;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
