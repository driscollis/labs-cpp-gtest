import string

class CharacterInString:
    def __init__(self, characters, string):
        self.characters = characters
        self.string = string
        
    def evaluate(self):
        for char in self.characters:
            if char in self.string:
                return True
        return False
    
class LengthOfString:
    def __init__(self, required_length, string):
        self.required_length = required_length
        self.string = string
        
    def evaluate(self):
        return len(self.string) > self.required_length

def check(password, admin=False):
    errors = set()
    
    def validate( validateclass, exception ):
        if not validateclass.evaluate():
            errors.add(exception)
    
    validate( LengthOfString( 7, password ), 'TooShortException' )
    validate( CharacterInString( string.ascii_letters, password ), 'NoAlphabeticException')
    validate( CharacterInString( string.digits, password), 'NoDigitException')
    if admin:
        validate(LengthOfString(10, password),'AdminTooShortException')
        validate(CharacterInString(string.punctuation, password), 'AdminNoSpecialCharacterException')
        validate(CharacterInString(password[-1:], string.punctuation+string.digits), 
                     'AdminLastCharacterIsNotSpecialOrNumber')         
        
    return errors