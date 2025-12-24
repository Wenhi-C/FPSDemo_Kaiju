// Copyright Wenhi


#include "AbilitySystem/Ability/KaijuFireAbility.h"

#include "Actor/KaijuBullet.h"

void UKaijuFireAbility::SpawnProjectile(const FVector& SpawnLocation, const FRotator& SpawnRotation)
{
	const bool bIsServer = GetAvatarActorFromActorInfo()->HasAuthority();
	if (!bIsServer) return;

	check(BulletClass);
	
	FTransform SpawnTransform;
	SpawnTransform.SetLocation(SpawnLocation);
	SpawnTransform.SetRotation(SpawnRotation.Quaternion());

	AKaijuBullet* Bullet = GetWorld()->SpawnActorDeferred<AKaijuBullet>(
		BulletClass,
		SpawnTransform,
		GetOwningActorFromActorInfo(),
		Cast<APawn>(GetAvatarActorFromActorInfo()),
		ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

	Bullet->SetOwner(GetAvatarActorFromActorInfo());
	Bullet->SetDamage(Damage);
	
	Bullet->FinishSpawning(SpawnTransform);
}
