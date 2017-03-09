class Set(object):

    def __init__(self):
        self.internal_list = []

    def __contains__(self, item):
        if item in self.internal_list:
            return True
        else:
            return False

        def __repr__(self):
            return '<Set {}>'.format(self.internal_list)

    def __iter__(self):
        if not self.internal_list:
            raise StopIteration
        for item in self.internal_list:
            yield item

    def append(self, item):
        if isinstance(item, int) and item <= 0:
            # don't allow negative numbers to be added
            pass
        elif item not in self.internal_list:
            self.internal_list.append(item)

    def count(self, item):
        return self.internal_list.count(item)

    def intersection(self, other_list):
        new_list = []
        for item in other_list:
            if item not in self.internal_list:
                self.internal_list.append(item)


    def remove(self, item):
        self.internal_list.remove(item)

