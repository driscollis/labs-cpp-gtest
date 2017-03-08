import game
import playermap
import player
import ship

import unittest

SHIPS = {'Aircraft carrier': 5,
         'Battleship': 4,
         'Cruiser': 3,
         'Destroyer': 2,
         'Submarine': 1
         }

class TestSingleShip(unittest.TestCase):
    
    def test_number_of_ship_types(self):
        s = ship.Ship('Battleship')
        self.assertEqual(len(s.ships), len(SHIPS))
        
    def test_cannot_add_new_ship(self):
        with self.assertRaises(ship.InvalidBoat):
            ship.Ship('U-boat')
    
    def test_ship_create(self):
        for boat in SHIPS:
            s = ship.Ship(boat)
            self.assertEqual(SHIPS[boat], s.ships[boat])
            
    def test_ship_initial_damage(self):
        for boat in SHIPS:
            s = ship.Ship(boat)
            self.assertEqual(s.hit_count, 0)
    
    def test_ship_take_damage(self):
        for boat in SHIPS:
            s = ship.Ship(boat)
            s.it_hit()
            self.assertEqual(s.hit_count, 1)
            
    def test_ship_destroy_submarine(self):
        s = ship.Ship('Submarine')
        s.it_hit()
        self.assertTrue(s.isDestroyed())
        
    def test_ship_destroy_battleship(self):
        s = ship.Ship('Battleship')
        for cnt in range(s.ships['Battleship']):
            s.it_hit()
        self.assertTrue(s.isDestroyed())

    
class TestMap(unittest.TestCase):
    
    def test_map_correct_size(self):
        m = playermap.Map()
        self.assertEqual(m.size, 10)
        
    def test_map_location_valid(self):
        m = playermap.Map()
        self.assertTrue(m.valid(1,1))

    def test_map_is_attack(self):
        m = playermap.Map()
        m.attack(1,1)
        self.assertTrue(m.isHit(1,1))
        
    def test_map_attack_out_of_bounds(self):
        m = playermap.Map()
        with self.assertRaises(playermap.OutOfBounds):
            m.attack(11,11)
    
    def test_map_unattacked_not_hit(self):
        m = playermap.Map()
        self.assertFalse(m.isHit(1,1))
        
        
class TestPlayer(unittest.TestCase):
    
    def test_valid_ship_location(self):
        m = playermap.Map()
        p = player.Player(m)
        s = ship.Ship('Destroyer')
        direction = 'H'
        
        self.assertTrue(p.check_location(s, direction, 1, 2))
    
    def test_invalid_ship_start_location(self):
        m = playermap.Map()
        p = player.Player(m)
        s = ship.Ship('Destroyer')
        direction = 'H'
        
        self.assertFalse(p.check_location(s, direction, 100, 100))
    
    def test_invalid_ship_end_location(self):
        m = playermap.Map()
        p = player.Player(m)
        s = ship.Ship('Destroyer')
        direction = 'H'
    
        self.assertFalse(p.check_location(s, direction, 10, 10))
        
    def test_valid_first_ship_placement(self):
        m = playermap.Map()
        p = player.Player(m)
        s = ship.Ship('Destroyer')
        direction = 'H'
        
        p.place_ship(s, direction, 1, 1)
        self.assertIn((1,1), m.ship_locations)
        
    def test_overlapping_ship_placement(self):
        m = playermap.Map()
        p = player.Player(m)
        s = ship.Ship('Destroyer')
        direction = 'H'
        
        p.place_ship(s, direction, 1, 1)
        self.assertFalse(p.check_location(s, direction, 1, 1))
        
    def test_attack_occupied_location(self):
        m = playermap.Map()
        p = player.Player(m)
        s = ship.Ship('Submarine')
        direction = 'H'
        
        p.place_ship(s, direction, 1, 1)
        self.assertTrue(p.attack(1, 1))
        
class TestGame(unittest.TestCase):
    
    def test_game_board_size(self):
        g = game.Game()
        self.assertEqual(g.board_size, 10)
        
    def test_game_number_players(self):
        g = game.Game()
        self.assertEqual(g.number_players, 2)
        
    def test_valid_ship_list(self):
        g = game.Game()
        ships = g.generate_ship_list()
        ship_types = [boat.type for boat in ships]
        self.assertEqual(1, ship_types.count('Aircraft carrier'))
        self.assertEqual(1, ship_types.count('Battleship'))
        self.assertEqual(1, ship_types.count('Cruiser'))
        self.assertEqual(2, ship_types.count('Destroyer'))
        self.assertEqual(2, ship_types.count('Submarine'))
    
if __name__ == '__main__':
    unittest.main()