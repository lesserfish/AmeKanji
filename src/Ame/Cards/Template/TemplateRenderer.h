#pragma once

#include <string>
#include <vector>
#include <map>

namespace Ame
{
    typedef std::string Identifier;
    struct Variable
    {
        Variable(std::string v = "") : Value(v) {} 
        std::string ToString(){return Value;}
        std::string Value;   
    };

    class MapTable
    {
        public:
            MapTable() : Table(){}
            MapTable(Identifier id, Variable var) : Table(){Table[id] = var;}
            Variable getValue(Identifier var);
            int getValue(Variable& v, Identifier var);
            int Delete(std::string var);
            int Add(Identifier var, Variable val);
            int Add(Identifier Var, std::string Val);
            int Add(MapTable Table);
            std::map<std::string, Variable> getMap();
        private:
            std::map<std::string, Variable> Table;
    };
    class TemplateRenderer
    {
        public:
            TemplateRenderer() : MapTableArray(){}
            TemplateRenderer(Identifier s, MapTable table) : MapTableArray() {MapTableArray[s] = table;}
            int Delete(Identifier tableName);
            int Add(Identifier id, MapTable table);
            int Retrieve(MapTable& table, std::string tableName);

            std::string Render(std::string Template, std::string tableName);
            std::string Render(std::string Template, std::vector<std::string> tableNames);
            std::string RenderAll(std::string Template);
            std::string RenderAll(std::string Template, MapTable tableName);
            std::string RenderAll(std::string Template, std::vector<MapTable> tableNames);
            static std::string Render(std::string Template, std::vector<MapTable> tableNames);
            static std::string Render(std::string Template, MapTable mapTable);
        private:
            std::map<Identifier, MapTable> MapTableArray;
    };
}