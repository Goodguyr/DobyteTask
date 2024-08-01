### Raw
Тестовое задание.
В данной задаче будут рассматриваться 13-ти значные числа в тринадцатиричной системе исчисления (цифры 0,1,2,3,4,5,6,7,8,9,A,B,C) с ведущими нулями.
Например, ABA98859978C0, 6789110551234, 0000007000000
Назовем число красивым, если сумма его первых шести цифр равна сумме шести последних цифр.
Пример:
Число 0055237050A00 - красивое, так как 0+0+5+5+2+3 = 0+5+0+A+0+0
Число 1234AB988BABA - некрасивое, так как 1+2+3+4+A+B != 8+8+B+A+B+A 
Задача:
написать программу на С/С++ печатающую в стандартный вывод количество 13-ти значных красивых чисел с ведущими нулями в тринадцатиричной системе исчисления.
В качестве решения должен быть предоставлено:
1) ответ - количество таких чисел. Ответ должен быть представлен в десятичной системе исчисления.
2) исходный код программы.
Пожалуйста, кроме кода, напишите ответ числом в теле письма.


# Takeaways
## Task
- We have a digit of length 13, and we need to count beautiful numbers, meaning sum of first six == last six
    - (0,1,2,3,4,5,6,7,8,9,A,B,C)
    - Essentially we dont care about the middle digit
    - We ONLY care about sum, we dont care about getting the full digit
- We are counting in a 13 digit number system

# What do I need to do?
Need to generate all possible numbers w size 1-6 and count their sums
We might have 1: [000001],...
2:[000011], [000002]
Because we have a digit on both sides, the amount of combos for each num = n * (n-1)
Observations
- sums = from 0 to 72    // 72 = 12 * 6, where 6 size of digit 
- a sum can be made from different digits BUT same digits arranged differently make same sum -> permutations
- we could store sorted digit arrangement and then count their combos [0,1,2] -> {0, 1, 2, }
{0, 2, 1, }
{1, 0, 2, }
{1, 2, 0, }
{2, 0, 1, }
{2, 1, 0, }

we have 13 possible digits taken 6 times
nPr = 13^6 = 4,826,809
but only 73 possible sums

n - sum
6 elems
13 options

map[0] = [0,0,0,0,0] -> 1
map[1] = [0,0,0,0,1] -> 5 
map[2] = [0,0,0,1,1], [0,0,0,0,2]
map[3] = [0,0,1,1,1], [0,0,0,1,2], [0,0,0,0,3]
map[4] = [0,1,1,1,1], [0,0,0,2,2], [0,0,0,1,3], [0,0,0,0,4]
map[5] = [1,1,1,1,1], [0,1,1,1,2], 
...
map[72] = [12,12,12,12,12]

# Efficient solution
DP solution is possible, but for the sake of readability, combinatoric approach is used.