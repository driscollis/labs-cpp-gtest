#ifndef GAME_HEADER
#define GAME_HEADER

#include <cstdlib>
#include <memory>
#include "webgadgetproxy.h"


namespace StarTrek {


class Game {
public:
    class RandomGenerator
    {
    public:
        virtual int Get( int maximum )
        {
            return rand() % maximum;
        }
    };

private:
    int e_;
    int t_;
    std::unique_ptr<RandomGenerator> gen;

    int randomWithinLimitOf(int maximum) {
        return gen->Get( maximum );
    }

public:
    Game( std::unique_ptr<RandomGenerator> generator =
            std::unique_ptr<RandomGenerator>( new RandomGenerator() ));
    void fireWeapon(WebGadgetProxy& wg);
};

}

#endif
