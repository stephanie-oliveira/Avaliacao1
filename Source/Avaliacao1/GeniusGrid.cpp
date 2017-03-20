// Fill out your copyright notice in the Description page of Project Settings.

#include "Avaliacao1.h"
#include "GeniusGrid.h"
#include "Lights.h"


// Sets default values
AGeniusGrid::AGeniusGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	ConstructorHelpers::FObjectFinder<UBlueprint> RedBP(TEXT("Blueprint'/Game/Blueprints/Red.Red'"));
	ConstructorHelpers::FObjectFinder<UBlueprint> GreenBP(TEXT("Blueprint'/Game/Blueprints/Green.Green'"));
	ConstructorHelpers::FObjectFinder<UBlueprint> YellowBP(TEXT("Blueprint'/Game/Blueprints/Yellow.Yellow'"));
	ConstructorHelpers::FObjectFinder<UBlueprint> BlueBP(TEXT("Blueprint'/Game/Blueprints/Blue.Blue'"));


	if (RedBP.Succeeded()) {
		RedLight = Cast<UClass>(RedBP.Object->GeneratedClass);
	}

	if (GreenBP.Succeeded()) {
		GreenLight = Cast<UClass>(GreenBP.Object->GeneratedClass);
	}

	if (YellowBP.Succeeded()) {
		YellowLight = Cast<UClass>(YellowBP.Object->GeneratedClass);
	}

	if (BlueBP.Succeeded()) {
		BlueLight = Cast<UClass>(BlueBP.Object->GeneratedClass);
	}

}

// Called when the game starts or when spawned
void AGeniusGrid::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGeniusGrid::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

