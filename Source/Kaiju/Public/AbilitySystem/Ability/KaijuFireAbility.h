// Copyright Wenhi

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Ability/KaijuGameplayAbility.h"
#include "KaijuFireAbility.generated.h"

class AKaijuBullet;
/**
 * 
 */
UCLASS()
class KAIJU_API UKaijuFireAbility : public UKaijuGameplayAbility
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void SpawnProjectile(const FVector& SpawnLocation, const FRotator& SpawnRotation);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AKaijuBullet> BulletClass;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> DamageEffectClass;
	
	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	float Damage;
};
