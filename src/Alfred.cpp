// Alfred.cpp

#include <iostream>
#include <string>
#include <vector>
#include "Database.h"
#include "PrimitiveContainer.h"

std::vector<Alfred::PrimitiveContainer*> keys;

void welcomeMessage();
void helpList();
void handleInput();
void handleHelp();
void handleObserve(std::string command);
void handleRemember(std::string command);
bool isNumber(std::string input);
void printRememberValue(std::string key, Alfred::PrimitiveContainer* value);

int main() {
    Alfred::Database* database = new Alfred::Database();
    std::cout << "Hello! My name is Alfred :)" << std::endl << std::endl;
    welcomeMessage();
    handleInput();
    std::cout << std::endl << "Bye!" << std::endl << std::endl;
}

void welcomeMessage() {
    std::cout << "I can remember anything you want for you. To get started, here is a list of things I can do:" << std::endl;
    helpList();
    std::cout << "At any time, you can simply type 'help' and I will show you the list of things I can do :)" << std::endl;
}

void helpList() {
    std::cout << "<help>" << "  show this help list" << std::endl;
    std::cout << "<observe [number|phrase] value [number|phrase] key>" << "  observe a value for a key" << std::endl;
    std::cout << "<remember [number|phrase] key>" << "  remember a value for the key" << std::endl;
    std::cout << "<sleep>" << " put me to sleep" << std::endl;
}

void handleInput() {
    bool awake = true;
    while (awake) {
        std::cout << std::endl;

        std::string command;
        std::getline(std::cin, command);

        std::string commandType;
        std::string delimeter = " ";
        size_t position;
        if ((position = command.find(delimeter)) != std::string::npos) {
            commandType = command.substr(0, position);
            command.erase(0, position + delimeter.length());
        } else if (command.length() > 0) {
            commandType = command;
        }

        if (commandType.compare("help") == 0) {
            handleHelp();
        } else if (commandType.compare("observe") == 0) {
            handleObserve(command);
        } else if (commandType.compare("remember") == 0) {
            handleRemember(command);
        } else if (commandType.compare("sleep") == 0) {
            awake = false;
        }
    }
}

void handleHelp() {
    std::cout << "I am happy to help! Here is the help list :)" << std::endl;
    helpList();
}

void handleObserve(std::string command) {
    std::vector<std::string> tokens;
    std::string delimeter = " ";
    size_t position;
    while ((position = command.find(delimeter)) != std::string::npos) {
        tokens.push_back(command.substr(0, position));
        command.erase(0, position + delimeter.length());
    }
    tokens.push_back(command);

    if (tokens.size() != 4) {
        std::cout << "I'm sorry, I don't understand your observe command. An observe command looks like this:" << std::endl;
        std::cout << "<observe [number|phrase] value [number|phrase] key>" << "  observe a value for a key" << std::endl;
        return;
    }
    if ((tokens.at(0).compare("number") != 0) && (tokens.at(0).compare("phrase") != 0)) {
        std::cout << "The first parameter should be either 'number' or 'phrase' so I can know what I am observing. ";
        std::cout << "An observe command looks like this:" << std::endl;
        std::cout << "<observe [number|phrase] value [number|phrase] key>" << "  observe a value for a key" << std::endl;
        return;
    }
    if ((tokens.at(0).compare("number") == 0) && !isNumber(tokens.at(1))) {
        std::cout << "You said the value you want me to observe is a number, but you gave me a value that is not a number. " << std::endl;
        std::cout << "An observe command looks like this:" << std::endl;
        std::cout << "<observe [number|phrase] value [number|phrase] key>" << "  observe a value for a key" << std::endl;
        return;
    }
    if ((tokens.at(2).compare("number") != 0) && (tokens.at(2).compare("phrase") != 0)) {
        std::cout << "The third parameter should be either 'number' or 'phrase' so I can know what I am observing. ";
        std::cout << "An observe command looks like this:" << std::endl;
        std::cout << "<observe [number|phrase] value [number|phrase] key>" << "  observe a value for a key" << std::endl;
        return;
    }
    if ((tokens.at(2).compare("number") == 0) && !isNumber(tokens.at(3))) {
        std::cout << "You said the key you want me to observe is a number, but you gave me a key that is not a number. " << std::endl;
        std::cout << "An observe command looks like this:" << std::endl;
        std::cout << "<observe [number|phrase] value [number|phrase] key>" << "  observe a value for a key" << std::endl;
        return;
    }

    Alfred::PrimitiveContainer* key;
    Alfred::PrimitiveContainer* value;
    if (tokens.at(2).compare("number") == 0) {
        key = new Alfred::PrimitiveContainer(std::stoi(tokens.at(3)));
    } else {
        key = new Alfred::PrimitiveContainer(tokens.at(3));
    }
    if (tokens.at(0).compare("number") == 0) {
        value = new Alfred::PrimitiveContainer(std::stoi(tokens.at(1)));
    } else {
        value = new Alfred::PrimitiveContainer(tokens.at(1));
    }
    Alfred::Database::push(key, value);
    keys.push_back(key);
    std::cout << "I have observed '" << tokens.at(1) << "' for the key '" << tokens.at(3) << "'. Yay! :D" << std::endl;
}

