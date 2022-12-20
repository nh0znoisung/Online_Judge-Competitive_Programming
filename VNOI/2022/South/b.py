graph = []
road = []
def search(a,b,c):
    for i in graph[a].keys():
        if graph[a][i] < c:
            continue
        elif i == str(b):
            return True
        else:
            if search(int(i),b,c):
                return True
            else:
                continue
    return False

def main():
    n,m,q = input().split(' ')
    n,m,q = map(int, [n,m,q])
    for i in range(n):
        graph.append({})
    for i in range(m):
        u,v,c = input().split(' ')
        u,v,c = map(int, [u,v,c])
        graph[u-1][str(v-1)] = c
        road.append((u-1,v-1))
    for i in range(q):
        query = input()
        if query[0] == "C":
            query = query[2:]
            u,c = map(int, query.split(' '))
            u,c = map(int, [u,c])
            if c > graph[road[u-1][0]][str(road[u-1][1])]:
                graph[road[u-1][0]][str(road[u-1][1])] = c
        else:
            query = query[2:]
            a,b,c = map(int, query.split(' '))
            if search(a-1,b-1,c): print("YES")
            else: print("NO")
main()