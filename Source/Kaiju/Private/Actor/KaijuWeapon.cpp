// Copyright Wenhi


#include "Actor/KaijuWeapon.h"

#include "Components/SphereComponent.h"


AKaijuWeapon::AKaijuWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	SetRootComponent(Sphere);

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	WeaponMesh->SetupAttachment(GetRootComponent());

	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Sphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Sphere->SetCollisionResponseToAllChannels(ECR_Ignore);
	Sphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	
}

void AKaijuWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}


