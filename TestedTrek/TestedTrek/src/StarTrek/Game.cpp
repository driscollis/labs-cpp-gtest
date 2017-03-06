#include "stdafx.h"

#include <sstream>

#include "Game.h"
#include "Klingon.h"
#include "Galaxy.h"

namespace StarTrek {

Game::Game() : phaser_ammo(10000), photon_torpedos(8) {
    generator = &rand;
}

void Game::fireWeapon(Galaxy& galaxy) {
    Klingon* enemy = (Klingon*)galaxy.variable("target");
    int distance = -1;
    if ( enemy )
    {
        distance = enemy->distance();
    }

    if (galaxy.parameter("command") == "phaser") {
        int amount = atoi(galaxy.parameter("amount").c_str());
        attackWithPhaser( enemy, amount, distance, galaxy );

    } else if (galaxy.parameter("command") == "photon") {
        attackPhotonTorpedo( enemy, distance, galaxy );
    }
}

void Game::fireWeapon(Untouchables::WebGadget* webGadget) {
    Galaxy galaxy(webGadget);
    fireWeapon(galaxy);
}

int Game::energyRemaining(void) {
    return phaser_ammo;
}

int Game::torpedoes(void) {
    return photon_torpedos;
}

void Game::torpedoes(int value) {
    photon_torpedos = value;
}

void Game::hitKlingon( Klingon* enemy, int damage, Galaxy& galaxy )
{
    enemy->hit( damage );

    if ( enemy->isDead() )
    {
        galaxy.writeLine("Klingon destroyed!");
        enemy->destroy();
    }
    else
    {
        stringstream message;
        message << "Klingon has " << enemy->energy() << " remaining";
        galaxy.writeLine(message.str());
    }
}

bool Game::hasEnoughPhaserAmmo( int amount )
{
    return phaser_ammo >= amount;
}

bool Game::hasEnoughPhotoTorpedos()
{
    return photon_torpedos > 0;
}

void Game::reducePhaserAmmo( int amount )
{
    phaser_ammo -= amount;
}

void Game::reducePhotoTorpedos()
{
    --photon_torpedos;
}

void Game::attackWithPhaser( Klingon* enemy, int amount, int distance,
    Galaxy& galaxy )
{
    if ( hasEnoughPhaserAmmo( amount ) ) {
        if ( !m_phaser.arePhasersInRange(distance) ) {
            stringstream message;
            message << "Klingon out of range of phasers at " << distance << " sectors...";
            galaxy.writeLine(message.str());
        } else {
            int damage = m_phaser.getPhaserDamage( amount, distance );
            stringstream message;
            message << "Phasers hit Klingon at " << distance << " sectors with " << damage << " units";
            galaxy.writeLine(message.str());
            hitKlingon( enemy, damage, galaxy );
        }
        reducePhaserAmmo( amount );

    } else {
        galaxy.writeLine("Insufficient energy to fire phasers!");
    }
}

void Game::attackPhotonTorpedo( Klingon* enemy, int distance, Galaxy& galaxy )
{
    if ( hasEnoughPhotoTorpedos() ) {
        if ( !m_photon_torp.didTorpedoHit( distance ) ) {
            photonTorpedoMissed( distance, galaxy );
        } else {
            int damage = m_photon_torp.getPhotonTorpDamage();
            stringstream message;
            message << "Photons hit Klingon at " << distance << " sectors with " << damage << " units";
            galaxy.writeLine(message.str());

            hitKlingon( enemy, damage, galaxy );
        }
        reducePhotoTorpedos();

    } else {
        galaxy.writeLine("No more photon torpedoes!");
    }
}

void Game::photonTorpedoMissed( int distance, Galaxy& galaxy )
{
    stringstream message;
    message << "Torpedo missed Klingon at " << distance << " sectors...";
    galaxy.writeLine(message.str());
}

}
