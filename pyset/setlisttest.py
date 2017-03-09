import pysetlist

import unittest

class TestPySet(unittest.TestCase):

    def setUp(self):
        self.my_set = pysetlist.Set()

    def test_set_empty(self):
        self.assertFalse(self.my_set.internal_list)

    def test_append(self):
        self.my_set.append(5)
        self.assertIn(5, self.my_set)

    def test_cannot_append_zero(self):
        """
        Tests that we can't add zero to the set
        Also checks that the set remains empty
        """
        self.my_set.append(0)
        self.assertNotIn(0, self.my_set)
        self.assertFalse(self.my_set.internal_list)

    def test_cannot_add_negative_numbers(self):
        self.my_set.append(-1)
        self.assertNotIn(-1, self.my_set)

    def test_cannot_add_same_item_twice(self):
        self.my_set.append(1)
        self.my_set.append(1)
        self.assertNotEqual(self.my_set.count(1), 2)
        self.assertEqual(self.my_set.count(1), 1)

    def test_remove_item(self):
        """
        Tests that after adding and removing a single item, the
        set is empty
        """
        self.my_set.append(1)
        self.my_set.remove(1)
        self.assertFalse(self.my_set.internal_list)

    def test_empty_intersections(self):
        my_set2 = pysetlist.Set()
        self.my_set.intersection(my_set2.internal_list)
        self.assertFalse(self.my_set.internal_list)

    def tearDown(self):
        self.my_set = None
        del self.my_set

if __name__ == '__main__':
    unittest.main()