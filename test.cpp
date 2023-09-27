// Fill out your copyright notice in the Description page of Project Settings.


#include "test.h"
#include "Drone.h"



// Sets default values
Atest::Atest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Log, TEXT("Constructor"));
	DroneClass = ADrone::StaticClass(); //�߰��� �ڵ�
}

// Called when the game starts or when spawned
void Atest::BeginPlay()
{
	Super::BeginPlay();

	FString path;
	path = FPaths::ProjectContentDir() + "test/test1.txt";
	if (FPaths::FileExists(path))
	{
		FString fileContents;
		if (FFileHelper::LoadFileToString(fileContents, *path))
		{
			TArray<FString> Lines;
			fileContents.ParseIntoArrayLines(Lines);
			// �� ���� �Ľ��Ͽ� ��� ������Ʈ ����
			for (const FString& Line : Lines)
			{
				TArray<FString> Tokens;
				Line.ParseIntoArray(Tokens, TEXT(","), true);
				if (Tokens.Num() == 4)
				{
					int32 DroneID = FCString::Atoi(*Tokens[0]);
					float LocX = FCString::Atof(*Tokens[1]);
					float LocY = FCString::Atof(*Tokens[2]);
					float LocZ = FCString::Atof(*Tokens[3]);
					UE_LOG(LogTemp, Log, TEXT("%d %f %f %f"), DroneID, LocX, LocY, LocZ);

					// ��� ������Ʈ ���� �� ��ġ ����
					FVector SpawnLocation(LocX, LocY, LocZ);
					// ��� ������Ʈ ����
					AActor* NewDrone = GetWorld()->SpawnActor<AActor>(DroneClass, SpawnLocation, FRotator::ZeroRotator);


					if (NewDrone)
					{
						UE_LOG(LogTemp, Log, TEXT("Oh my god!"));

						/*
						// ���Ǿ� ���Ϳ� ��ü �޽� ������Ʈ�� �߰�
						UStaticMeshComponent* SphereMeshComponent = NewDrone->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

						// ��ü �޽ø� ���� (������Ʈ�� ���Ե� ��ü �޽� �Ǵ� �������� �����ϴ� �⺻ ��ü �޽ø� ����� �� ����)
						static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));

						if (SphereMeshAsset.Succeeded())
						{
							SphereMeshComponent->SetStaticMesh(SphereMeshAsset.Object);
						}

						// ��ü ������ ������ ���� �Ǵ� �ٸ� ���ϴ� ������ �߰��� �� �ֽ��ϴ�.
						// �� �κп��� ���� ������ ��� ������Ʈ�� ���ϴ� ������� ������ �� �ֽ��ϴ�.
						// ���� ���, ��� ��, �ؽ�ó, ���� ���� ���� ������ �� �ֽ��ϴ�.
						 // ��� ������ ���� ��ġ ���
						FVector DroneLocation = NewDrone->GetActorLocation();
						// ��� ������ ��ġ�� �α׿� ���
						UE_LOG(LogTemp, Log, TEXT("Drone Location: %s"), *DroneLocation.ToString());
						
						*/
						
					}
				}
			}
		}
	}

		

	UE_LOG(LogTemp, Log, TEXT("!!!!!path : %s"), *path);


}

// Called every frame
void Atest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

