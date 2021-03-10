// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ItemStructure.h"
#include "SlotStructure.generated.h"

USTRUCT(BlueprintType)
struct FSlotStructure {
	GENERATED_USTRUCT_BODY();

	uint32 UniqueID;

	FORCEINLINE FSlotStructure();

	explicit FORCEINLINE FSlotStructure(FItemStructure ItemStructure, int32 Quantity);

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

// TODO: 序列化
FORCEINLINE FSlotStructure::FSlotStructure() {
	static uint32 ID = 0;

	UniqueID = ID++;

	this->ItemStructure = ItemStructure;
	this->Quantity = Quantity;
}

FORCEINLINE FSlotStructure::FSlotStructure(FItemStructure ItemStructure, int32 Quantity) {
	static uint32 ID = 0;

	UniqueID = ID++;

	this->ItemStructure = ItemStructure;
	this->Quantity = Quantity;
}
