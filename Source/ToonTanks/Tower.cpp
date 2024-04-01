// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "Tower.h"


void ATower::Tick(float DeltaTime) 
{
    Super::Tick(DeltaTime);

    if(Tank){
        // Find the distance to the Tank
        float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());

        // Check to see if the Tank is in range
        if(Distance <= FireRange)
        {
            // If in Range, rotate turret toward tank
            RotateTurret(Tank->GetActorLocation());
        }


        
    }
    
   
}

void ATower::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>( UGameplayStatics::GetPlayerPawn(this,0));
}