import sys

def solve():
	it = iter(sys.stdin.read().strip().split())
	t = int(next(it))
	out = []
	for i in range(1, t+1):
		n = int(next(it))
		m = int(next(it))
		ok = (m <= n <= 2*m-2) or (n >= 2*m and n % 2 == 0)
		out.append(f"Case #{i}: {"YES" if ok else "NO"}")

	print("\n".join(out))

if __name__ == "__main__":
	solve()
