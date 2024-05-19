// Copyright FIXNIT GAMES

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuraDestroyMesh.generated.h"


UCLASS()
class AURA_API AAuraDestroyMesh : public AActor
{
	GENERATED_BODY()
	
public:
	AAuraDestroyMesh();

	UFUNCTION(BlueprintCallable)
	void DestroyMeshBlock();

private:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComponent;
};
