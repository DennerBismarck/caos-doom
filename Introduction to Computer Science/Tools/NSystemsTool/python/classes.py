class Base:

    def __init__(self) -> None:
        pass

class Number:

    def __init__(self, digits: list, base: Base) -> None:
        self.digits = digits
        self.base = base
        