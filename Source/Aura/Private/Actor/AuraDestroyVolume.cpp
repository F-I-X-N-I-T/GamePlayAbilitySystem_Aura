// Copyright FIXNIT GAMES


#include "Actor/AuraDestroyVolume.h"

#include "Actor/AuraDestroyMesh.h"
#include "Components/BoxComponent.h"
#include "Interaction/PlayerInterface.h"

// Sets default values
AAuraDestroyVolume::AAuraDestroyVolume()
{
	PrimaryActorTick.bCanEverTick = false;

	Box = CreateDefaultSubobject<UBoxComponent>("Box");
	SetRootComponent(Box);
	Box->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Box->SetCollisionObjectType(ECC_WorldStatic);
	Box->SetCollisionResponseToAllChannels(ECR_Ignore);
	Box->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

void AAuraDestroyVolume::LoadActor_Implementation()
{
	if (bReached)
	{
		Destroy();
		for (AAuraDestroyMesh* Destroy : DestroyMeshes)
		{
			if (IsValid(Destroy))
			{
				Destroy->DestroyMeshBlock();
			}
		}
	}
}

// Called when the game starts or when spawned
void AAuraDestroyVolume::BeginPlay()
{
	Super::BeginPlay();
	Box->OnComponentBeginOverlap.AddDynamic(this, &AAuraDestroyVolume::OnBoxOverlap);
}

void AAuraDestroyVolume::OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor->Implements<UPlayerInterface>()) return;
		
	bReached = true;

	for (AAuraDestroyMesh* Destroy : DestroyMeshes)
	{
		if (IsValid(Destroy))
		{
			Destroy->DestroyMeshBlock();
		}
	}
	Box->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
