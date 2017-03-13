// Fill out your copyright notice in the Description page of Project Settings.

#include "Avaliacao1.h"
#include "Lights.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"


// Sets default values
ALights::ALights()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));

	Sprite->SetSprite(ClosedSprite);

	Sprite->OnInputTouchBegin.AddDynamic(this, &Lights::OnTouchBegin);
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

