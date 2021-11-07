#pragma once
#include "configuration.hpp"
#include "plot_parser.hpp"
#include <nlohmann/json.hpp>

namespace nlohmann
{
    template <>
    struct adl_serializer<range> {
        static void from_json(const json& j, range& r) {
            j.at("begin").get_to(r.begin);
            j.at("end").get_to(r.end);
            j.at("step").get_to(r.step);
        }
    };

    template <>
    struct adl_serializer<invariants> {
        static void from_json(const json& j, invariants& i) {
            j.at("repeats").get_to(i.repeats);
            j.at("range").get_to(i.range);
        }
    };
}

namespace cfg
{
    using nlohmann::json;

    inline void from_json(const json& j, configuration& c) {
        j.at("prefix").get_to(c.prefix);
        j.at("plots").get_to(c.plots);
        j.at("invariants").get_to(c.invariants);
    }
}
