import ship

class Game:
    def __init__(self):
        self.board_size = 10
        self.number_players = 2
        
    def generate_ship_list(self):
        ships = []
        ships.append(ship.Ship('Aircraft carrier'))
        ships.append(ship.Ship('Battleship'))
        ships.append(ship.Ship('Cruiser'))
        ships.append(ship.Ship('Destroyer'))
        ships.append(ship.Ship('Destroyer'))
        ships.append(ship.Ship('Submarine'))
        ships.append(ship.Ship('Submarine'))
        return ships
    
    
