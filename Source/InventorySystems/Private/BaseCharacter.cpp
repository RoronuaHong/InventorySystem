﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InventoryComponent.h"
#include "Item.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	InventoryComp = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComp"));

	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SetupAttachment(RootComponent);

	//InventoryComp->SetActive(true);

	CameraComp->SetupAttachment(SpringArmComp);
}

void ABaseCharacter::MoveForward(float Value) {
	AddMovementInput(GetActorForwardVector() * Value);
}

void ABaseCharacter::MoveRight(float Value) {
	AddMovementInput(GetActorRightVector() * Value);
}

void ABaseCharacter::OnInteract() {
	ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);

	if(MyCharacter) {
		TArray<AActor*> OverlappingItems;

		bool ImplementsInterface = MyCharacter->GetClass()->ImplementsInterface(UInterfaces::StaticClass());

		MyCharacter->GetOverlappingActors(OverlappingItems);

		for(AActor* Items : OverlappingItems) {
			AItem* MyItem = Cast<AItem>(Items);

			if(MyItem) {
				if(ImplementsInterface) {
					MyItem->Interact();

					break;
				}
			}
		}
	}
}

void ABaseCharacter::OnInventory() {
	UE_LOG(LogTemp, Log, TEXT("Inventory: %s"), *GetNameSafe(InventoryComp));

	if(InventoryComp) {
		InventoryComp->ToggleInventory();
	}
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	void MoveForward(float Value);
	void MoveRight(float Value);

}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABaseCharacter::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &ABaseCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &ABaseCharacter::AddControllerYawInput);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ABaseCharacter::OnInteract);
	PlayerInputComponent->BindAction("Inventory", IE_Pressed, this, &ABaseCharacter::OnInventory);
}
