class Set(object):
        
    def __init__(self):
        self.storage = []
    
    def is_empty(self):
        if self.storage:
            return False
        else:
            return True
    
    def append(self, item):
        if isinstance(item, list):
            for i in item:
                self.storage.append(i)
        else:
            self.storage.append(item)
            
    def __iter__(self):
        if not self.storage:
            raise StopIteration
        for item in self.storage:
            yield item
    
    def __contains__(self, item):
        if item in self.storage:
            return True
    
    def __eq__(self, other_list):
        if len(self.storage) != len(other_list):
            return False
        for i in range(len(other_list)):
            if other_list[i] not in self.storage:
                return False
        return True
        #return set(self.storage) == set(other_list)
    
    def __ne__(self, other_list):
        return not self.__eq__(other_list)
    
    def __len__(self):
        return len(self.storage)
    
    def __getitem__(self, index):
        return self.storage[index]
    
    def __repr__(self):
        return '<Set: {}>'.format(str(self.storage))
   