#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "json11.hpp"


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
    static Variant parse_json(json11::Json& job);
};
std::string Variant::to_string() const{
    switch (type) {
        case VariantType::Symbol:
        case VariantType::Number:
            return val;
        case VariantType::List: {
            std::string result = "(";
            for (const auto& element : list) {
                result += element.to_string() + " ";
            }
            if (!list.empty()) {
                result.pop_back();
            }
            result += ")";
            return result;
        }
        case VariantType::Proc:
            return "Procedure";
        default:
            return "Unknown";
         }
    };

std::string Variant::to_json_string() const{
    json11::Json json;
    switch (type) {
        case VariantType::Symbol:
            json = val;
            break;
        case VariantType::Number:
            json = std::stod(val);
            break;
        case VariantType::List: {
            json11::Json::array json_array;
            for (const auto& element : list) {
                json_array.push_back(json11::Json(element.to_json_string()));
            }
            json = json_array;
            break;
        }
        case VariantType::Proc:
            json = "Procedure";
            break;
        default:
            json = nullptr;
    }
    return json.dump();
}

Variant Variant::from_json_string(const std::string sjson) {
    std::string err;
    json11::Json json = json11::Json::parse(sjson, err);
    if (!err.empty()) {
        throw std::runtime_error("Error parsing JSON: " + err);
    }
    return parse_json(json);

}

Variant Variant::parse_json(jsonlib::Json job) {
    return Variant();
}
int main() {
    Variant symbol_variant(VariantType::Symbol);
    symbol_variant.val = "hola";

    Variant number_variant(VariantType::Number);
    number_variant.val = "10";

    Variant list_variant(VariantType::List);
    list_variant.list = {symbol_variant, number_variant};

    std::cout << "to_string: " << list_variant.to_string() << std::endl;
    std::cout << "to_json_string: " << list_variant.to_json_string() << std::endl;

    std::string json_str = list_variant.to_json_string();
    Variant parsed_variant = Variant::from_json_string(json_str);

    std::cout << "Parsed Variant to_string: " << parsed_variant.to_string() << std::endl;

    return 0;
}



