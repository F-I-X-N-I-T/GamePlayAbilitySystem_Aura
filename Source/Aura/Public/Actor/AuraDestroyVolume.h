// Copyright FIXNIT GAMES

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interaction/SaveInterface.h"
#include "AuraDestroyVolume.generated.h"

class AAuraDestroyMesh;
class UBoxComponent;

UCLASS()
class AURA_API AAuraDestroyVolume : public AActor, public ISaveInterface
{
	GENERATED_BODY()
	
public:	
	AAuraDestroyVolume();

	/* Save Interface */
	virtual void LoadActor_Implementation() override;
	/* end Save Interface */

	void DestroyMesh();

	UPROPERTY(BlueprintReadOnly, SaveGame)
	bool bReached = false;
	
protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere)
	TArray<AAuraDestroyMesh*> DestroyMeshes;
private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UBoxComponent> Box;
};
