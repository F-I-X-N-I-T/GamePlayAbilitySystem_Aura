// Copyright FIXNIT GAMES


#include "Actor/AuraDestroyMesh.h"

#include "Actor/AuraDestroyVolume.h"


AAuraDestroyMesh::AAuraDestroyMesh()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	SetRootComponent(MeshComponent);
}

void AAuraDestroyMesh::DestroyMeshBlock()
{
	MeshComponent->DestroyComponent();
	MeshComponent = nullptr;
}
