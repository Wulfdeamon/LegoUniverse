#pragma once
#include "CppScripts.h"

class AmShieldGenerator : public CppScripts::Script
{
public:
    void OnStartup(Entity* self) override;
    void OnProximityUpdate(Entity* self, Entity* entering, std::string name, std::string status) override;
    void OnDie(Entity* self, Entity* killer) override;
    void OnTimerDone(Entity* self, std::string timerName) override;

    void StartShield(Entity* self);
    void BuffPlayers(Entity* self);
    void EnemyEnteredShield(Entity* self, Entity* intruder);
};
