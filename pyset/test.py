import pyset

import copy
import unittest

class TestSet(unittest.TestCase):
    
    def test_is_empty(self):
        my_set = pyset.Set()
        self.assertEqual(True, my_set.is_empty())
        
    def test_append(self):
        my_set = pyset.Set()
        my_set.append( 5 )
        self.assertIn( 5, my_set )
        
    def test_equals(self):
        new_list = [1, 2, 3]
        my_set = pyset.Set()
        my_set.append([1, 2, 3])
        self.assertEqual(new_list, my_set)
        self.assertEqual(my_set, my_set)
        
    def test_notequal(self):
        new_list = [1, 2, 3]
        my_set = pyset.Set()
        my_set.append([3,4,5])
        self.assertNotEqual(new_list, my_set)
        
    def test_reverse_is_equal(self):
        new_list = [1,2,3]
        reversed_list = copy.deepcopy(new_list)
        reversed_list.reverse()
        my_set = pyset.Set()
        my_set.append(reversed_list)
        self.assertEqual(new_list, my_set)
        
    def test_you_are_not_cheating(self):
        new_list = [1, 2, 3]
        my_set = pyset.Set()
        my_set.append( new_list )
        big_list = [1, 1, 2, 2, 3, 3]
        self.assertNotEqual(big_list, my_set)
    
    
if __name__ == '__main__':
    unittest.main()