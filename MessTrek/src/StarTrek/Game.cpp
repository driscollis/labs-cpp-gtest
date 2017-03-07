#include <sstream>
#include <time.h>

#include "Game.h"
#include "Klingon.h"

StarTrek::Game::Game( std::unique_ptr<RandomGenerator> generator )
    : e_(10000), t_(8), gen( std::move( generator ) ) {
    srand(time(NULL));
}

void StarTrek::Game::fireWeapon(WebGadgetProxy& wg) {
    if (wg.parameter("command") == "phaser") {
        int amount = atoi(wg.parameter("amount").c_str());
        Klingon* enemy = (Klingon*)wg.variable("target");
        if (e_ >= amount) {
            int distance = enemy->distance();
            if (distance > 4000) {
                stringstream message;
                message << "Klingon out of range of phasers at " << distance << " sectors...";
                wg.writeLine(message.str());
            } else {
                int damage = amount - (((amount /20)* distance /200) + randomWithinLimitOf(200));
                if (damage < 1)
                    damage = 1;
                stringstream message;
                message << "Phasers hit Klingon at " << distance << " sectors with " << damage << " units";
                wg.writeLine(message.str());
                if (damage < enemy->energy()) {
                    enemy->energy(enemy->energy() - damage);
                    stringstream message;
                    message << "Klingon has " << enemy->energy() << " remaining";
                    wg.writeLine(message.str());
                } else {
                    wg.writeLine("Klingon destroyed!");
                    enemy->destroy();
                }
            }
            e_ -= amount;

        } else {
            wg.writeLine("Insufficient energy to fire phasers!");
        }

    } else if (wg.parameter("command") == "photon") {
        Klingon* enemy = (Klingon*)wg.variable("target");
        if (t_ > 0) {
            int distance = enemy->distance();
            if ((randomWithinLimitOf(4) + ((distance / 500) + 1) > 7)) {
                stringstream message;
                message << "Torpedo missed Klingon at " << distance << " sectors...";
                wg.writeLine(message.str());
            } else {
                int damage = 800 + randomWithinLimitOf(50);
                stringstream message;
                message << "Photons hit Klingon at " << distance << " sectors with " << damage << " units";
                wg.writeLine(message.str());

                if (damage < enemy->energy()) {
                    enemy->energy(enemy->energy() - damage);
                    stringstream message;
                    message << "Klingon has " << enemy->energy() << " remaining";
                    wg.writeLine(message.str());
                } else {
                    wg.writeLine("Klingon destroyed!");
                    enemy->destroy();
                }
            }
            t_--;

        } else {
            wg.writeLine("No more photon torpedoes!");
        }
    }
}
