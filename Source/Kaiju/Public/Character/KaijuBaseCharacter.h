// Copyright Wenhi

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "KaijuBaseCharacter.generated.h"

UCLASS()
class KAIJU_API AKaijuBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AKaijuBaseCharacter();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USkeletalMeshComponent> Weapon = nullptr;
	

public:	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
