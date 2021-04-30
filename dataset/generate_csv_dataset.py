from random import randint


def values_generator(amount: int, min_value: int = 0, max_value: int = 1000000):
    """Function to generate values for tests"""
    for j in range(1):
        with open("input-" + str(amount) + "-" + str(j) + ".txt", "a") as inp:
            for i in range(amount):
                value = randint(min_value, max_value)
                inp.write(str(value) + " ")
            inp.write("\n")



if __name__ == '__main__':
    help_message = """"""
    amount = int(input("Количество генерируемых чисел\n"))
values_generator(amount)
