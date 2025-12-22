// Copyright Wenhi

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KaijuWeapon.generated.h"

class USphereComponent;

UCLASS()
class KAIJU_API AKaijuWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	AKaijuWeapon();

protected:

	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USphereComponent> Sphere;
};
