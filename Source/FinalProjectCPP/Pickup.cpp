// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/PackageAccessTrackingOps.h"

// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	MyMesh -> SetSimulatePhysics(true);
	RootComponent = MyMesh;

	bHolding = false;
	bGravity = true;
	
} 

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();

	MyCharacter = UGameplayStatics::GetPlayerCharacter(this,0);
	PlayerCamera = MyCharacter->FindComponentByClass<UCameraComponent>();
	TArray<USceneComponent*> Components; 

	//puts into the components TArray 
	MyCharacter -> GetComponents(Components);

	//if the number is greater than 0 then loops through each component
	//if one of the components is equal to the holding components that is what we set it
	//equal to 
	if(Components.Num() > 0 )
	{
		for(auto& Comp: Components)
		{
			if(Comp->GetName() == "HoldingComponent")
			{
				HoldingComp = Cast<USceneComponent>(Comp);
			}
		}
	}
	
}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
//if pickup is being held and holding comp is true then set actor location and rotation
	
	
	if(bHolding && HoldingComp)
	{
		SetActorLocationAndRotation(HoldingComp-> GetComponentLocation(), HoldingComp->GetComponentRotation()); 
	}

}

void APickup::RotateActor()
{
	ControlRotation = GetWorld->GetFirstPlayerController()->GetControlRotation();
	SetActorRotation(FQuat(ControlRotation));
}


