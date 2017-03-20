// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Lights.generated.h"

UCLASS()
class AVALIACAO1_API ALights : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALights();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION()
		void ShineLight();
	UFUNCTION()
		void DropLight();
	UFUNCTION()
		void AISequencia();



	FORCEINLINE int GetIndex() const { return Index; }
	FORCEINLINE void SetIndex(int NewIndex) { Index = NewIndex; }

	FORCEINLINE bool GetIsActived() const { return IsActived; }
	FORCEINLINE void SetIsActived(bool NewIsActived) { IsActived = NewIsActived; }
	

private:
	
	
	UPROPERTY(EditAnywhere)
		class UPaperSpriteComponent* Sprite;

	UPROPERTY(EditAnywhere)
		class UPaperSprite* OpenedSprite;

	UPROPERTY(EditAnywhere)
		class UPaperSprite* ClosedSprite;

	UPROPERTY(EditAnywhere)
		int Index;

	//booleanas para impedir que as luzes pisquem ao mesmo tempo

	UPROPERTY(EditAnywhere)
		bool IsActived;


	//UFUNCTION()
		//void OnTouchBegin(ETouchIndex::Type type, UPrimitiveComponent* TouchedComponent);

	UPROPERTY(EditAnywhere)
		FTimerHandle FuzeTimerHandle;

};
