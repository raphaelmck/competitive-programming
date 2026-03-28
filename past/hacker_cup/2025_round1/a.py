import sys

def solve():
	it = iter(sys.stdin.read().strip().split())
	T = int(next(it))
	out = []
	for t in range(1, T+1):
		n = int(next(it))
		a = [int(next(it)) for _ in range(n)]
		if n <= 1:
			ans = 0
		else:
			ans = max(abs(a[i+1] - a[i]) for i in range(n-1))
		out.append(f"Case #{t}: {ans}")

	print("\n".join(out))

if __name__ == "__main__":
	solve()
