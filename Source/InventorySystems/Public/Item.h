// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces.h"
#include "Item.generated.h"

class USphereComponent;

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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact();
};
