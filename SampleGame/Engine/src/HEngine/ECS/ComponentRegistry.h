#pragma once

#include "..\Core\UUID.h"
#include <unordered_map>
#include <typeindex>
#include <memory>
#include <cassert>

#include "../Initializations/Core.h"

namespace HEngine {

	class IComponentStorage {
	public:
		virtual ~IComponentStorage() = default;
		virtual void Remove(UUID id) = 0;
	};

	template<typename T>
	class ComponentStorage : public IComponentStorage {
	public:
		void Add(UUID id, T component) {
			m_Components[id] = std::move(component);
		}

		void Remove(UUID id) override {
			m_Components.erase(id);
		}

		T* Get(UUID id) {
			auto it = m_Components.find(id);
			return it != m_Components.end() ? &it->second : nullptr;
		}

		bool Has(UUID id) const {
			return m_Components.find(id) != m_Components.end();
		}

	private:
		std::unordered_map<UUID, T> m_Components;
	};

	class HENGINE_API ComponentRegistry {
	public:
		template<typename T>
		void Add(UUID id, T component) {
			GetOrCreateStorage<T>()->Add(id, std::move(component));
		}

		template<typename T>
		void Remove(UUID id) {
			GetStorage<T>()->Remove(id);
		}

		template<typename T>
		T* Get(UUID id) {
			auto* storage = GetStorage<T>();
			return storage ? storage->Get(id) : nullptr;
		}

		template<typename T>
		bool Has(UUID id) {
			auto* storage = GetStorage<T>();
			return storage && storage->Has(id);
		}

		void RemoveAllComponents(UUID id) {
			for (auto& [type, storage] : m_Storages)
				storage->Remove(id);
		}


		//// Prevent copy
		//ComponentRegistry(const ComponentRegistry&) = delete;
		//ComponentRegistry& operator=(const ComponentRegistry&) = delete;

		//// Allow move
		//ComponentRegistry(ComponentRegistry&&) noexcept = default;
		//ComponentRegistry& operator=(ComponentRegistry&&) noexcept = default;


	private:
		std::unordered_map<std::type_index, std::unique_ptr<IComponentStorage>> m_Storages;

		template<typename T>
		ComponentStorage<T>* GetOrCreateStorage() {
			auto index = std::type_index(typeid(T));
			if (m_Storages.find(index) == m_Storages.end())
				m_Storages[index] = std::make_unique<ComponentStorage<T>>();
			return static_cast<ComponentStorage<T>*>(m_Storages[index].get());
		}

		template<typename T>
		ComponentStorage<T>* GetStorage() {
			auto it = m_Storages.find(std::type_index(typeid(T)));
			return it != m_Storages.end() ? static_cast<ComponentStorage<T>*>(it->second.get()) : nullptr;
		}
	};

}
