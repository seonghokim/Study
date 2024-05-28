def runMatch(mystr):
    
    # match case
    match mystr:
        # pattern 1
        case ["a"]:
            print("a")
        # pattern 2
        case ["a", *b]:
            print(f"a and {b}")
        # pattern 3
        case (*a, "e"):
            print(f"{a} and e")#(*a, "e"), [*a, "e"]
        # default pattern
        case _:
            print("No data")
            
runMatch([])
runMatch(["a"])
runMatch(["a", "b"])
runMatch(["b", "c", "d", "e"])