#ifndef GAME_HEADER
#define GAME_HEADER


#include <Untouchables/WebGadget.h>

#include "Phaser.h"
#include "PhotonTorpedo.h"
#include "RandGenerator.h"

namespace StarTrek {

class Galaxy;
class Klingon;

class Game {
private:
    int phaser_ammo;
    int photon_torpedos;

    Phaser m_phaser;
    PhotonTorpedo m_photon_torp;

    void hitKlingon( Klingon* enemy, int damage, Galaxy& galaxy );

    bool hasEnoughPhaserAmmo( int amount );
    bool hasEnoughPhotoTorpedos();
    void reducePhaserAmmo( int amount );
    void reducePhotoTorpedos();
    void photonTorpedoMissed( int distance, Galaxy& galaxy );

    void attackWithPhaser( Klingon* enemy, int amount, int distance, Galaxy& galaxy );
    void attackPhotonTorpedo( Klingon* enemy, int distance, Galaxy& galaxy );

public:
    Game();
    void fireWeapon(Untouchables::WebGadget* wg);
    void fireWeapon(Galaxy& galaxy);
    int energyRemaining(void);
    void torpedoes(int value);
    int torpedoes(void);
};

}

#endif
