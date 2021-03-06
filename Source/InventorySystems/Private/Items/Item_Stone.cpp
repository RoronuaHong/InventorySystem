// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item_Stone.h"

AItem_Stone::AItem_Stone() {
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshCompObj(TEXT("StaticMesh'/Game/Meshes/Var5_LOD2.Var5_LOD2'"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> ThumbnailObj(TEXT("Texture2D'/Game/Images/furture.furture'"));

	UTexture2D* Thumbnail = ThumbnailObj.Object;

	MeshComp->SetStaticMesh(MeshCompObj.Object);

	// TODO: 添加默认Class.
	ItemStruct = FItemStructure(
		FText::FromString("Stone"),
		true,
		Thumbnail,
		4,
		true,
		0,
		FText::FromString("None"),
		AItem_Stone::StaticClass()
	);

	SlotStruct = FSlotStructure(ItemStruct, 3);
}
