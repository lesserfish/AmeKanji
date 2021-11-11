#include "TemplateRenderer.h"
#include <iostream>

namespace Ame
{

    int MapTable::Delete(std::string var)
    {
        std::map<Identifier, Variable>::iterator it = Table.find(var);
        if (it != Table.end())
        {
            Table.erase(it);
            return 0;
        }
        return -1;
    }
    Variable MapTable::getValue(std::string var)
    {
        std::map<Identifier, Variable>::iterator it = Table.find(var);
        if (it != Table.end())
        {
            Variable v = it->second;
            return v;
        }
        return Variable();
    }
    int MapTable::getValue(Variable &v, std::string var)
    {
        std::map<Identifier, Variable>::iterator it = Table.find(var);
        if (it != Table.end())
        {
            Variable v = it->second;
            return 0;
        }
        return -1;
    }
    std::map<std::string, Variable> MapTable::getMap()
    {
        return Table;
    }
    int MapTable::Add(Identifier var, Variable val)
    {
        std::map<Identifier, Variable>::iterator it = Table.find(var);
        if (it != Table.end())
        {
            return -1;
        }
        Table[var] = val;
        return 0;
    }
    int MapTable::Add(Identifier var, std::string val)
    {
        Variable v(val);
        return Add(var, v);
    }
    int MapTable::Add(MapTable table)
    {
        std::map<std::string, Variable> tablemap = table.getMap();
        Table.insert(tablemap.begin(), tablemap.end());
        return 0;
    }

    int TemplateRenderer::Delete(std::string s)
    {
        std::map<Identifier, MapTable>::iterator it = MapTableArray.find(s);
        if (it != MapTableArray.end())
        {
            MapTableArray.erase(it);
            return 0;
        }
        return -1;
    }
    int TemplateRenderer::Add(Identifier id, MapTable table)
    {
        std::map<Identifier, MapTable>::iterator it = MapTableArray.find(id);
        if (it != MapTableArray.end())
            return -1;
        MapTableArray[id] = table;
        return 0;
    }
    int TemplateRenderer::Retrieve(MapTable &table, std::string tableName)
    {
        std::map<Identifier, MapTable>::iterator it = MapTableArray.find(tableName);
        if (it == MapTableArray.end())
            return -1;
        table = it->second;
        return 0;
    }

    std::string TemplateRenderer::Render(std::string Template, std::string tableName)
    {
        std::map<Identifier, MapTable>::iterator it = MapTableArray.find(tableName);
        if (it == MapTableArray.end())
            return "";
        return Render(Template, it->second);
    }
    std::string TemplateRenderer::Render(std::string Template, std::vector<std::string> tableNames)
    {
        std::vector<MapTable> mapTables;
        for (std::string &s : tableNames)
        {
            std::map<Identifier, MapTable>::iterator it = MapTableArray.find(s);
            if (it == MapTableArray.end())
                continue;
            mapTables.push_back(it->second);
        }
        return TemplateRenderer::Render(Template, mapTables);
    }
    std::string TemplateRenderer::RenderAll(std::string Template)
    {
        std::vector<MapTable> mapTables;
        for (std::pair<Identifier, MapTable> it : MapTableArray)
        {
            mapTables.push_back(it.second);
        }
        return TemplateRenderer::Render(Template, mapTables);
    }
    std::string TemplateRenderer::RenderAll(std::string Template, MapTable tableName)
    {
        std::vector<MapTable> mapTables;
        mapTables.push_back(tableName);
        for (std::pair<Identifier, MapTable> it : MapTableArray)
        {
            mapTables.push_back(it.second);
        }
        return TemplateRenderer::Render(Template, mapTables);
    }
    std::string TemplateRenderer::RenderAll(std::string Template, std::vector<MapTable> tableNames)
    {
        std::vector<MapTable> mapTables = tableNames;
        for (std::pair<Identifier, MapTable> it : MapTableArray)
        {
            mapTables.push_back(it.second);
        }
        return TemplateRenderer::Render(Template, mapTables);
    }

    //static
    std::string TemplateRenderer::Render(std::string Template, std::vector<MapTable> mapTables)
    {
        MapTable mergedTable;
        for (MapTable &table : mapTables)
        {
            mergedTable.Add(table);
        }
        return TemplateRenderer::Render(Template, mergedTable);
    }
    std::string TemplateRenderer::Render(std::string Template, MapTable mapTable)
    {
        std::string::iterator marker = Template.begin();

        while (marker != Template.end())
        {
            if (*marker == ')')
            {
                std::string::iterator checkpoint = std::next(marker);
                marker--;
                while (marker >= Template.begin())
                {
                    if (*marker == '$' && *std::next(marker) == '(')
                    {
                        std::string variable = std::string(marker, checkpoint);
                        std::string clean_variable = variable.substr(2, variable.size() - 3);
                        std::string var_evaluated = mapTable.getValue(clean_variable).ToString();

                        Template.replace(marker, checkpoint, var_evaluated.begin(), var_evaluated.end());
                        return Render(Template, mapTable);
                    }
                    marker--;
                }
                marker = std::prev(checkpoint);
            }
            marker++;
        }
        return Template;
    }
}