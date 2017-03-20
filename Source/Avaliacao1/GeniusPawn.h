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
		void GerenciarLuzes();

	UFUNCTION()
		void GerarSequencia();

	UFUNCTION()
		void Gerenciador();

	UPROPERTY(EditAnywhere)
		TArray<int32> SequenciaComputador;

	FORCEINLINE class ALights* GetRedLight() const { return RedLight; }
	FORCEINLINE void SetRedLight(class ALights* NewRedLight) { RedLight = NewRedLight; }

	FORCEINLINE class ALights* GetBlueLight() const { return BlueLight; }
	FORCEINLINE void SetBlueLight(class ALights* NewBlueLight) { BlueLight = NewBlueLight; }

	FORCEINLINE class ALights* GetYellowLight() const { return YellowLight; }
	FORCEINLINE void SetYellowLight(class ALights* NewYellowLight) { YellowLight = NewYellowLight; }

	FORCEINLINE class ALights* GetGreenLight() const { return GreenLight; }
	FORCEINLINE void SetGreenLight(class ALights* NewGreenLight) { GreenLight = NewGreenLight; }

	




private:


	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		ALights* RedLight;

	UPROPERTY(EditAnywhere)
		ALights* BlueLight;

	UPROPERTY(EditAnywhere)
		ALights* YellowLight;

	UPROPERTY(EditAnywhere)
		ALights* GreenLight;


	

	//variaveis que guardam as sequencias para comparação
	

	UPROPERTY(EditAnywhere)
		TArray<int32> SequenciaJogador;

	UPROPERTY(EditAnywhere)
		FTimerHandle FuzeTimerHandle;

	int32 PosicaoAtual;
	int i;



	
	
};
