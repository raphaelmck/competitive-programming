import sys
from bisect import bisect_left
from collections import Counter

def cap(t, b, pref):
    i = bisect_left(b, t)
    return (len(b) - i) * t + pref[i]

def solve():
    it = iter(sys.stdin.buffer.read().split())
    t = int(next(it))
    out = []
    for i in range(1, t + 1):
        N = int(next(it)); 
        M = int(next(it))
        A = [int(next(it)) for _ in range(N)]
        B = [int(next(it)) for _ in range(M)]

        cnt = Counter(A)
        g = [cnt[s] for s in sorted(cnt.keys(), reverse=True)]
        d = len(g)

        B.sort()
        pref = [0] * (len(B) + 1)
        for idx, x in enumerate(B, 1):
            pref[idx] = pref[idx - 1] + x

        G = [0] * (d + 1)
        H = [0] * (d + 1)
        for lvl in range(1, d + 1):
            G[lvl] = G[lvl - 1] + g[lvl - 1]
            H[lvl] = H[lvl - 1] + lvl * g[lvl - 1]

        lim = min(d, len(B))
        best = 0
        bound = float("inf") 

        for k in range(1, lim + 1):
            t_players = G[k] 
            bound = min(bound, (H[k] + cap(t_players, B, pref)) // t_players - 1)
            if k <= bound:
                best = t_players
            else:
                break

        out.append(f"Case #{i}: {best}")

    print("\n".join(out))

if __name__ == "__main__":
    solve()
