// appid hacks
#pragma once

namespace AppId
{

// loads appid_override.txt, rewrites steam.inf if needed
void Init();

// returns the appid provided in appid_override.txt, fallback to 730
uint32_t GetOverride();

// returns ClientVersion parsed from csgo/steam.inf, 0 if not found
// used to keep GC compatible with the client's actual protocol era
uint32_t GetClientVersion();

// if false, the game is running on a "non-valve" app id and we
// should patch serverbrowser and spoof steam stats callbacks
bool IsOriginal();

}