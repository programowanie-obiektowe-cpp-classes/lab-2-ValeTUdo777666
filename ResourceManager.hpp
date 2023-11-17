

#include "Resource.hpp"

class ResourceManager
{
public:
    ResourceManager() : resource(std::make_unique<Resource>()) {}

    // Konstruktor kopiuj¹cy
    ResourceManager(const ResourceManager& other) : resource(std::make_unique<Resource>(*other.resource)) {}

    // Operator przypisania kopiuj¹cego
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            resource = std::make_unique<Resource>(*other.resource);
        }
        return *this;
    }

    // Konstruktor przenosz¹cy
    ResourceManager(ResourceManager&& other) noexcept : resource(std::move(other.resource)) {}

    // Operator przypisania przenosz¹cego
    ResourceManager& operator=(ResourceManager&& other) noexcept
    {
        if (this != &other) {
            resource = std::move(other.resource);
        }
        return *this;
    }

    // Destruktor
    ~ResourceManager() = default;

    double get() { return resource->get(); }

    // Pozosta³e metody specjalne
    // Mo¿esz dostosowaæ te metody do swoich potrzeb

private:
    std::unique_ptr<Resource> resource;
};