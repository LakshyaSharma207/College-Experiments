import math
from random import choice

board = [['' for _ in range(3)] for _ in range(3)]
scores = {
    'X': 1,
    'O': -1,
    'tie': 0
}
current_player = 'X'

def empty_cells(board):
    empty_cells = []
    for i in range(3):
        for j in range(3):
            if board[i][j] == '':
                empty_cells.append((i, j))
    return empty_cells

def bestMove():
    global current_player
    # AI makes its move 
    if current_player == 'O':
        return
    
    bestScore = -math.inf
    nextMove = []
    depth = len(empty_cells(board))

    if depth == 9:
        x = choice([0, 1, 2])
        y = choice([0, 1, 2])
        board[x][y] = 'X'

    else:
        for i in range(3):
            for j in range(3):
                if board[i][j] == '':
                    board[i][j] = 'X'
                    score = minmax(board, depth, False)
                    board[i][j] = ''
                    
                    if score > bestScore:
                        bestScore = score
                        nextMove = [i, j]

        board[nextMove[0]][nextMove[1]] = 'X'
    current_player = 'O'
    printBoard()

def checkWinner(state):
    for row in state:
        if row[0] == row[1] == row[2] != '':
            return row[0]
    
    for i in range(3):
        if state[0][i] == state[1][i] == state[2][i] != '':
            return state[0][i]
        
    if state[0][0] == state[1][1] == state[2][2] != '':
        return state[0][0]
    
    if state[0][2] == state[1][1] == state[2][0] != '':
        return state[0][2]
    
    # Check if there are any empty cells left
    for row in empty_cells(state):
        if row:
            return None
    
    # If there are no empty cells left, it's a tie
    for row in empty_cells(state):
        if row == None:
            return 'tie'
        
    return 'tie'
    
def printBoard():
    for row in board:
        print(row)
    

# minmax function taking the current board with potential AI move and first move is NOT maximizing
def minmax(state, depth, isMaximizing):
    if depth == 0:
        return scores[checkWinner(state)]
    
    winner = checkWinner(state)
    if winner != None:
        return scores[winner]
    
    if isMaximizing:
        bestScore = -math.inf
        for i in range(3):
            for j in range(3):
                if state[i][j] == '':
                    state[i][j] = 'X'
                    score = minmax(state, depth - 1, False)
                    state[i][j] = ''

                    bestScore = max(score, bestScore)
                    
        return bestScore
    else:
        bestScore = math.inf
        for i in range(3):
            for j in range(3):
                if state[i][j] == '':
                    state[i][j] = 'O'
                    score = minmax(state, depth - 1, True)
                    state[i][j] = ''
                    
                    bestScore = min(score, bestScore)
        return bestScore

def main():
    global current_player
    while len(empty_cells(board)) > 0:
        winner = checkWinner(board)
        if winner != None:
            print("Winner: ",winner)
            break

        bestMove()
        player_input = list(input("Enter your move for 'O': "))
        player_input = [int(element.strip()) for element in player_input if element.strip()]
        board[player_input[0] - 1][player_input[1] - 1] = 'O'
        current_player = 'X'


if __name__ == "__main__":
    main()
