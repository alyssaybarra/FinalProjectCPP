// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "Pickup.generated.h"

UCLASS()
class FINALPROJECTCPP_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MyMesh;
//dummy component
	UPROPERTY(EditAnywhere)
	USceneComponent* HoldingComp;

	UFUNCTION()
	void RotateActor();

	UFUNCTION()
	void Pickup();

	//whether we are holding the object or not 
	bool bHolding;

	//whether the actor has gravity or not
	bool bGravity;

	//control rotation from the controller
	FRotator ControlRotation;


	//gets the character from the scene
	ACharacter* MyCharacter;

	UCameraComponent* PlayerCamera;

	FVector ForwardVector; 
	
};
