

#include "Resource.hpp"

class ResourceManager
{
public:
    ResourceManager() : resource(std::make_unique<Resource>()) {}

    // Konstruktor kopiujący
    ResourceManager(const ResourceManager& other) : resource(std::make_unique<Resource>(*other.resource)) {}

    // Operator przypisania kopiującego
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            resource = std::make_unique<Resource>(*other.resource);
        }
        return *this;
    }

    // Konstruktor przenoszący
    ResourceManager(ResourceManager&& other) noexcept : resource(std::move(other.resource)) {}

    // Operator przypisania przenoszącego
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

    // Pozostałe metody specjalne
    // Możesz dostosować te metody do swoich potrzeb

private:
    std::unique_ptr<Resource> resource;
};