void handleRemember(std::string command) {
    std::vector<std::string> tokens;
    std::string delimeter = " ";
    size_t position;
    while ((position = command.find(delimeter)) != std::string::npos) {
        tokens.push_back(command.substr(0, position));
        command.erase(0, position + delimeter.length());
    }
    tokens.push_back(command);

    if (tokens.size() != 2) {
        std::cout << "I'm sorry, I don't understand your remember command. An remember command looks like this:" << std::endl;
        std::cout << "<remember [number|phrase] key>" << "  remember a value for the key" << std::endl;
    }
    if ((tokens.at(0).compare("number") != 0) && (tokens.at(0).compare("phrase") != 0)) {
        std::cout << "The first parameter should be either 'number' or 'phrase' so I can know what I am remembering. ";
        std::cout << "An remember command looks like this:" << std::endl;
        std::cout << "<remember [number|phrase] key>" << "  remember a value for the key" << std::endl;
        return;
    }
    if ((tokens.at(0).compare("number") == 0) && !isNumber(tokens.at(1))) {
        std::cout << "You said the key is a number, but you gave me a key that is not a number. " << std::endl;
        std::cout << "An remember command looks like this:" << std::endl;
        std::cout << "<remember [number|phrase] key>" << "  remember a value for the key" << std::endl;
        return;
    }

    bool keyIsANumber = tokens.at(0).compare("number") == 0 ? true : false;
    std::string key = command;
    for (Alfred::PrimitiveContainer* container : keys) {
        int contentsNumber;
        std::string contentsString;
        Alfred::PrimitiveContainer* value;
        if (keyIsANumber) {
            container->getData(contentsNumber);
            if (contentsNumber == std::stoi(key)) {
                value = (Alfred::PrimitiveContainer*) Alfred::Database::get(container);
                printRememberValue(key, value);
                return;
            }
        } else {
            container->getData(contentsString);
            if (contentsString.compare(key) == 0) {
                value = (Alfred::PrimitiveContainer*) Alfred::Database::get(container);
                printRememberValue(key, value);
                return;
            }
        }
    }
    std::cout << "I'm sorry, but I don't remember a value for the key '" << key << "'. :(" << std::endl;
}

bool isNumber(std::string input) {
    if (input.at(0) == '-') input.erase(0, 1);
    for (char const& character : input) {
        if (std::isdigit(character) == 0) return false;
    }
    return true;
}

void printRememberValue(std::string key, Alfred::PrimitiveContainer* value) {
    std::string valueString;
    int valueInt;
    std::cout << "I remember the value '";
    if (value->getData(valueInt)) {
        std::cout << valueInt;
    } else if (value->getData(valueString)) {
        std::cout << valueString;
    }
    std::cout << "' for the key '" << key << "'. Yay! :D" << std::endl;
}
