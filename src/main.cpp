#include "Fish.h"
#include "Input.h"
#include "Oceanarium.h"

#include <exception>
#include <iostream>

int main() {
    Oceanarium oceanarium;

    while (true) {
        try {
            std::cout << "\n===== OCEANARIUM =====\n";
            std::cout << "1. Add aquarium\n";
            std::cout << "2. Add fish\n";
            std::cout << "3. Status of aquariums\n";
            std::cout << "0. Exit\n";

            const int choice = Input::readInt("Choose: ");

            if (choice == 0) {
                break;
            }

            if (choice == 1) {
                Aquarium aquarium;
                oceanarium.addAquarium(aquarium);

                std::cout << "Aquarium added\n";
            }

            else if (choice == 2) {
                if (oceanarium.getAquariumCount() == 0) {
                    throw std::runtime_error("No aquariums available");
                }

                const auto &aquariums = oceanarium.getAquariums();
                std::cout << "\nAvailable aquariums:\n";
                for (size_t i = 0; i < aquariums.size(); i++) {
                    std::cout << (i + 1) << ". Aquarium - " << aquariums[i].getFishCount() << " fish\n";
                }

                const int aquariumNumber = Input::readInt("Select aquarium number: ");
                const int index = aquariumNumber - 1;

                if (index < 0 || index >= oceanarium.getAquariumCount()) {
                    throw std::runtime_error("Invalid aquarium number");
                }

                const std::string species = Input::readLettersOnly("Species: ");
                const int age = Input::readIntRange("Age: ", 0, 200);
                const std::string gender = Input::readGender("Gender (male/female): ");
                const int appetite = Input::readIntRange("Appetite (0-100): ", 0, 100);
                const int health = Input::readIntRange("Health (0-100): ", 0, 100);
                const int count = Input::readIntRange("Number of fish to add: ", 1, 1000);

                for (int i = 0; i < count; ++i) {
                    Fish fish(species, age, gender, appetite, health);
                    oceanarium.getAquarium(index).addFish(fish);
                }
                std::cout << count << " fish added successfully to aquarium " << aquariumNumber << "\n";
            }


            else if (choice == 3) {
                const auto &aquariums = oceanarium.getAquariums();

                if (aquariums.empty()) {
                    std::cout << "No aquariums\n";
                    continue;
                }

                std::cout << "\n===== AQUARIUMS =====\n";

                for (size_t i = 0; i < aquariums.size(); i++) {
                    const auto &fishes = aquariums[i].getFishes();
                    std::cout << "\nAquarium " << (i + 1) << ":\n";

                    if (fishes.empty()) {
                        std::cout << "  No fish\n";
                        continue;
                    }

                    for (const auto &f: fishes) {
                        std::cout << "  Species: " << f.getSpecies() << " | Age: " << f.getAge()
                                  << " | Gender: " << f.getGender() << " | Appetite: " << f.getAppetite()
                                  << " | Health: " << f.getHealth() << "\n";
                    }
                }
            }

            else {
                throw std::runtime_error("Unknown option");
            }
        }

        catch (const std::exception &e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}
