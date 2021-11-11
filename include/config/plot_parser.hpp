#pragma once
#include "plot.hpp"
#include "sorting_mapper.hpp"
#include "generator_mapper.hpp"
#include "executor_mapper.hpp"
#include <nlohmann/json.hpp>

namespace nlohmann {

    template <>
    struct adl_serializer<const sorting*> {
        static void from_json(const json& j, const sorting*& s) {
            s = sorting_mapper::map(j.get<std::string>());
        }
    };

    template <>
    struct adl_serializer<const generator*> {
        static void from_json(const json& j, const generator*& g) {
            g = generator_mapper::map(j.get<std::string>());
        }
    };

    template <>
    struct adl_serializer<unit_test> {
        static void from_json(const json& j, unit_test& u) {
            j.at("generator").get_to(u.generator);
            j.at("algorithm").get_to(u.sorting);
        }
    };

    template <>
    struct adl_serializer<const executor*> {
        static void from_json(const json& j, const executor*& e) {
            e = executor_mapper::map(j.get<std::string>());
        }
    };

}

namespace cfg
{
    using nlohmann::json;

    inline void from_json(const json& j, plot& p) {
        j.at("type").get_to(p.executor);
        j.at("sortings").get_to(p.tests);
    }
}
