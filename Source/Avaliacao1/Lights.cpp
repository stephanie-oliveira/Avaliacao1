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

	RootComponent = Sprite;
	
}

// Called when the game starts or when spawned
void ALights::BeginPlay()
{
	Super::BeginPlay();

	AISequencia();
}

// Called every frame
void ALights::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );


}


void ALights::DropLight() {

//	SetIsActived(false);
	Sprite->SetSprite(ClosedSprite);
	UWorld *World = GetWorld();

	World->GetTimerManager().ClearTimer(FuzeTimerHandle);

	if (World != nullptr) {
		AGeniusPawn* Pawn = Cast <AGeniusPawn>(UGameplayStatics::GetPlayerController(World, 0)->GetControlledPawn());
		if (Pawn->SequenciaComputador.Num() < 5) {
			Pawn->Gerenciador();
			IsPlayer = false;
		}
		else {
			IsPlayer = true;
		}
	}


}

void ALights::ShineLight() {

	Sprite->SetSprite(OpenedSprite);

	GetWorld()->GetTimerManager().SetTimer(FuzeTimerHandle, this, &ALights::DropLight, 1.0f, true);

}

void  ALights::AISequencia() {
		UWorld *World = GetWorld();

		if (World != nullptr) {

			AGeniusPawn* Pawn = Cast <AGeniusPawn>(UGameplayStatics::GetPlayerController(World, 0)->GetControlledPawn());
		
			if (GetIndex() == 1) {
				Pawn->SetRedLight(this);
			}
			else if (GetIndex() == 2) {
				Pawn->SetBlueLight(this);
			}
			else if (GetIndex() == 3) {
				Pawn->SetGreenLight(this);
			}
			else if (GetIndex() == 4) {
				Pawn->SetYellowLight(this);

			}
			Pawn->Gerenciador();
	}
}

void ALights::OnTouchBegin(ETouchIndex::Type type, UPrimitiveComponent* TouchedComponent) {

	UWorld *World = GetWorld();
	if (World != nullptr) {
		AGeniusPawn* Pawn = Cast <AGeniusPawn>(UGameplayStatics::GetPlayerController(World, 0)->GetControlledPawn());
			UE_LOG(LogTemp, Warning, TEXT("Click"));
			ShineLight();
			
	}
}




