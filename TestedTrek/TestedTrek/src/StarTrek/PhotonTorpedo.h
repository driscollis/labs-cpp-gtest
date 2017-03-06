#ifndef PHOTON_TORPEDO_HEADER
#define PHOTON_TORPEDO_HEADER

namespace StarTrek
{

class PhotonTorpedo
{
public:
    PhotonTorpedo();
    ~PhotonTorpedo();

    int getPhotonTorpDamage();
    bool didTorpedoHit( int distance );
};

} // namespace StarTrek

#endif // PHOTON_TORPEDO_HEADER
