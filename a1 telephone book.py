'''
QUESTION:
    Consider telephone book database of N clients. Make use of a hash table implementation to quickly look up client‘s telephone number. 
    Make use of two collision handling techniques and compare them using number of comparisons required to find a set of telephone numbers.

OUTPUT:
    Chaining       - Telephone number for key 123456 : John Doe
    Linear Probing - Telephone number for key 123456 : John Doe
'''

class TelephoneBook:
    def __init__(self, size, collision_handling):
        self.size = size
        self.collision_handling = collision_handling
        self.table = [None] * size

    def hash_function(self, key):
        return key % self.size

    def insert(self, key, value):
        index = self.hash_function(key)

        if self.collision_handling == 'chaining':
            if self.table[index] is None:
                self.table[index] = []
            self.table[index].append((key, value))
        elif self.collision_handling == 'linear_probing':
            while self.table[index] is not None:
                index = (index + 1) % self.size
            self.table[index] = (key, value)

    def search(self, key):
        index = self.hash_function(key)

        if self.collision_handling == 'chaining':
            if self.table[index] is None:
                return None
            for pair in self.table[index]:
                if pair[0] == key:
                    return pair[1]
            return None
        elif self.collision_handling == 'linear_probing':
            while self.table[index] is not None:
                if self.table[index][0] == key:
                    return self.table[index][1]
                index = (index + 1) % self.size
            return None


# Example usage
telephone_book_chaining = TelephoneBook(10, 'chaining')
telephone_book_chaining.insert(123456, 'John Doe')
telephone_book_chaining.insert(789012, 'Jane Smith')
telephone_book_chaining.insert(345678, 'Michael Johnson')

telephone_book_linear_probing = TelephoneBook(10, 'linear_probing')
telephone_book_linear_probing.insert(123456, 'John Doe')
telephone_book_linear_probing.insert(789012, 'Jane Smith')
telephone_book_linear_probing.insert(345678, 'Michael Johnson')

# Searching for a telephone number
key = 123456
print("Chaining       - Telephone number for key", key, ":", telephone_book_chaining.search(key))
print("Linear Probing - Telephone number for key", key, ":", telephone_book_linear_probing.search(key))
