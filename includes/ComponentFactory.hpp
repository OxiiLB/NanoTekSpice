/*
** EPITECH PROJECT, 2024
** CreateComponent
** File description:
** CreateComponent
*/


#ifndef COMPONENT_FACTORY_HPP_
    #define COMPONENT_FACTORY_HPP_

    #include <memory>
    #include <string>
    #include <unordered_map>
    #include <functional>
    #include "IComponent.hpp"

    namespace nts {
        class ComponentFactory {
            public:
                ComponentFactory();
                ~ComponentFactory();

                std::unique_ptr<IComponent> createComponent(const std::string &type);
                std::unique_ptr<IComponent> createAndComponent() const;
                std::unique_ptr<IComponent> createOrComponent() const;
                std::unique_ptr<IComponent> createClockComponent() const;
                std::unique_ptr<IComponent> createTrueComponent() const;

            protected:
                std::unordered_map<std::string, std::function<std::unique_ptr<IComponent>()>> _FunctionTab;
            };
    }

#endif
