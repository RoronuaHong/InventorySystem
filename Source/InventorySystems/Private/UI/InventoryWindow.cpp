// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InventoryWindow.h"
#include "Components/InventoryComponent.h"

UInventoryWindow::UInventoryWindow(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
	InventoryComp = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComp"));
}
