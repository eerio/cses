from functools import lru_cache
import sys

sys.setrecursionlimit(10000)

@lru_cache(maxsize=None)
def solution(a: int, b: int) -> int:
    if a == b:
        return 0
    
    if a > b:
        return solution(b, a)

    # a: wysokość, b: szerokość
    assert 1 <= a < b

    try:
        cut_horizontal = min(
                solution(y, b) + solution(a - y, b)
                for y in range(1, a // 2 + 1)
        )
    except ValueError:
        cut_horizontal = float('inf')

    try:
        cut_vertical = min(
                solution(a, x) + solution(a, b - x)
                for x in range(1, b // 2 + 1)
        )
    except ValueError:
        cut_vertical = float('inf')

    return 1 + min(cut_horizontal, cut_vertical)


if __name__ == '__main__':
    a, b = input().split()
    a, b = int(a), int(b)
    print(solution(a, b))

