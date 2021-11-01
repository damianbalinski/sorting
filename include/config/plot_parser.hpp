#pragma once
#include "plot.hpp"
#include "sorting_mapper.hpp"
#include "executor_mapper.hpp"
#include <nlohmann/json.hpp>

namespace nlohmann {

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

    template <>
    struct adl_serializer<const sorting*> {
        static void from_json(const json& j, const sorting*& s) {
            s = sorting_mapper::map(j.at("algorithm").get<std::string>());
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
        j.at("invariants").get_to(p.invariants);
        j.at("sortings").get_to(p.sortings);
    }
}
