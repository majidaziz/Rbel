def main():
    #creates list of 4 columns 145 rows
    yarra = [[0 for x in range(4)]for y in range(145)]
    row = 0
    col = 0
    with open("taz.txt") as wobj:
        for line in wobj:
            for ch in line:
                if col > 3:
                    row += 1
                    col = 0
                if row > 144:
                    print("array fully filled")
                    break;
                yarra[row][col] = ch
                col += 1
    for x in yarra:
        print(''.join(*zip(*x)))
