#ifndef PHASER_HEADER
#define PHASER_HEADER

namespace StarTrek
{

class Phaser
{
public:
    Phaser();
    ~Phaser();

    bool arePhasersInRange( int distance );
    int getPhaserDamage( int amount, int distance );

};

} // namespace StarTrek

#endif
