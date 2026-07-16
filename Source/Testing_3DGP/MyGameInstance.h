// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameSettings.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TESTING_3DGP_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	/*
	virtual void Init() override;

	// Game Exit
	virtual void Shutdown() override;

	// --- Settings Access ---
	UFUNCTION(BlueprintCallable, Category = "Game Settings")
	void LoadSettings();

	UFUNCTION(BlueprintCallable, Category = "Game Settings")
	void SaveSettings() const;
	*/

	// Getter for the entire settings object (read-only)
	UFUNCTION(BlueprintPure, Category = "Game Settings")
	UGameSettings* GetSettings() const { return CurrentSettings; }

	/*
	// Individual getters/setters (expose to Blueprints)
	UFUNCTION(BlueprintPure, Category = "Game Settings")
	float GetMasterVolume() const { return CurrentSettings ? CurrentSettings->MasterVolume : 1.f; }

	UFUNCTION(BlueprintCallable, Category = "Game Settings")
	void SetMasterVolume(float NewVolume);

	UFUNCTION(BlueprintCallable, Category = "Game Settings")
	void SetMusicVolume(float NewVolume);

	UFUNCTION(BlueprintCallable, Category = "Game Settings")
	void SetSFXVolume(float NewVolume);

	UFUNCTION(BlueprintCallable, Category = "Game Settings")
	void ChangeLanguage(FString NewLanguage);
	*/


	// ... repeat for MusicVolume, SFXVolume, ResolutionIndex, FOV, Language, etc.
	// Or just expose the whole settings object to Blueprints and let them modify it directly.
	// But for C++ safety, add setters that also auto-save or apply changes.

	// --- Apply settings to engine (optional, but useful) ---
	UFUNCTION(BlueprintCallable, Category = "Game Settings")
	void ApplyAudioSettings() const;

	UFUNCTION(BlueprintCallable, Category = "Game Settings")
	void ApplyVideoSettings() const;  // resolution, FOV, etc.

private:
	// The in‑memory copy of settings (loaded from disk)
	UPROPERTY()
	TObjectPtr<UGameSettings> CurrentSettings;

	// Slot name for SaveGame system
	static const FString SaveSlotName;
	static const int32 UserIndex;
};
