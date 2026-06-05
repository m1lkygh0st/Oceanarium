#include <iostream>
#include <memory>
#include <vector>

#include "Aquarium.h"
#include "Fish.h"
#include "Oceanarium.h"
#include "Worker.h"

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
            std::cout << "4. Add Worker\n";
            std::cout << "5. Feed Fish\n";
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
                    std::cout << "No aquariums available. Add aquarium first.\n";
                    continue;
                }

                std::cout << "\nAvailable aquariums:\n";
                for (int i = 0; i < oceanarium.getAquariumCount(); ++i) {
                    const Aquarium &aq = oceanarium.getAquarium(i);
                    std::cout << aq.getNumber() << ". Aquarium (" << aq.getFishCount() << " fish)\n";
                }

                const int aquariumNumber = Input::readIntRange("Select aquarium: ", 1, oceanarium.getAquariumCount());
                Aquarium &aquarium = oceanarium.getAquarium(aquariumNumber - 1);

                std::vector<std::string> fishTypes = {"Salmon", "Shark", "Angelfish", "Butterflyfish", "Cardinalfish"};

                std::cout << "\nSelect fish type:\n";
                for (size_t i = 0; i < fishTypes.size(); ++i) {
                    std::cout << (i + 1) << ". " << fishTypes[i] << "\n";
                }

                const int type = Input::readIntRange("Choice: ", 1, static_cast<int>(fishTypes.size()));

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

                std::cout << count << " " << fishTypes[type - 1] << "(s) added successfully.\n";
            }

            else if (choice == 3) {
                if (oceanarium.getAquariumCount() == 0) {
                    std::cout << "No aquariums.\n";
                    continue;
                }

                for (int i = 0; i < oceanarium.getAquariumCount(); ++i) {
                    oceanarium.getAquarium(i).printInfo();
                }
            }

            else if (choice == 4) {
                if (oceanarium.getAquariumCount() == 0) {
                    std::cout << "No aquariums available.\n";
                    continue;
                }

                std::cout << "\nAvailable aquariums:\n";
                for (int i = 0; i < oceanarium.getAquariumCount(); ++i) {
                    const Aquarium &aq = oceanarium.getAquarium(i);
                    std::cout << aq.getNumber() << ". Aquarium (" << aq.getFishCount() << " fish, "
                              << aq.getWorkerCount() << " workers)\n";
                }

                const int aquariumNumber = Input::readIntRange("Select aquarium: ", 1, oceanarium.getAquariumCount());
                Aquarium &aquarium = oceanarium.getAquarium(aquariumNumber - 1);

                const std::string name = Input::readString("Worker name: ");
                const int age = Input::readIntRange("Age: ", 18, 80);
                const std::string gender = Input::readGender("Gender: ");

                aquarium.addWorker(Worker(name, age, gender));
                std::cout << "Worker added.\n";
            }

            else if (choice == 5) {
                if (oceanarium.getAquariumCount() == 0) {
                    std::cout << "No aquariums available.\n";
                    continue;
                }

                std::cout << "\nAquariums with workers:\n";
                std::vector<int> validAquariums;
                for (int i = 0; i < oceanarium.getAquariumCount(); ++i) {
                    if (const Aquarium &aq = oceanarium.getAquarium(i); aq.getWorkerCount() > 0) {
                        std::cout << aq.getNumber() << ". Aquarium with " << aq.getWorkerCount() << " workers\n";
                        validAquariums.push_back(i);
                    }
                }

                if (validAquariums.empty()) {
                    std::cout << "No workers available in any aquarium. Add workers first.\n";
                    continue;
                }

                const int aquariumChoice =
                        Input::readIntRange("Select aquarium to feed: ", 1, oceanarium.getAquariumCount());
                Aquarium &aquarium = oceanarium.getAquarium(aquariumChoice - 1);

                if (aquarium.getWorkerCount() == 0) {
                    std::cout << "This aquarium has no workers.\n";
                    continue;
                }

                std::cout << "\nWorkers in aquarium:\n";
                for (int i = 0; i < aquarium.getWorkerCount(); ++i) {
                    std::cout << i + 1 << ". ";
                    aquarium.getWorker(i).printInfo();
                }

                const int workerChoice =
                        Input::readIntRange("Select worker to feed fish: ", 1, aquarium.getWorkerCount());
                Worker &worker = aquarium.getWorker(workerChoice - 1);

                aquarium.feedFishByWorker(worker);

                std::cout << "Fish in aquarium " << aquarium.getNumber() << " have been fed by " << worker.getName()
                          << ".\n";
            }

            else {
                std::cout << "Invalid choice.\n";
            }
        }

        catch (const std::exception &e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}
