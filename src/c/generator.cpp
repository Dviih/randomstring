#include <random>

#include <node/node.h>
#include <node/v8.h>

#define NAPI_VERSION 3
#define NODE_MODULE_VERSION 127

char* nativeGenerator(size_t size, char* charset, size_t len) {
	std::random_device randomDevice;
	std::mt19937_64 gen(randomDevice());

	std::uniform_int_distribution<> random(0, len-1);

	char* data = (char*)malloc(size);

	for (size_t i = 0; i < size; i++)
		data[i] = charset[random(gen)];

	return data;
}

