#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "json11.hpp"
#include "jsonlib.hpp"

// Enumeración para los tipos de datos admitidos
enum VariantType{Symbol, Number, List, Proc, Lambda, Cadena};

// Estructura para representar un entorno
struct Entorno;

class Variant {
public:
    using proc_type = Variant(*)(const std::vector<Variant>&);
    using iter = std::vector<Variant>::const_iterator;
    using map = std::map<std::string, Variant>;

    VariantType type;
    std::string val;
    std::vector<Variant> list;
    proc_type proc;
    Entorno* env;

    Variant(VariantType type = VariantType::Symbol) : type(type), env(nullptr), proc(nullptr) {}
    Variant(VariantType type, const std::string& val) : type(type), val(val), env(nullptr), proc(nullptr) {}
    Variant(proc_type proc) : type(VariantType::Proc), proc(proc), env(nullptr) {}

    std::string to_string() const;
    std::string to_json_string() const;
    static Variant from_json_string(const std::string& json);
    static Variant parse_json(jsonlib::Json job);
};
std::string Variant::to_string() {
    // Tu implementación aquí
}

std::string Variant::to_json_string() {
    // Tu implementación aquí
}

Variant Variant::from_json_string(std::string sjson) {
    // Tu implementación aquí
}

Variant Variant::parse_json(jsonlib::Json job) {
    // Tu implementación aquí
}




