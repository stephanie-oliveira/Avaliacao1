// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GeniusGrid.generated.h"

UCLASS()
class AVALIACAO1_API AGeniusGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGeniusGrid();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:
	UPROPERTY(EditAnywhere)
		USceneComponent* Root;

	TSubclassOf<class ALights> RedLight;
	TSubclassOf<class ALights> GreenLight;
	TSubclassOf<class ALights> YellowLight;
	TSubclassOf<class ALights> BlueLight;

	int Random;

	
	
};
