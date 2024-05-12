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

void generator(const v8::FunctionCallbackInfo<v8::Value>& args) {
	v8::Isolate* isolate = args.GetIsolate();

	if (args.Length() < 2)
		isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8Literal(isolate, "Missing length or charset.")));

	if (!args[0]->IsUint32())
		isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8Literal(isolate, "arg[0] is not of type int")));

	if (!args[1]->IsString())
		isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8Literal(isolate, "arg[1] is not of type string")));

	size_t size = args[0]->IntegerValue(isolate->GetCurrentContext()).ToChecked();
	if (size < 4) isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8Literal(isolate, "arg[0] must be higher than 3.")));

	v8::String::Utf8Value str(isolate, args[1]);

	args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, nativeGenerator(size, str.operator*(), str.length())).ToLocalChecked());
}

