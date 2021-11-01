#pragma once
#include "configuration.hpp"
#include "plot_parser.hpp"
#include <nlohmann/json.hpp>

namespace cfg
{
    using nlohmann::json;

    inline void from_json(const json& j, configuration& c) {
        j.at("prefix").get_to(c.prefix);
        j.at("plots").get_to(c.plots);
    }
}
