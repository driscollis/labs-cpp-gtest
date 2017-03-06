#include "PhotonTorpedo.h"

#include "RandGenerator.h"

namespace StarTrek
{

PhotonTorpedo::PhotonTorpedo()
{
}

PhotonTorpedo::~PhotonTorpedo()
{
}

int PhotonTorpedo::getPhotonTorpDamage()
{
    return 800 + rnd(50);
}

bool PhotonTorpedo::didTorpedoHit( int distance )
{
    return (rnd(4) + ((distance / 500) + 1) <= 7);
}

} // namespace StarTrek
