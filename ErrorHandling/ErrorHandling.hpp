/*
** EPITECH PROJECT, 2024
** B-OOP-400-BDX-4-1-tekspice-alea.chlodnik
** File description:
** ErrorHandling
*/

#ifndef ERRORHANDLING_HPP_
    #define ERRORHANDLING_HPP_

    #include <exception>

namespace nts {
    class NoFileException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("No file provided");
            }
    };

    class NoChipsetSectionException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("No .chipsets section found");
            }
    };

    class MultipleChipsetSectionException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Multiple .chipsets sections found");
            }
    };

    class NoChipsetException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("No chipset found");
            }
    };

    class NoLinkSectionException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("No .links section found");
            }
    };

    class MultipleLinkSectionException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Multiple .links sections found");
            }
    };

    class NoLinkException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Links not found");
            }
    };

    class InvalidSectionFormatException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Invalid file format, .links section not under .chipsets section");
            }
    };

    class InvalidComponentException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Invalid component type");
            }
    };

    class RepeatNameException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Component with this name already exists");
            }
    };

    class InexistentComponentNameException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Component with this name not previously declared");
            }
    };

    class SelfLinkException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Cant link a component to itself");
            }
    };

    class NotANumberException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Not a number");
            }
    };

    class GateNotConnectedException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Gate not linked to anything");
            }
    };

    class NoOutputException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("No output found");
            }
    };

    class ImproperLinkLineException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Improper link line");
            }
    };

    class ImproperComponentLineException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Improper component line");
            }
    };

    class InvalidCommandException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Invalid command");
            }
    };

    class InvalidValueException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Invalid value");
            }
    };

    class InvalidNumberOfArgumentsException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Invalid number of arguments");
            }
    };

    // Exception during process
    class PinException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Pin does not exist");
            }
    };

    class ComponentException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Component does not exist");
            }
    };

    class SetlinkException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Pin out of range");
            }
    };

    class MallocFailedException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Malloc failed");
            }
    };

    class FileNotFoundException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("File not found");
            }
    };

    class CantLinkTWoOutputsException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Cant link two outputs");
            }
    };

    class CantLinkTwoInputsException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Cant link two inputs");
            }
    };

    class CantLinkSamePinsTogetherException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Cant link same pins together");
            }
    };

    class CantLinkTwoClocksTogetherException : public std::exception {
        public:
            const char *what() const noexcept override
            {
                return ("Cant link two clocks");
            }
    };
}

#endif /* !ERRORHANDLING_HPP_ */
