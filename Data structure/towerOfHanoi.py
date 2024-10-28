class State:
    def __init__(self, disks, towers):
        self.disks = disks
        self.towers = towers

    def __eq__(self, other):
        return self.disks == other.disks and self.towers == other.towers

    def __hash__(self):
        return hash(str(self.disks) + str(self.towers))


def hanoi_blind_search(state, target_tower, max_depth):
    if state.towers[target_tower] == state.disks:
        return True

    if max_depth == 0:
        return False

    for src_tower in range(len(state.towers)):
        if state.towers[src_tower] == state.disks:
            continue

        for dest_tower in range(len(state.towers)):
            if src_tower == dest_tower:
                continue

            if state.towers[dest_tower] == [] or state.towers[src_tower][-1] < state.towers[dest_tower][-1]:
                disk = state.towers[src_tower].pop()
                state.towers[dest_tower].append(disk)

                if hanoi_blind_search(state, target_tower, max_depth - 1):
                    return True

                state.towers[dest_tower].pop()
                state.towers[src_tower].append(disk)

    return False


def hanoi_heuristic_search(state, target_tower, max_depth, heuristic):
    if state.towers[target_tower] == state.disks:
        return True

    if max_depth == 0:
        return False

    next_moves = []
    for src_tower in range(len(state.towers)):
        if state.towers[src_tower] == state.disks:
            continue

        for dest_tower in range(len(state.towers)):
            if src_tower == dest_tower:
                continue

            if state.towers[dest_tower] == [] or state.towers[src_tower][-1] < state.towers[dest_tower][-1]:
                disk = state.towers[src_tower].pop()
                state.towers[dest_tower].append(disk)
                next_moves.append((src_tower, dest_tower))
                state.towers[dest_tower].pop()
                state.towers[src_tower].append(disk)

    next_moves.sort(key=lambda move: heuristic(move, target_tower))

    for move in next_moves:
        src_tower, dest_tower = move
        disk = state.towers[src_tower].pop()
        state.towers[dest_tower].append(disk)

        if hanoi_heuristic_search(state, target_tower, max_depth - 1, heuristic):
            return True

        state.towers[dest_tower].pop()
        state.towers[src_tower].append(disk)

    return False


def heuristic(move, target_tower):
    src_tower, dest_tower = move
    if dest_tower == target_tower:
        return 0
    return 1


def solve_tower_of_hanoi_blind_search(disks):
    initial_state = State(disks, [[disk for disk in range(disks, 0, -1)], [], []])
    target_tower = 2  # Tower 3 is the target tower
    max_depth = 2 ** disks - 1  # Maximum depth for blind search

    if hanoi_blind_search(initial_state, target_tower, max_depth):
        print("Tower of Hanoi solution found using blind search.")
    else:
        print("No solution found using blind search.")


def solve_tower_of_hanoi_heuristic_search(disks):
    initial_state = State(disks, [[disk for disk in range(disks, 0, -1)], [], []])
    target_tower = 2  # Tower 3 is the target tower
    max_depth = float("inf")  # No depth limit for heuristic search

    if hanoi_heuristic_search(initial_state, target_tower, max_depth, heuristic):
        print("Tower of Hanoi solution found using heuristic search.")
    else:
        print("No solution found using heuristic search.")


# Testing the algorithms
solve_tower_of_hanoi_blind_search(5)
solve_tower_of_hanoi_heuristic_search(5)
