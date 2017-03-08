class InvalidBoat(Exception):
    pass

class Ship:
    def __init__(self, ship_type):
        self.type = ship_type
        self.ships = {'Aircraft carrier': 5,
                      'Battleship': 4,
                      'Cruiser': 3,
                      'Destroyer': 2,
                      'Submarine': 1,
                      }
        
        if ship_type not in self.ships:
            raise InvalidBoat(
                '"{}" is an invalid ship type!'.format(ship_type))
        
        self.size = self.ships[self.type]
        self.hit_count = 0
        
    def it_hit(self):
        if not self.isDestroyed():
            self.hit_count += 1
            if self.hit_count == self.size:
                print 'You sunk my {}'.format(self.type)
        
    def isDestroyed(self):
        return self.hit_count == self.ships[self.type]