// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MyHUD.h"
#include "Components/CanvasPanel.h"

UMyHUD::UMyHUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
	//HUDCanvas = CreateDefaultSubobject<UCanvasPanel>(TEXT("Canvas Panel"));
}

void UMyHUD::NativeConstruct() {
	Super::NativeConstruct();
}

UCanvasPanel* UMyHUD::GetHUDCanvas() {
	return HUDCanvas;
}
