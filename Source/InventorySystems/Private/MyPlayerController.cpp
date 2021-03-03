// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "UI/MyHUD.h"

AMyPlayerController::AMyPlayerController() {
	
}

void AMyPlayerController::BeginPlay() {
	Super::BeginPlay();

	WidgetHUD = CreateWidget<UMyHUD>(GetWorld(), LoadClass<UMyHUD>(this, TEXT("WidgetBlueprint'/Game/UI/WBP_HUD.WBP_HUD_C'")));

	if(WidgetHUD) {
		WidgetHUD->AddToViewport();
	}
}

UMyHUD* AMyPlayerController::GetWidgetHUD() {
	return WidgetHUD;
}
