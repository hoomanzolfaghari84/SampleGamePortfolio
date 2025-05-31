#pragma once
#include <unordered_map>
#include <vector>
#include <functional>
#include <typeindex>
#include <memory>
#include "HEvent.h"
#include <queue>

namespace HEngine {

    class HEventBus {
    public:
        // Listener registration
        template<typename EventType>
        void Subscribe(std::function<void(EventType&)> callback) {
            auto& listeners = listenersMap[typeid(EventType)];
            listeners.push_back([callback](HEvent& event) {
                callback(static_cast<EventType&>(event));
                });
        }

        // Event firing
        template<typename EventType>
        void Publish(EventType& event) {
            auto it = listenersMap.find(typeid(EventType));
            if (it != listenersMap.end()) {
                for (auto& listener : it->second)
                    listener(event);
            }
        }

        template<typename EventType>
        void Queue(std::unique_ptr<EventType> e) {
            eventQueue.push(std::move(e));
        }

        void DispatchAll() {
            while (!eventQueue.empty()) {
                auto& event = *eventQueue.front();
                Publish(event);
                eventQueue.pop();
            }
        }

    private:
        // Vector of listeners for each event type
        std::unordered_map<std::type_index, std::vector<std::function<void(HEvent&)>>> listenersMap;
        std::queue<std::unique_ptr<HEvent>> eventQueue;

    };

}
