// Copyright Wenhi

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KaijuBullet.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UNiagaraSystem;
class UGameplayEffect;

UCLASS()
class KAIJU_API AKaijuBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	AKaijuBullet();
	
	void SetDamage(float InDamage) { Damage = InDamage; }
	
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UNiagaraSystem> ImpactEffect;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USoundBase> ImpactSound;

	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	UPROPERTY(EditDefaultsOnly)
	float LifeSpan = 5.f;

	UPROPERTY()
	float Damage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> DamageEffectClass;
};
