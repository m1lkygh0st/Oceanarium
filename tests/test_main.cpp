#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Fish.h"
#include "Worker.h"

#include <string>

TEST_CASE("Fish::feed - normal increase and boundary clamp") {
  Fish fish("TestFish", 3, "male", 50, 80);

  fish.feed(10);
  CHECK(fish.getAppetite() == 60);

  fish.feed(50);
  CHECK(fish.getAppetite() == 100);

  fish.feed(20);
  CHECK(fish.getAppetite() == 100);
}

TEST_CASE("Fish::tickDay - normal consumption without starvation") {
  Fish fish("TestFish", 2, "female", 10, 20);

  fish.tickDay();

  CHECK(fish.getAppetite() == 9);
  CHECK(fish.getHealth() == 20);
  CHECK(fish.isAlive() == true);
}

TEST_CASE("Fish::tickDay - starvation decreases health") {
  Fish fish("TestFish", 2, "female", 1, 10);

  fish.tickDay();

  CHECK(fish.getAppetite() == 0);
  CHECK(fish.getHealth() == 5);
  CHECK(fish.isAlive() == true);
}

TEST_CASE("Fish::tickDay - death when health reaches zero") {
  Fish fish("TestFish", 2, "female", 0, 4);

  fish.tickDay();

  CHECK(fish.getHealth() == 0);
  CHECK(fish.isAlive() == false);

  fish.tickDay();

  CHECK(fish.getHealth() == 0);
  CHECK(fish.getAppetite() == 0);
}

TEST_CASE("Worker break system - activation and countdown") {
  Worker worker("John", 30, "male");

  CHECK(worker.isActive() == true);

  worker.setBreak(3);

  CHECK(worker.isActive() == false);

  worker.tickDay();
  CHECK(worker.isActive() == false);

  worker.tickDay();
  CHECK(worker.isActive() == false);

  worker.tickDay();
  CHECK(worker.isActive() == true);
}

TEST_CASE("Worker break system - zero break edge case") {
  Worker worker("Alex", 25, "female");

  worker.setBreak(0);

  CHECK(worker.isActive() == true);

  worker.tickDay();

  CHECK(worker.isActive() == true);
}