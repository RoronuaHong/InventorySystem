// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Item_Stone.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEMS_API AItem_Stone : public AItem
{
	GENERATED_BODY()
	
public:
	AItem_Stone();

	bool OnUseItem() override;
};
