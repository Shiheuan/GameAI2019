#pragma once
#include "BaseGameEntity.h"
#include <map>
#include <cassert>
#include <string>


// 用宏提供对 EntityManager 的一个实例的访问
#define EntityMgr EntityManager::Instance()

class EntityManager
{
private:
	typedef std::map<int, BaseGameEntity*> EntityMap;
private:
	EntityMap m_EntityMap;
	EntityManager(){}
	EntityManager(const EntityManager&);
	EntityManager& operator=(const EntityManager&);
public:
	static EntityManager* Instance();
	// 该方法存储指向实体的指针在std::vector中
	// m_Entities 在索引位置上由实体的ID显示（获得更快速的访问）
	void RegisterEntity(BaseGameEntity* NewEntity);
	BaseGameEntity* GetEntityFromID(int id)const;
	void RemoveEntity(BaseGameEntity* pEntity);
};

