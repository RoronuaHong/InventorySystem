// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ItemStructure.h"
#include "SlotStructure.generated.h"

USTRUCT(BlueprintType)
struct FSlotStructure {
	GENERATED_USTRUCT_BODY();

	uint32 UniqueID;

	FSlotStructure(): ItemStructure(ItemStructure), Quantity(Quantity) {};

	FSlotStructure(FItemStructure ItemStructure, int32 Quantity): ItemStructure(ItemStructure), Quantity(Quantity) {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FItemStructure ItemStructure;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Quantity;

	FSlotStructure(const FSlotStructure& SlotStruct)//复制构造函数
	{
		*this = SlotStruct;
	}

	bool operator==(const FSlotStructure& Type) {
		return UniqueID == Type.UniqueID;
	}
};