// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_AIController.h"

#include "FinalProjectCPPCharacter.h"
#include "NPC.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

ANPC_AIController::ANPC_AIController(FObjectInitializer const& ObjectInitializer)
{
	SetupPerceptionSystem(); 
}

//if the InPawn is the npc then you can get the tree from it 
void ANPC_AIController::OnPossess(APawn* InPawn)
{
	//player posses the pawn of the character 
	Super::OnPossess(InPawn);
	if(ANPC* const npc = Cast<ANPC>(InPawn))
	{
		if(UBehaviorTree* const tree = npc->GetBehaviorTree())
		{
			UBlackboardComponent* b;
			//if one doesnt exist then it will create one 
			UseBlackboard(tree->BlackboardAsset,b);
			Blackboard = b;
			RunBehaviorTree(tree); 
		}
	}
}

void ANPC_AIController::SetupPerceptionSystem()
{
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	if(SightConfig)
	{
		SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(
			TEXT("Perception Component")));
		SightConfig-> SightRadius = 500.f;
		//npc will stop seeing thee player
		SightConfig->LoseSightRadius = SightConfig->SightRadius + 25.f;
		//field of view 
		SightConfig->PeripheralVisionAngleDegrees = 90.f;
		//time after the player being seen is forgotten 
		SightConfig->SetMaxAge(5.f);
		SightConfig->AutoSuccessRangeFromLastSeenLocation = 520.f;
		SightConfig->DetectionByAffiliation.bDetectEnemies = true;
		SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
		SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

		GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
		GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this,
			&ANPC_AIController::OnTargetDetected);
		GetPerceptionComponent()->ConfigureSense(*SightConfig);
		
		
	}
	
}

void ANPC_AIController::OnTargetDetected(AActor* Actor, FAIStimulus const Stimulus)
{
	if(auto* const ch = Cast<AFinalProjectCPPCharacter>(Actor))
	{
		GetBlackboardComponent()->SetValueAsBool("CanSeePlayer", Stimulus.WasSuccessfullySensed());
		
		
	}
}
