#include "Serializer.hpp"

/**
 * reinterpret_cast: convert a pointer to an integer type and back
 */
uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}