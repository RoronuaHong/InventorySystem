// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

struct result {
	int CurrentIndex;
	bool CurrentBoolean;
};

result HasPartialStack(FSlotStructure SlotStruct, const TArray<FSlotStructure>& InventoryArray) {													\
	int CurrentIndex = 0;																				
	bool CurrentBoolean = false;																		
																										
	for(int Indexs = 0; Indexs < InventoryArray.Num(); Indexs++) {										
																										
		if(SlotStruct.ItemStructure.ItemClass == InventoryArray[Indexs].ItemStructure.ItemClass &&		
			InventoryArray[Indexs].Quantity < SlotStruct.ItemStructure.MaxStackSize) {					
			CurrentIndex = Indexs;																		
			CurrentBoolean = true;														
																										
			break;																						
		}																								
	}																									
																										
	return { CurrentIndex, CurrentBoolean };													
}																										
