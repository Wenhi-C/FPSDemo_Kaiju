// Copyright Wenhi

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "KaijuAIController.generated.h"

class UBehaviorTreeComponent;
/**
 * 
 */
UCLASS()
class KAIJU_API AKaijuAIController : public AAIController
{
	GENERATED_BODY()
public:
	AKaijuAIController();
protected:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;
};
