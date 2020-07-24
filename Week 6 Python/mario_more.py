from cs50 import get_int

height = 0
while height > 8 or height < 1:
    height = get_int("Height: ")

for i in range(height):
    for j in range(height * 2 + 2):
        # left-side pyramid
        if i + j > height - 2 and j < height:
            print("#", end="")
        # right-side pyramid
        elif j > height + 1 and j - i < height + 3:
            print("#", end="")
        # space for all other positions
        elif i + j < height - 1 or j == height or j == height + 1:
            print(" ", end="")
    # change line at the bottom
    print("")
    
