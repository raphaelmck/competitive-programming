import sys
from collections import deque
from array import array

def solve():
	it = iter(sys.stdin.read().strip().split())
	t = int(next(it))
	out = []
	for i in range(1, t+1):
		n = int(next(it))
		k = int(next(it))
		m = int(next(it))
		
		occ = [array('I') for _ in range(n+1)]
		routes = []
		lens = []
		nxt = []

		for r in range(m):
			l = int(next(it))
			seq = [int(next(it)) for _ in range(l)]
			routes.append(array('I', seq))
			lens.append(l)
			nxt.append(list(range(l+1)))
			for j, u in enumerate(seq):
				o = occ[u]
				o.append(r)
				o.append(j)
		
		def find(r, j):
			nr = nxt[r]
			while nr[j] != j:
				nr[j] = nr[nr[j]]
				j = nr[j]
			return j
			
		dist = [-1] * (n+1)
		dist[1] = 0
		q = deque([1])

		while q:
			u = q.popleft()
			du = dist[u]
			ol = occ[u]

			for p in range(0, len(ol), 2):
				r = ol[p]
				idx = ol[p + 1]
				Lr = lens[r]
				limit = idx + k
				if limit >= Lr:
					limit = Lr - 1
				if idx + 1 > limit:
					continue

				arr_r = routes[r]

				j = find(r, idx + 1)
				while j <= limit:
					v = arr_r[j]
					if dist[v] == -1:
						dist[v] = du + 1
						q.append(v)
					nxt[r][j] = find(r, j + 1)
					j = nxt[r][j]

		ans = 0
		for w in range(1, n+1):
			ans += w * dist[w]
		
		out.append(f"Case #{i}: {ans}")

	print("\n".join(out))

if __name__ == "__main__":
	solve()
