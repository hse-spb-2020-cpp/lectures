x = int('10')
print(x)

try:
    y = int('10f')
except ValueError:
    print('Oops, ValueError')
print('continue')
