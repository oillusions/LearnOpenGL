#pragma once
#include <filesystem>
#include <functional>
#include <memory>

#include "base_loader.h"

template<typename T>
class AssetLoader : public BaseAssetLoader {
    public:
        void virtual load(std::filesystem::path, std::function<void(std::shared_ptr<T>)>) = 0;
};
