// MyActor.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class CPP_PROJECT05_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	void Move(float X, float Y, float Z);	// 이동 함수
	void Turn(float Pitch, float Yaw, float Roll);	// 회전 함수
};
