class Solution:
    def validArrangement(self, pairs):
        from collections import defaultdict, deque

        adjacencyMatrix = defaultdict(deque)
        Degree=defaultdict(int)

        # Build the adjacency list and track in-degrees and out-degrees
        for pair in pairs:
            start, end = pair
            adjacencyMatrix[start].append(end)
            Degree[start]+=1
            Degree[end]-=1

        result = []

        def visit(node):
            while adjacencyMatrix[node]:
                nextNode = adjacencyMatrix[node].popleft()
                visit(nextNode)
            result.append(node)

        # Find the start node
        startNode = pairs[0][0]
        for node in Degree:
            if Degree[node]==1:
                startNode = node
                break
        # Start DFS traversal
        visit(startNode)

        # Reverse the result since DFS gives us the path in reverse
        result.reverse()

        # Construct the result pairs
        pairedResult = [
            [result[i - 1], result[i]] for i in range(1, len(result))
        ]

        return pairedResult