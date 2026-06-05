#include <iostream>
#include <memory>
#include "Aquarium.h"
#include "Fish.h"
#include "Oceanarium.h"

#include "Angelfish.h"
#include "Butterflyfish.h"
#include "Cardinalfish.h"
#include "Salmon.h"
#include "Shark.h"

#include "Input.h"

int main() {
    Oceanarium oceanarium;

    while (true) {
        try {
            std::cout << "\n===== Oceanarium Menu =====\n";
            std::cout << "1. Add Aquarium\n";
            std::cout << "2. Add Fish\n";
            std::cout << "3. Show Aquariums\n";
            std::cout << "0. Exit\n";

            const int choice = Input::readInt("Choose: ");

            if (choice == 0) {
                std::cout << "Exiting...\n";
                break;
            }

            if (choice == 1) {
                int number = oceanarium.getAquariumCount() + 1;
                oceanarium.addAquarium(std::make_unique<Aquarium>(number));
                std::cout << "Aquarium " << number << " added.\n";
            }

            else if (choice == 2) {
                if (oceanarium.getAquariumCount() == 0) {
                    std::cout << "No aquariums available. Please add an aquarium first.\n";
                    continue;
                }

                std::cout << "\nAvailable aquariums:\n";

                for (int i = 0; i < oceanarium.getAquariumCount(); ++i) {
                    const Aquarium &aq = oceanarium.getAquarium(i);
                    std::cout << aq.getNumber() << ". Aquarium - " << aq.getFishCount() << " fish\n";
                }

                const int aquariumNumber =
                        Input::readIntRange("Select aquarium number: ", 1, oceanarium.getAquariumCount());

                Aquarium &aquarium = oceanarium.getAquarium(aquariumNumber - 1);

                std::cout << "\nSelect fish type:\n";
                std::cout << "1. Salmon\n";
                std::cout << "2. Shark\n";
                std::cout << "3. Angelfish\n";
                std::cout << "4. Butterflyfish\n";
                std::cout << "5. Cardinalfish\n";

                const int type = Input::readIntRange("Choice: ", 1, 5);

                int age = Input::readIntRange("Age: ", 0, 200);
                std::string gender = Input::readGender("Gender (male/female): ");
                int appetite = Input::readIntRange("Appetite (0-100): ", 0, 100);
                int health = Input::readIntRange("Health (0-100): ", 0, 100);
                const int count = Input::readIntRange("Number of fish: ", 1, 1000);

                for (int i = 0; i < count; ++i) {
                    std::unique_ptr<Fish> fish;

                    if (type == 1) {
                        fish = std::make_unique<Salmon>(age, gender, appetite, health);
                    }

                    else if (type == 2) {
                        fish = std::make_unique<Shark>(age, gender, appetite, health);
                    }

                    else if (type == 3) {
                        fish = std::make_unique<Angelfish>(age, gender, appetite, health);
                    }

                    else if (type == 4) {
                        fish = std::make_unique<Butterflyfish>(age, gender, appetite, health);
                    }

                    else {
                        fish = std::make_unique<Cardinalfish>(age, gender, appetite, health);
                    }

                    aquarium.addFish(std::move(fish));
                }

                std::cout << "Fish added successfully.\n";
            }

            else if (choice == 3) {
                if (oceanarium.getAquariumCount() == 0) {
                    std::cout << "No aquariums available.\n";
                    continue;
                }

                for (int i = 0; i < oceanarium.getAquariumCount(); ++i) {
                    oceanarium.getAquarium(i).printInfo();
                }
            }

        }

        catch (const std::exception &e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}
