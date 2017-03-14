// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "GeniusPawn.generated.h"

UCLASS()
class AVALIACAO1_API AGeniusPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGeniusPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UFUNCTION()
		void DropLight();

	FORCEINLINE class ALights* GetCurrentLight() const { return CurrentLight; }
	FORCEINLINE void SetCurrentLight(class ALights* NewCurrentLight) { CurrentLight = NewCurrentLight; }


	FORCEINLINE bool GetRedLight() const { return RedLight; }
	FORCEINLINE void SetRedLight(bool NewRedLight) { RedLight = NewRedLight; }

	FORCEINLINE bool GetBlueLight() const { return BlueLight; }
	FORCEINLINE void SetBlueLight(bool NewBlueLight) { BlueLight = NewBlueLight; }

	FORCEINLINE bool GetYellowLight() const { return YellowLight; }
	FORCEINLINE void SetYellowLight(bool NewYellowLight) { YellowLight = NewYellowLight; }

	FORCEINLINE bool GetGreenLight() const { return GreenLight; }
	FORCEINLINE void SetGreenLight(bool NewGreenLight) { GreenLight = NewGreenLight; }

private:

	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		bool RedLight;

	UPROPERTY(EditAnywhere)
		bool BlueLight;

	UPROPERTY(EditAnywhere)
		bool YellowLight;

	UPROPERTY(EditAnywhere)
		bool GreenLight;

	UPROPERTY(EditAnywhere)
		ALights* CurrentLight;

	UPROPERTY(EditAnywhere)
		FTimerHandle FuzeTimerHandle;



	
	
};
