// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindRandomLocation.h"

#include "NavigationSystem.h"
#include "NPC_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_FindRandomLocation::UBTTask_FindRandomLocation(FObjectInitializer const& ObjectInitializer)
{

	NodeName = "Find Random Location In NavMesh"; 
}

EBTNodeResult::Type UBTTask_FindRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//get AI Controller and its NPC
	if(auto* const cont = Cast<ANPC_AIController>(OwnerComp.GetAIOwner()))
	{
		if(auto* const npc = cont->GetPawn())
		{
			//obtain npc location to use as an orgin
			auto const Origin = npc->GetActorLocation();
			//get the naviagation system and generate a random location
			if(auto* const NavSys = UNavigationSystemV1::GetCurrent(GetWorld()))
			{
				FNavLocation Loc;
				//only enters this if statement if it is able to find a random location in the radius 
				if(NavSys->GetRandomPointInNavigableRadius(Origin, SearchRadius, Loc))
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Loc.Location);
					
				}
    
				 FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded; 
			}
			
		}
	}
	
	return EBTNodeResult::Failed; 
}
