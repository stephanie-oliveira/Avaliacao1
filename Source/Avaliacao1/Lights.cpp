// Fill out your copyright notice in the Description page of Project Settings.

#include "Avaliacao1.h"
#include "Lights.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "GeniusPawn.h"



// Sets default values
ALights::ALights()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));

	Sprite->SetSprite(ClosedSprite);

	Sprite->OnInputTouchBegin.AddDynamic(this, &ALights::OnTouchBegin);
	RootComponent = Sprite;
	
}

// Called when the game starts or when spawned
void ALights::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALights::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ALights::OnTouchBegin(ETouchIndex::Type type, UPrimitiveComponent* TouchedComponent) {

	UWorld *World = GetWorld();
	if (World != nullptr) {
		AGeniusPawn* Pawn = Cast <AGeniusPawn>(UGameplayStatics::GetPlayerController(World, 0)->GetControlledPawn());
		
		if (Pawn->GetRedLight()) {
			Sprite->SetSprite(OpenedSprite);
			UE_LOG(LogTemp, Warning, TEXT("luz vermelha acesa"));

			Pawn->DropLight();

		}
		else if (Pawn->GetBlueLight()) {
			Sprite->SetSprite(OpenedSprite);
			UE_LOG(LogTemp, Warning, TEXT("luz azul acesa"));

		}
		else if (Pawn->GetYellowLight()) {
			Sprite->SetSprite(OpenedSprite);
			UE_LOG(LogTemp, Warning, TEXT("luz amarela acesa"));

		}
		else if (Pawn->GetGreenLight()) {
			Sprite->SetSprite(OpenedSprite);
			UE_LOG(LogTemp, Warning, TEXT("luz verde acesa"));

		}
		
	}
}

