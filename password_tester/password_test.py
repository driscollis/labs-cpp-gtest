import password

import unittest

class TestPassword(unittest.TestCase):
    
    def test_greater_than_seven(self):
        pw = '123'
        
        self.assertIn('TooShortException', password.check(pw))
            
    def test_admin_greater_than_ten(self):
        pw = '12345678'
        
        self.assertIn('AdminTooShortException', password.check(pw, admin=True) )
    
    def test_contain_no_alphabet_char(self):
        pw = '12345678'
        
        self.assertIn('NoAlphabeticException', password.check(pw))
            
    def test_contain_no_digit(self):
        pw = 'abcdefgh'
        
        self.assertIn('NoDigitException', password.check(pw))
            
    def test_valid_password(self):
        pw = 'abcdefg7'
        
        self.assertEqual( set(), password.check( pw ) )
    
    def test_admin_does_not_contain_special(self):
        pw = 'abc123def456'
        
        self.assertIn('AdminNoSpecialCharacterException', password.check(pw, admin=True))
            
    def test_admin_last_char_is_not_special(self):
        pw = 'abc!23def45a'
        
        self.assertIn('AdminLastCharacterIsNotSpecialOrNumber', password.check(pw, admin=True))
            
    def test_valid_admin_password(self):
        pw = 'abc123def456!'
        
        self.assertEqual(set(), password.check(pw, admin=True))
        
    def test_all_errors(self):
        pw = ''
        
        self.assertEqual(set(['TooShortException', 'NoAlphabeticException', 'NoDigitException']),
                         password.check(pw))
        
    def test_all_admin_errors(self):
        pw = ''
        
        self.assertEqual(set(['AdminTooShortException', 'TooShortException', 'NoAlphabeticException', 
                          'NoDigitException', 'AdminNoSpecialCharacterException', 
                          'AdminLastCharacterIsNotSpecialOrNumber']),
                         password.check(pw, admin=True))
            
if __name__ == '__main__':
    unittest.main()