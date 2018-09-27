//
//  Array_improved.cpp
//  Test
//
//  Created by Jhoirenial on 10/22/17.
//  Copyright © 2017 Jhoirenial. All rights reserved.
//
#include <iostream>
#include <ctime>
#include <vector>
#include <random>
#include <algorithm>

int main(){

  const int size = 10;

  std::vector<int> numbers(size);

  std::random_device random_devices;
  std::mt19937 random_machine(random_devices());
  std::uniform_int_distribution<int> distribution(-size, size);

  std::cout << "========================================" << std::endl;

  std::generate(numbers.begin(), numbers.end(), [&] { return distribution(random_machine); } );

  for (auto number: numbers) std::cout << number << " ";
  std::cout << std::endl << "========================================" << std::endl;

  std::sort(numbers.begin(), numbers.end(), [&] (int i, int j) {return i < j; } );

  for (auto number: numbers) std::cout << number << " ";
  std::cout << std::endl << "========================================" << std::endl;

    int CompNeg = *(numbers.begin()) * *(numbers.begin() + 1);
    int CompPos = *(numbers.end() - 1)  * *(numbers.end() - 2);

      std::cout << "Max composition is " << (CompNeg > CompPos ? CompNeg : CompPos);

    std::cout << std::endl << "========================================" << std::endl;

    return 0;
}
