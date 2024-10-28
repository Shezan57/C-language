class State:
    def _init_(self, pegs):
        self.pegs = pegs
    
    def _eq_(self, other):
        return self.pegs == other.pegs
    
    def _hash_(self):
        return hash(str(self.pegs))

class Action:
    def _init_(self, from_peg, to_peg):
        self.from_peg = from_peg
        self.to_peg = to_peg
    
    def _str_(self):
        return f"Move from peg {self.from_peg} to peg {self.to_peg}"

class Node:
    def _init_(self, state, action=None, parent=None):
        self.state = state
        self.action = action
        self.parent = parent
    
    def _str_(self):
        return str(self.action)
    
    def _repr_(self):
        return f"<Node {str(self)}>"

class TowerOfHanoi:
    def _init_(self, n=5):
        self.n = n
        self.initial_state = State([list(range(n, 0, -1)), [], []])
        self.goal_state = State([[], [], list(range(n, 0, -1))])
           
    def legal_moves(self, state):
        moves = []
        for i in range(3):
            for j in range(3):
                if i != j:
                    if len(state.pegs[i]) > 0:
                        if len(state.pegs[j]) == 0 or state.pegs[i][-1] < state.pegs[j][-1]:
                            moves.append(Action(i, j))
        return moves
    
    def result(self, state, action):
        new_pegs = [peg[:] for peg in state.pegs]
        disk = new_pegs[action.from_peg].pop()
        new_pegs[action.to_peg].append(disk)
        return State( new_pegs)