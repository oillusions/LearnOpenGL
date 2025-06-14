#pragma once
#include <iostream>
#include <fstream>
#include <memory>

#include "base_asset_loader.h"

class ShaderContentLoader : public AssetLoader<ShaderContent> {
public:
    void load(std::filesystem::path asset_path, std::function<void(std::shared_ptr<ShaderContent>)> listener) override {
        if (exists(asset_path)) {
            std::ifstream asset_file(asset_path);
            if (asset_file.is_open()) {
                std::stringstream buffer;
                buffer << asset_file.rdbuf();
                listener(std::make_shared<ShaderContent>(buffer.str()));
            } else {
                std::cerr << "could not open file: " << asset_path.string() << std::endl;
            }
        } else {
            std::cerr << "NO File: " << asset_path.string() << std::endl;
        }
    }
};