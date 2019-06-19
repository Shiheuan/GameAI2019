#pragma once
#include "BaseGameEntity.h"
#include <map>
#include <cassert>
#include <string>


// �ú��ṩ�� EntityManager ��һ��ʵ���ķ���
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
	// �÷����洢ָ��ʵ���ָ����std::vector��
	// m_Entities ������λ������ʵ���ID��ʾ����ø����ٵķ��ʣ�
	void RegisterEntity(BaseGameEntity* NewEntity);
	BaseGameEntity* GetEntityFromID(int id)const;
	void RemoveEntity(BaseGameEntity* pEntity);
};

