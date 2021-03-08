// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/Item_Herb.h"
#include "UObject/ConstructorHelpers.h"

AItem_Herb::AItem_Herb() {
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshCompObj(TEXT("StaticMesh'/Game/Meshes/Var2_LOD2.Var2_LOD2'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> ThumbnailObj(TEXT("Texture2D'/Game/Images/Fortunes.Fortunes'"));

	UTexture2D* Thumbnail = ThumbnailObj.Object;

	MeshComp->SetStaticMesh(MeshCompObj.Object);

	// TODO: 添加默认Class.
	ItemStruct = FItemStructure(
		FText::FromString("GreenHerb"),
		true,
		Thumbnail,
		4,
		true,
		0,
		FText::FromString("None"),
		AItem_Herb::StaticClass()
	);

	SlotStruct = FSlotStructure(ItemStruct, 3);
}

bool AItem_Herb::OnUseItem() {
	UE_LOG(LogTemp, Log, TEXT("heal"));

	return true;
}

