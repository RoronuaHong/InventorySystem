// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ItemStructure.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FItemStructure
{
	GENERATED_BODY();

	FORCEINLINE FItemStructure();

	explicit FORCEINLINE FItemStructure(FText Name, bool bStackable, UTexture2D* Thumbnail, 
		const int32 MaxStackSize, bool bComsumable, float Durability, FText Description);

	UPROPERTY(BlueprintReadWrite)
	FText Name;

	UPROPERTY(BlueprintReadWrite)
    bool bStackable;

	UPROPERTY(BlueprintReadWrite)
	UTexture2D* Thumbnail;

	UPROPERTY(BlueprintReadWrite)
	int32 MaxStackSize;

	UPROPERTY(BlueprintReadWrite)
	bool bComsumable;

	UPROPERTY(BlueprintReadWrite)
	float Durability;

	UPROPERTY(BlueprintReadWrite)
	FText Description;

};

FORCEINLINE FItemStructure::FItemStructure(): Name(FText::FromString("None")), bStackable(false), Thumbnail(nullptr), MaxStackSize(4),
bComsumable(false), Durability(0), Description(FText::FromString("None")) {
	
}

FORCEINLINE FItemStructure::FItemStructure(FText Name, bool bStackable, UTexture2D* Thumbnail,
	const int32 MaxStackSize, bool bComsumable, float Durability, FText Description) : Name(FText::FromString("None")), bStackable(false), Thumbnail(nullptr), MaxStackSize(4), 
	bComsumable(false), Durability(0), Description(FText::FromString("None")) {

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