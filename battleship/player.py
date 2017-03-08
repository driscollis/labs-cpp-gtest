class Player:
    
    def __init__(self, player_map):
        self.map = player_map
        self.ships = {}
        
    def check_location(self, ship, direction, x, y):
        if self.map.valid_ship_position(x, y):
            if direction == 'H':
                return self.map.valid_ship_position(x + ship.size - 1, y)
            else:
                return self.map.valid_ship_position(x, y + ship.size - 1)
        return False
    
    def place_ship(self, ship, direction, x, y):
        if self.check_location(ship, direction, x, y):
            if direction == 'H':
                for pos in range(x, x + ship.size):
                    self.map.ship_locations[pos, y] = True
                self.ships[ship] = [(pos, y) for pos in range(x, x + ship.size)]
            else:
                for pos in range(y, y + ship.size):
                    self.map.ship_locations[x, pos] = True
                self.ships[ship] = [(x, pos) for pos in range(y, y + ship.size)]
        else:
            print 'Ship cannot be placed in this location'
            
    def attack(self, x, y):
        if self.map.valid(x, y):
            self.map.attack(x, y)
            for ship in self.ships:
                if (x, y) in self.ships[ship]:
                    ship.it_hit()
                    return True
        return False