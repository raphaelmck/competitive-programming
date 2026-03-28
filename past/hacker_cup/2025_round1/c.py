import sys
from collections import defaultdict

def solve():
	it = iter(sys.stdin.read().strip().split())
	T = int(next(it))
	out = []
	for t in range(1, T+1):
		N = int(next(it))

		freq = defaultdict(int)
		p = 0
		freq[0] = 1
		for _ in range(N):
			p ^= int(next(it))
			freq[p] += 1
		
		base = N * (N+1) * (N+2) // 6
		sub = 0
		for c in freq.values():
			sub += (c-1) * c * (c+1) // 6
		
		ans = base - sub
		out.append(f"Case #{t}: {ans}")
	
	print("\n".join(out))

if __name__ == "__main__":
	solve()
