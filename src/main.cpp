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
                if (oceanarium.getAquariumCount() == 0)
                    throw std::runtime_error("No aquariums available");

                const auto &aquariums = oceanarium.getAquariums();
                std::cout << "\nAvailable aquariums:\n";
                for (size_t i = 0; i < aquariums.size(); i++) {
                    std::cout << (i + 1) << ". Aquarium - " << aquariums[i].getFishCount() << " fish\n";
                }

                const int aquariumNumber = Input::readInt("\nSelect aquarium number: ");
                const int index = aquariumNumber - 1;

                if (index < 0 || index >= oceanarium.getAquariumCount())
                    throw std::runtime_error("Invalid aquarium number");

                const int count = Input::readInt("Fish count to add: ");
                oceanarium.getAquarium(index).addFish(count);
                std::cout << "Fish added\n";
            }

            else if (choice == 3) {
                const auto &aquariums = oceanarium.getAquariums();

                if (aquariums.empty()) {
                    std::cout << "No aquariums\n";
                    continue;
                }

                for (size_t i = 0; i < aquariums.size(); i++) {
                    std::cout << "Aquarium " << (i + 1) << " - " << aquariums[i].getFishCount() << " fish\n";
                }
            }

            else {
                throw std::runtime_error("Input 0 - 3");
            }
        }

        catch (const std::exception &e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}
