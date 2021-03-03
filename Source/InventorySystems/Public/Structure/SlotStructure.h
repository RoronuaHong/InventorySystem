// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ItemStructure.h"
#include "SlotStructure.generated.h"

USTRUCT(BlueprintType)
struct FSlotStructure {
	GENERATED_BODY();

	FORCEINLINE FSlotStructure();

	explicit FORCEINLINE FSlotStructure(FItemStructure ItemStructure, int32 Quantity);

	UPROPERTY(BlueprintReadWrite)
	FItemStructure ItemStructure;

	UPROPERTY(BlueprintReadWrite)
	int32 Quantity;
};

FORCEINLINE FSlotStructure::FSlotStructure() {

}

//FORCEINLINE FSlotStructure::FSlotStructure(FItemStructure ItemStructure, int32 Quantity) {
//
//}

FORCEINLINE FSlotStructure::FSlotStructure(FItemStructure ItemStructure, int32 Quantity): ItemStructure(ItemStructure), Quantity(0) {

}
