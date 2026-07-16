#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/GameViewportClient.h"
#include "Sound/SoundClass.h"
#include "Sound/SoundMix.h"
#include "GameFramework/GameUserSettings.h"
#include "Engine/Engine.h" 

class UGameUserSettings;

void UMyGameInstance::ApplyAudioSettings() const
{
    if (!CurrentSettings) return;

    // Option 1: Using a Sound Mix (recommended)
    // You need to create a SoundMix asset and a Master SoundClass in your content browser.
    // For example: "/Game/Audio/MasterSoundMix.MasterSoundMix" and "/Game/Audio/MasterSoundClass.MasterSoundClass"
    USoundMix* MasterSoundMix = LoadObject<USoundMix>(nullptr, TEXT("/Game/Audio/MasterSoundMix.MasterSoundMix"));
    USoundClass* MasterSoundClass = LoadObject<USoundClass>(nullptr, TEXT("/Game/Audio/MasterSoundClass.MasterSoundClass"));

    if (MasterSoundMix && MasterSoundClass)
    {
        // Set volume (0.0 to 1.0)
        UGameplayStatics::SetSoundMixClassOverride(this, MasterSoundMix, MasterSoundClass, CurrentSettings->MasterVolume, 1.0f, 0.0f, true);
        UGameplayStatics::PushSoundMixModifier(this, MasterSoundMix);
    }
    else
    {
        // Fallback: use console command (less reliable, but works without assets)
        FString Command = FString::Printf(TEXT("Audio.Volume %.2f"), CurrentSettings->MasterVolume);
        UKismetSystemLibrary::ExecuteConsoleCommand(GetWorld(), Command, nullptr);
    }
}

void UMyGameInstance::ApplyVideoSettings() const
{
    if (!CurrentSettings) return;

    // --- Resolution ---
    // Get the engine's user settings object
    UGameUserSettings* UserSettings = GEngine->GetGameUserSettings();
    if (UserSettings)
    {
        // Define your resolution list (or get from monitor)
        TArray<FIntPoint> Resolutions = {
            FIntPoint(1280, 720),
            FIntPoint(1920, 1080),
            FIntPoint(2560, 1440),
            FIntPoint(3840, 2160)
        };
        int32 Index = FMath::Clamp(CurrentSettings->ResolutionIndex, 0, Resolutions.Num() - 1);
        FIntPoint SelectedRes = Resolutions[Index];

        // Apply resolution
        UserSettings->SetScreenResolution(SelectedRes);
        UserSettings->ApplySettings(false);  // false = non‑immediate, ask user to confirm
        // For immediate change without confirmation: UserSettings->ApplyResolutionSettings(false);
    }

    // --- FOV ---
    // FOV is typically stored on the camera component of the player's pawn.
    // We need to get the player's pawn first.
    UWorld* World = GetWorld();
    if (!World) return;

    for (ULocalPlayer* LocalPlayer : GetLocalPlayers())
    {
        APlayerController* PC = LocalPlayer->GetPlayerController(World);
        if (PC && PC->GetPawn())
        {
            // Find the camera component on the pawn
            UCameraComponent* Camera = PC->GetPawn()->FindComponentByClass<UCameraComponent>();
            if (Camera)
            {
                Camera->SetFieldOfView(CurrentSettings->FOV);
            }
            else
            {
                // Alternative: if your camera is on a SpringArm or separate actor, adjust accordingly
                UE_LOG(LogTemp, Warning, TEXT("UCameraComponent not found!"));
            }
        }
    }
}