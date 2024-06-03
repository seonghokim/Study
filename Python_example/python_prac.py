
class BirthDay:
    def __init__(self, birth_year: int, birth_month: int, birth_date: int):
        self.year = birth_year
        self.month = birth_month
        self.date = birth_date

    @classmethod
    def by_security_number(cls, security_number: str):
        birth_year = 1900 + int(security_number[:2])
        birth_month = int(security_number[2:4])
        birth_date = int(security_number[4:6])
        return cls(birth_year, birth_month, birth_date)


if __name__ == "__main__":
    birth1 = BirthDay(1999, 1, 31)
    birth2 = BirthDay.by_security_number("990131")
    print(birth1.year)
    print(birth2.year)


