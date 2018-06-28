// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ShellCmd.h"

#define LOCTEXT_NAMESPACE "FShellCmdModule"

void FShellCmdModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// https://forums.unrealengine.com/development-discussion/c-gameplay-programming/47944-can-i-run-an-external-application-from-ue4-build
	//FPlatformProcess::CreateProc(TEXT("C:\\Users\\Cero\\Desktop\\Test.exe"), nullptr, true, false, false, nullptr, 0, nullptr, nullptr);
	processHandle = FGenericPlatformProcess::CreateProc(TEXT("/home/nick/Desktop/UE4Editor"), nullptr, true, false, false, nullptr, 0, nullptr, nullptr);
}

void FShellCmdModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	FGenericPlatformProcess::CloseProc(processHandle);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FShellCmdModule, ShellCmd)