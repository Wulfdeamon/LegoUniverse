#pragma once
#include "CppScripts.h"

class NtAssemblyTubeServer : public CppScripts::Script
{
public:
	void OnStartup(Entity* self) override;
    void OnPlayerLoaded(Entity* self, Entity* player) override;
    void OnProximityUpdate(Entity* self, Entity* entering, std::string name, std::string status) override;
    void RunAssemblyTube(Entity* self, Entity* player);
    void TeleportPlayer(Entity* self, Entity* player);
    void UnlockPlayer(Entity* self, Entity* player);

private:
    std::map<LWOOBJID, bool> m_TeleportingPlayerTable;
};
