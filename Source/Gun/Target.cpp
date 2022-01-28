// Fill out your copyright notice in the Description page of Project Settings.
#include "Target.h"

// Sets default values
ATarget::ATarget()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(SceneRoot);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	Hitbox = CreateDefaultSubobject<UBoxComponent>(TEXT("Hitbox"));
	Hitbox->SetupAttachment(Mesh);

}

// Called when the game starts or when spawned
void ATarget::BeginPlay()
{
	Super::BeginPlay();
	Hitbox->OnComponentBeginOverlap.AddDynamic(this, &ATarget::OnOverlap);
}

// Called every frame
void ATarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATarget::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("stepping on"));
	//if (OtherActor->IsA(Bullet) && traveltime>1.f) //stoppe deg fra å teleporte på stedet du står
	//{
	//	teleport playercharacter hit
	//}
}


