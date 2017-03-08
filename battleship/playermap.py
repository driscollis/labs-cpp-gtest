class OutOfBounds(Exception):
    pass

class Map:
    def __init__(self):
        self.size = 10
        self.hit_locations = {}
        self.ship_locations = {}
        
    def valid(self, x, y):
        return x in range(1, self.size+1) and \
               y in range(1, self.size+1) 
    
    def valid_ship_position(self, x, y):
        return self.valid(x, y) and \
               (x, y) not in self.ship_locations
        
    def attack(self, x, y):
        if not self.valid(x, y): 
            raise OutOfBounds
        if (x, y) not in self.hit_locations:
            self.hit_locations[(x, y)] = True
    
    def isHit(self, x, y):
        return self.hit_locations.get((x, y), False);