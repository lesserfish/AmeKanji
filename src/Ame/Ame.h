#pragma once

#include "AmeConfig.h"
#include "StatusCodes.h"
#include "Jisho/EventChain.h"
#include "Jisho/Librarian.h"
#include <string>
#include <functional>
#include <pugixml.hpp>

namespace Ame
{
    class Ame
    {
    public:
        Ame(int argc, char **argv);
        Ame();

        ame_result load_stdout_callback(std::function<void(std::string)> Func);
        ame_result load_progress_callback(std::function<void(int, int, std::string)> Func);
        void AmePrint(std::string content);

        ame_result loadArgs(int argc, char **argv);
        ame_result loadConfigurationFromString(std::string config = "");
        ame_result loadConfigurationFromFile(std::string file = "");
        ame_result loadConfigurationFromXML(std::string &XMLContent, std::string rootNode = "ame");
        ame_result loadConfigurationFromXML(pugi::xml_document &XMLDoc, std::string rootNode = "ame");

        ame_result loadTemplateFromFile(std::string file = "");
        ame_result loadTemplateFromString(std::string cTemplate);
        ame_result loadTemplateFromXML(pugi::xml_document &XMLDoc);
        ame_result loadTemplateFromXML(std::string &XMLContent) { return ame_result(); }

        ame_result loadWordlistFromFile(std::string file = "");
        ame_result loadWordlistFromString(std::string cWordlist);
        ame_result loadWordlistFromXML(pugi::xml_document &XMLDoc);
        ame_result loadWordlistFromXML(std::string &XMLContent) { return ame_result(); }

        template <typename K>
        ame_result setEventChain(EventChain<K> ec) { return ame_result(); }
        ame_result clearEventChain() { return ame_result(); }
        template <typename K>
        ame_result AddChainLink(std::vector<ChainLink<K>> Link) { return ame_result(); }
        template <typename T, Parser parser, typename... A>
        ame_result AddChainLink(A... Args) { return ame_result(); }
        template <typename... A>
        ame_result AddChainLinkFromLibrary(Parser parser, A... Args) { return ame_result(); }

        ame_result preRunChecklist();
        ame_result Go();

        ame_result SaveDeck(std::string file = "");
        std::string getDeck();

        void Clear();

    private:
        AmeConfig configInstance;
        std::function<void(std::string)> stdout_callback;
        std::function<void(int, int, std::string)> progress_callback;
    };
}