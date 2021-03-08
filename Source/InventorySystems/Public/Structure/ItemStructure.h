// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ItemStructure.generated.h"

class AActor;
class UTexture2D;

USTRUCT(BlueprintType)
struct FItemStructure {
	GENERATED_USTRUCT_BODY();

	uint32 UniqueID;

	FORCEINLINE FItemStructure();

	explicit FORCEINLINE FItemStructure(FText Name, bool bStackable, UTexture2D* Thumbnail,
		const int32 MaxStackSize, bool bComsumable, float Durability, FText Description, TSubclassOf<AActor> ItemClass);

	FItemStructure(const FItemStructure& Struct)//复制构造函数
	{
		*this = Struct;
	}

	bool operator==(const FItemStructure& Type) {
		return UniqueID == Type.UniqueID;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bStackable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Thumbnail;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxStackSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bComsumable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Durability;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ItemClass;
};

FORCEINLINE FItemStructure::FItemStructure(): Name(FText::FromString("None")), bStackable(false), Thumbnail(nullptr), MaxStackSize(4),
bComsumable(false), Durability(0), Description(FText::FromString("None")), ItemClass(nullptr) {
	static uint32 ID = 0;

	UniqueID = ID++;

	this->Name = Name;
	this->bStackable = bStackable;
	this->MaxStackSize = MaxStackSize;
	this->Thumbnail = Thumbnail;
	this->Description = Description;
	this->Durability = Durability;
	this->bComsumable = bComsumable;
	this->ItemClass = ItemClass;
}

FORCEINLINE FItemStructure::FItemStructure(FText Name, bool bStackable, UTexture2D* Thumbnail,
	const int32 MaxStackSize, bool bComsumable, float Durability, FText Description, TSubclassOf<AActor> ItemClass): Name(FText::FromString("None")), bStackable(false), Thumbnail(nullptr), MaxStackSize(4),
	bComsumable(false), Durability(0), Description(FText::FromString("None")), ItemClass(nullptr) {
	static uint32 ID = 0;

	UniqueID = ID++;

	this->Name = Name;
	this->bStackable = bStackable;
	this->MaxStackSize = MaxStackSize;
	this->Thumbnail = Thumbnail;
	this->Description = Description;
	this->Durability = Durability;
	this->bComsumable = bComsumable;
	this->ItemClass = ItemClass;
}

//{
//	FText::FromString("None"),
//		false,
//		nullptr,
//		4,
//		false,
//		0,
//		FText::FromString("None")
//}
