// Fill out your copyright notice in the Description page of Project Settings.

#include "Avaliacao1.h"
#include "GeniusPawn.h"
#include "Lights.h"


// Sets default values
AGeniusPawn::AGeniusPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->ProjectionMode = ECameraProjectionMode::Orthographic;
	Camera->OrthoWidth = 1200.0f;
	Camera->SetupAttachment(RootComponent);
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	i = 1;

}

// Called when the game starts or when spawned
void AGeniusPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGeniusPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AGeniusPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void AGeniusPawn::GerenciarLuzes() {

	UWorld *World = GetWorld();

	if (World != nullptr) {

		if (PosicaoAtual == 1) {
			GetRedLight()->ShineLight();
			UE_LOG(LogTemp, Warning, TEXT("Vermelho 1"));
			GetWorld()->GetTimerManager().ClearTimer(FuzeTimerHandle);

		}
		else if (PosicaoAtual == 2) {
			GetBlueLight()->ShineLight();
			UE_LOG(LogTemp, Warning, TEXT("Azul 2"));
			GetWorld()->GetTimerManager().ClearTimer(FuzeTimerHandle);

		}
		else if (PosicaoAtual == 3) {
			GetYellowLight()->ShineLight();
			UE_LOG(LogTemp, Warning, TEXT("Amarelo 3"));
			GetWorld()->GetTimerManager().ClearTimer(FuzeTimerHandle);

		}
		else if (PosicaoAtual == 4) {
			GetGreenLight()->ShineLight();
			UE_LOG(LogTemp, Warning, TEXT("Verde 4"));
			GetWorld()->GetTimerManager().ClearTimer(FuzeTimerHandle);
		}
	}
}


void AGeniusPawn::GerarSequencia() {

	int32 Random;
	Random = FMath::RandRange(1, 4);
	SequenciaComputador.Add(Random);
	UE_LOG(LogTemp, Warning, TEXT("Sequencia %d"), Random);
}


void AGeniusPawn::Gerenciador() {

	GerarSequencia();

	UWorld *World = GetWorld();
	if (World != nullptr) {
		if (GetRedLight() != nullptr && GetBlueLight() != nullptr && GetYellowLight() != nullptr && GetGreenLight() != nullptr) {
			PosicaoAtual = SequenciaComputador[i];
			GetWorld()->GetTimerManager().SetTimer(FuzeTimerHandle, this, &AGeniusPawn::GerenciarLuzes, 2.0f, true);
			i++;
		}
	}
}

