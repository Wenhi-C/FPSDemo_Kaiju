// Copyright Wenhi

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KaijuEffectActor.generated.h"

class UGameplayEffect;
class USphereComponent;

UCLASS()
class KAIJU_API AKaijuEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AKaijuEffectActor();

	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyState, bool bFromSweep, const FHitResult& SweepResult);

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);
	
private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> SphereComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
};
