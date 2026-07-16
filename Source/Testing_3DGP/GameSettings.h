// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GameSettings.generated.h"

UCLASS()
class TESTING_3DGP_API UGameSettings : public USaveGame
{
	GENERATED_BODY()
	
public:	


    UPROPERTY() float MasterVolume = 1.f;
    UPROPERTY() float MusicVolume = 1.f;
    UPROPERTY() float SFXVolume = 1.f;
    UPROPERTY() int32 ResolutionIndex = 0; // 0=
    UPROPERTY() float FOV = 90.f;

    // Accessibility
    UPROPERTY() FString Language = "en";
    UPROPERTY() int32 ColorBlindMode = 0;   // 0=None,1=Deuteranopia,2=Protanopia,3=Tritanopia
    UPROPERTY() float ColorBlindIntensity = 1.f;
    UPROPERTY() float UIScale = 1.f;
    UPROPERTY() bool bSubtitlesEnabled = true;
    UPROPERTY() float SubtitleFontSize = 16.f;
    UPROPERTY() bool bReducedMotion = false;
    UPROPERTY() bool bHighContrast = false;

    // Input — stored as a serialized mapping context
    //UPROPERTY() TArray<FCustomBinding> CustomBindings;
};
