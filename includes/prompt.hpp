/*
** EPITECH PROJECT, 2024
** Prompt.hpp
** File description:
** prompt
*/

#ifndef PROMPT_HPP_
    #define PROMPT_HPP_

    #include <iostream>
    #include "Circuit.hpp"
    #include <vector>
    #include <unordered_map>
    #include <functional>

    class prompt {
        public:
            prompt();
            ~prompt();

            void run(Circuit &circuit);
            void exit();
            void launch_command(Circuit &circuit);
            std::pair<std::string, nts::Tristate> parse_input(std::string input);
            bool getExit() const { return this->_exit; };

        protected:
            bool _exit;
            std::string _input;
            bool _isLooping;
    };

#endif /* !PROMPT_HPP_ */
