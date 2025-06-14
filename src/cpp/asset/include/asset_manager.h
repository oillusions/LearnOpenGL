#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <typeindex>

#include "base_asset_loader.h"

class AssetManager {
    public:
        template<typename T>
        static void registerLoader(const std::shared_ptr<AssetLoader<T>>& loader) {
            loaders.emplace(typeid(T), std::static_pointer_cast<BaseAssetLoader>(loader));
        }

        template<typename T>
        static void request(const std::filesystem::path& asset_path, const std::function<void(std::shared_ptr<T>)>& listener) {
            if (loaders.count(typeid(T))) {
                std::shared_ptr<AssetLoader<T>> loader = std::dynamic_pointer_cast<AssetLoader<T>>(loaders[typeid(T)]);
                loader->load(asset_path, listener);
                std::cout << "load: " << asset_path.filename() << std::endl;
            } else {
                std::cerr << "No Loader" << std::endl;
            }
        }
    private:
        static std::map<std::type_index, std::shared_ptr<BaseAssetLoader>> loaders;
};
