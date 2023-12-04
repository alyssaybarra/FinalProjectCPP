// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_AIController.h"

#include "NPC.h"

ANPC_AIController::ANPC_AIController(FObjectInitializer const& ObjectInitializer)
{
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
