#include <iostream>
#include <random>
#include <string>
#include <thread>
#include <chrono>
#include <vector>

const char* hex_characters[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"};

void wait() {
	std::this_thread::sleep_for(std::chrono::milliseconds(std::rand() % 500));
}

void AI_training() {
	std::cout << "\nStarting AI Training\nSetting hyperparameters\nPreparing matrices for training\nStarting Iterations\n";

	for (int i = 0; i < (std::rand() % 30) + 10; i++) {
		std::cout << "[Epoch " << i << "] loss: " << float(std::rand() % 1000) / 1000 << "\n";
		wait();
	}
}

void hexdump() {
	std::cout << "\nGenerating hexdump from network penetration\n";
	for (int i = 10; i < (std::rand() % 20) + 20; i++) {
		std::cout << "0x0000" << i << ": ";
		for (int j = 0; j < 32; j++){
			std::cout << hex_characters[std::rand() % 16];
		}
		std::cout << "\n";
		wait();
	}
}

int main() {
	std::vector<void (*)()> banana;
	banana.push_back(AI_training);
	banana.push_back(hexdump);
	while (true) {
		std::cout << "\033[1;32m";
		banana[std::rand() % banana.size()]();
		std::cout << "\033[1;0m";
		wait();
	}
	return 0;
}
