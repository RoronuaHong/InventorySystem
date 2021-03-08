// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item_arbor.h"

AItem_arbor::AItem_arbor() {

}

bool AItem_arbor::OnUseItem() {
	UE_LOG(LogTemp, Log, TEXT("arbor"));

	return true;
}
