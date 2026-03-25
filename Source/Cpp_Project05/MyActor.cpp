// MyActor.cpp

#include "MyActor.h"
#include "Engine/Engine.h"	// 화면에 메시지 출력하려고 불러온 공구통
#include "Math/UnrealMathUtility.h"	// 랜덤값 생성을 위해 불러온 공구통

AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(0.f, 50.f, 0.f));	// 시작 위치

	for (int i = 0; i < 10; i++)	// 10번 반복
	{
		float X = FMath::RandRange(-1000.f, 1000.f);	// 랜덤 이동 값 (X 방향)
		float Y = FMath::RandRange(-1000.f, 1000.f);	// 랜덤 이동 값 (Y 방향)
		float Z = FMath::RandRange(0.f, 100.f);	// 랜덤 이동 값 (Z 방향)
		float Yaw = FMath::RandRange(0.f, 360.f);	// 랜덤 회전 값

		Move(X, Y, Z);	// 이동 함수 호출

		Turn(0.f, Yaw, 0.f);	// 회전 함수 호출

		// 화면에 정보 출력
		if (GEngine)
		{
			// 현재 좌표 출력
			GEngine->AddOnScreenDebugMessage(
				-1,
				10.0f,
				FColor::Blue,
				FString::Printf(TEXT("Actor : %s"), *GetActorLocation().ToString())
			);
		}
	}
}

void AMyActor::Move(float X, float Y, float Z)
{
	X = FMath::RandRange(-1000.f, 1000.f);
	Y = FMath::RandRange(-1000.f, 1000.f);
	Z = FMath::RandRange(0.f, 100.f);

	FVector NewLocation = FVector(X, Y, Z);	// 새로운 좌표 생성

	SetActorLocation(NewLocation);	// 새로운 좌표로 이동
}

void AMyActor::Turn(float Pitch, float Yaw, float Roll)
{
	SetActorRotation(FRotator(Pitch, Yaw, Roll));	// 회전값 설정
}

void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

