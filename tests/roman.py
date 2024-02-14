str = input("Enter a roman numeral: ")
dic = {'I': 1, 'V': 5, 'X':10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}

total = 0
prev_value = 0

for i in range(len(str)):
    current_value = dic[str[i]]
    if current_value > prev_value:
        total += current_value - 2 * prev_value
    else:
        total += current_value
    prev_value = current_value

print(total)