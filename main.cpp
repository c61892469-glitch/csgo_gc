#include "stdafx.h"
#include "platform.h"
#include "config.h"
#include "steam_hook.h"
#include "appid.h"  // FIX: needed for AppId::Init()

void InstallGC(bool dedicated)
{
    Platform::Initialize();
    LoadConfig();
    AppId::Init();  // FIX: apply appid_override to csgo/steam.inf BEFORE the GC
                    //      starts reading ClientVersion. Otherwise GetClientVersion()
                    //      reads the stale file and the old-protocol detection may
                    //      behave inconsistently.
    SteamHookInstall(dedicated);
}