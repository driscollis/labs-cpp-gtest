#include "Phaser.h"

#include <algorithm>

#include "RandGenerator.h"

namespace StarTrek
{
Phaser::Phaser()
{
}

Phaser::~Phaser()
{
}

bool Phaser::arePhasersInRange( int distance )
{
    return distance <= 4000;
}

int Phaser::getPhaserDamage( int amount, int distance )
{
    return std::max( 1, amount - (((amount /20)* distance /200) + rnd(200)) );
}

} // namespace StarTrek
