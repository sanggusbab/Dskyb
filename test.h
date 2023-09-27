// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Misc/FileHelper.h"   // ���� ó�� ���� ���
#include "Misc/Paths.h"       // ��� ���� ���
#include "Containers/Array.h" // TArray Ŭ���� ���� ���
#include "UObject/ConstructorHelpers.h" // UObject ���� ���� ���
#include "Components/StaticMeshComponent.h" // ��ü �޽ø� ǥ���ϱ� ���� ���
#include "Engine/World.h"     // ���� ���� ���
#include "Engine/Engine.h"    // ���� ���� ���
#include "test.generated.h"

UCLASS()
class MY2_API Atest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Atest();

protected:
	// Called when the game starts or when spawned

	UPROPERTY(EditAnywhere, Category = "Drone")
		TSubclassOf<AActor> DroneClass; // Drone Ŭ������ �����ϱ� ���� ����
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
