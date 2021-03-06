#pragma once
#include "dZMCommon.h"
#include "Zone.h"
#include "Spawner.h"
#include <map>

class dZoneManager {
public:
	enum class dZoneNotifier {
		SpawnedObjectDestroyed,
		SpawnedChildObjectDestroyed, //Used for when an object (like a stromling) needs to notify the spawner to respawn a new enemy.
		ReloadZone, //Forces the server and all connects clients to reload the map
		UserJoined,
		UserMoved,
		PrintAllGameObjects, //Using this is a BAD idea in production
		InvalidNotifier
	};

public:
    static dZoneManager* Instance() {
		if (!m_Address) {
			m_Address = new dZoneManager();
		}
		
		return m_Address;
	}
	
	void Initialize(const LWOZONEID& zoneID);
	~dZoneManager();

	Zone* GetZone(); //Gets a pointer to the currently loaded zone.
	void LoadZone(const LWOZONEID& zoneID); //Discard the current zone (if any) and loads a new zone.
	void NotifyZone(const dZoneNotifier& notifier, const LWOOBJID& objectID); //Notifies the zone of a certain event or command.
	void AddSpawner(LWOOBJID id, Spawner* spawner);
	LWOZONEID GetZoneID() const;
	LWOOBJID MakeSpawner(SpawnerInfo info);
	Spawner* GetSpawner(LWOOBJID id);
	void RemoveSpawner(LWOOBJID id);
	std::vector<Spawner*> GetSpawnersByName(std::string spawnerName);
	std::vector<Spawner*> GetSpawnersInGroup(std::string group);
	void Update(float deltaTime);
	Entity* GetZoneControlObject() { return m_ZoneControlObject; }

private:
    static dZoneManager* m_Address; //Singleton
	Zone* m_pZone;
	LWOZONEID m_ZoneID;
    std::map<LWOOBJID, Spawner*> m_Spawners;

	Entity* m_ZoneControlObject;
};
