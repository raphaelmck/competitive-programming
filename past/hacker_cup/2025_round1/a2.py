import sys

def check(a, h):
	n = len(a)
	i = 0
	while i < n:
		minB = a[i]
		j = i
		while j + 1 < n and abs(a[j] - a[j+1]) <= h:
			j += 1
			minB = min(minB, a[j])
		
		if minB > h:
			return False
		i = j + 1
	return True

def solve():
	it = iter(sys.stdin.read().strip().split())
	T = int(next(it))
	out = []
	for t in range(1, T+1):
		n = int(next(it))
		a = ([int(next(it)) for _ in range(n)])

		if n <= 1:
			out.append(f"Case #{t}: {a[0]}")
			continue

		maxA = max(a)
		maxD = max(abs(a[i+1] - a[i]) for i in range(n-1))
		l, r = 0, max(maxA, maxD)
		while l < r:
			m = (l+r) // 2
			if check(a, m):
				r = m
			else:
				l = m+1

		out.append(f"Case #{t}: {l}")

	print("\n".join(out))

if __name__ == "__main__":
	solve()
