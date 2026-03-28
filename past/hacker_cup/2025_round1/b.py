import sys

def solve():
	it = iter(sys.stdin.read().strip().split())
	T = int(next(it))
	out = []
	for t in range(1, T+1):
		N = int(next(it))
		A = int(next(it))
		B = int(next(it))

		ans = [1] * N + [1] * (N-1) + [B]
		out.append(f"Case #{t}: {' '.join(map(str, ans))}")

	print("\n".join(out))

if __name__ == "__main__":
	solve()
