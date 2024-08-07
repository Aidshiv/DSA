def print_board(board):
""" Print the current state of the Tic-Tac-Toe board """
for row in board:
print(" | ".join(row))
print("-" * 9)
def check_winner(board, player):
""" Check if the specified player has won the game """
for row in board:
if all(cell == player for cell in row):
return True
for col in range(3):
if all(board[row][col] == player for row in range(3)):
return True
if all(board[i][i] == player for i in range(3)):
return True
if all(board[i][2-i] == player for i in range(3)):
return True
return False
def is_full(board):
""" Check if the board is completely filled """
return all(cell != ' ' for row in board for cell in row)
def tic_tac_toe():
""" Main function to run the Tic-Tac-Toe game """
board = [[' ' for _ in range(3)] for _ in range(3)]
current_player = 'X'
while True:
print_board(board)
print(f"Player {current_player}'s turn.")
row = int(input("Enter row (1-3): "))
col = int(input("Enter column (1-3): "))
row -= 1
col -= 1
if board[row][col] == ' ':
board[row][col] = current_player
else:
print("Invalid move! Try again.")
continue
# Check if the current player has won
if check_winner(board, current_player):
print_board(board)
print(f"Player {current_player} wins!")
break
# Check if the board is full (tie game)
if is_full(board):
print_board(board)
print("It's a tie!")
break
# Switch to the other player
current_player = 'O' if current_player == 'X' else 'X'
if __name__ == "__main__":
tic_tac_toe()