#pragma once

#include <memory>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "../StatusCodes.h"

namespace Ame
{
    template<typename K>
    class ChainLink
    {
        public:
            template<typename F, typename... A>
            inline static std::shared_ptr<ChainLink> Setup(F && _Func, A&&... Args)
            {
                auto f = std::bind(std::forward<F>(_Func), std::placeholders::_1, std::placeholders::_2, std::forward<A>(Args)...);
                std::shared_ptr<ChainLink> l(new ChainLink(f));
                return l;
            }

            inline ame_result Call(K& input_A, std::vector<std::string> input_B)
            {
                return Func(input_A, input_B);
            }
        public:
            
            using FuncType = std::function<ame_result(K&, std::vector<std::string>)>;
            ChainLink(FuncType&& _F) : Func(std::forward<FuncType>(_F)){}
            FuncType Func;
    };

    template<typename K>
    class EventChain
    {
        public:
            EventChain() : StopOnFail(false){}
            inline void RegisterChain(std::shared_ptr<ChainLink<K>>& Chain){
                ChainRegistry.push_back(Chain);
            }
            inline void EmptyRegistry(){
                ChainRegistry.clear();
            }
            ame_result Call(K& Card, std::vector<std::string> Input, std::vector<std::string> ChainArgs = {})
            {
                this->ParseArgs(ChainArgs);
                for(auto& c : ChainRegistry)
                {
                    ame_result r = c->Call(Card, Input);
                    if(!r.OK && StopOnFail)
                        return r;
                }
                return ame_result(true, statusCode::OK, "All chain calls were succesfull.");
            }
        private:
            void ParseArgs(std::vector<std::string> Args)
            {
                for(auto& arg : Args)
                {
                    std::transform(arg.begin(), arg.end(), arg.begin(), ::tolower);
                    if(arg == "setstoponfail" || arg == "-setstoponfail" || arg == "stoponfail")
                        StopOnFail = true;
                }
            }
            std::vector<std::shared_ptr<ChainLink<K>>> ChainRegistry;

            bool StopOnFail;
    };

}
