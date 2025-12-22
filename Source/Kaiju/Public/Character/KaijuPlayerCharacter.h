// Copyright Wenhi

#pragma once

#include "CoreMinimal.h"
#include "Character/KaijuBaseCharacter.h"
#include "KaijuPlayerCharacter.generated.h"

class UInputMappingContext;
class UInputAction;
class UCameraComponent;
class UInputComponent;
struct FInputActionValue;
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

protected:

	virtual void InitAbilityActorInfo() override;

private:
	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Mesh, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* Mesh1P;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CameraComponent;

};
