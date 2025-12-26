// Copyright Wenhi

#pragma once

#include "CoreMinimal.h"
#include "Character/KaijuBaseCharacter.h"
#include "KaijuPlayerCharacter.generated.h"

class AKaijuWeapon;
class UInputMappingContext;
class UInputAction;
class UCameraComponent;
class UInputComponent;
struct FInputActionValue;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFireSignature);
/**
 * 
 */
UCLASS()
class KAIJU_API AKaijuPlayerCharacter : public AKaijuBaseCharacter
{
	GENERATED_BODY()

public:
	AKaijuPlayerCharacter();

	// 在服务器端调用
	virtual void PossessedBy(AController* NewController) override;
	// 在客户端调用
	virtual void OnRep_PlayerState() override;

	UFUNCTION(BlueprintCallable)
	FVector GetWeaponMuzzleLocation() const;

	UFUNCTION(BlueprintCallable)
	AKaijuWeapon* GetWeapon() const { return Weapon; }

	UPROPERTY(BlueprintReadOnly, BlueprintAssignable, BlueprintCallable)
	FOnFireSignature OnFireDelegate;
protected:

	virtual void InitAbilityActorInfo() override;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Weapon")
	TObjectPtr<AKaijuWeapon> Weapon; 

private:
	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Mesh, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* Mesh1P;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CameraComponent;

	
};
