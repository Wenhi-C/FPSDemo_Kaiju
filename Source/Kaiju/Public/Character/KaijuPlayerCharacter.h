// Copyright Wenhi

#pragma once

#include "CoreMinimal.h"
#include "Character/KaijuBaseCharacter.h"
#include "KaijuPlayerCharacter.generated.h"

class UCameraComponent;
/**
 * 
 */
UCLASS()
class KAIJU_API AKaijuPlayerCharacter : public AKaijuBaseCharacter
{
	GENERATED_BODY()

public:
	AKaijuPlayerCharacter();
private:
	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Mesh, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* Mesh1P;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CameraComponent;
};
