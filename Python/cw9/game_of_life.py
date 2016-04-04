def neighbors(cell, width=15, height=7):
    x, y = cell
    width, height = width -1, height-1
    neighbors = []
    for i in [0, -1, 1]:
        if y+i > height:
            i = -height
        elif y+i < 0:
            i = height
        for j in [0, -1, 1]:
            if x+j > width:
                j = -width
            elif x+j < 0:
                j = width
            if not(i == 0 and j == 0):
                yield (x + j, y + i)

def alive_neighbors(cell, board):
    neighbor_counter = 0
    for neighbor in neighbors(cell):
        if neighbor in board:
            neighbor_counter += 1
    return neighbor_counter

def next_round(board):
    nowa_board = set()
    suspects = set()
    for cell in board:
        for s in neighbors(cell):
            suspects.add(s)
        if alive_neighbors(cell, board) in {2, 3}:
            nowa_board.add(cell)
    for cell in suspects:
        if alive_neighbors(cell, board) == 3:
            nowa_board.add(cell)
    return nowa_board

def gen_board(level):
    board = set()
    board_list = filter(None, level.split('\n'))
    for y, row in enumerate(board_list):
        for x, block in enumerate(row):
            if block == "#":
                 board.add((x, y))
    return(board)

def print_board(board, width=15, height=7):
    for y in range(height):
        gen = ("#" if (x,y) in board else "." for x in range(width))
        print(''.join(gen))

def inspect_life(board):
    board_life = set()
    creativity = 0
    adulthood = 0
    while True:
        while not board in board_life:
            board_life.add(frozenset(board))
            board = next_round(board)
            adulthood += 1
        adulthood -= 1
        adult_board = board

        while adult_board != next_round(board):
            creativity +=  1
            board = next_round(board)
        break
    print("Dorosłość: {} Współczynnik kreatywności: {}".format(adulthood, creativity))
    return None

def play_game(board):
    print_board(board)
    choice = ""
    while True:
        choice = input(">")
        if choice in ['stop', 'koniec']:
            break
        board = next_round(board)
        print_board(board)


level1 = """
##........#####
...###.........
...#.#...######
...###.........
........##.....
##....###......
.#.............
"""

level2 = """
...............
...............
.......###.....
...............
...............
...............
...............
"""

level3 = """
......#........
.....#.........
....#..........
...#...........
..#........#...
.#.........#...
#..........#...
"""

level4 = """
...............
...............
...............
...............
...........#...
...........#...
...........#...
"""

level5 = """
......#........
.....#.........
....#..........
...#...........
..#............
.#.............
#..............
"""

board = gen_board(level3)


play_game(board)
#inspect_life(board)
