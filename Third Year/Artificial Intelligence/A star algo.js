             // A  B  C  D  E  F  G
const graph = [[0, 1, 1, 0, 0, 1, 0], // A
               [1, 0, 0, 1, 0, 0, 0], // B
               [1, 0, 0, 1, 1, 0, 0], // C
               [0, 1, 1, 0, 1, 1, 0], // D
               [0, 0, 1, 1, 0, 0, 1], // E
               [1, 0, 0, 1, 0, 0, 1], // F
               [0, 1, 0, 0, 1, 1, 0]] // G

const cost = [[0, 3, 2, 0, 0, 4, 0],
              [3, 0, 0, 4, 0, 0, 0],
              [2, 0, 0, 2, 4, 0, 0],
              [0, 1, 2, 0, 1, 3, 0],
              [0, 0, 3, 1, 0, 0, 6],
              [4, 0, 0, 3, 0, 0, 7],
              [0, 5, 0, 0, 6, 7, 0]];

// heuristic cost from each node to the goal node
const heuristic = [7, 6, 5, 4, 3, 2, 0];

let priorQueue = [{'cost': 0, 'node': 0, 'path': ['A']}];  // (cost, node, path)
let visited = [0, 0, 0, 0, 0, 0, 0];

while(priorQueue.length !== 0){
    priorQueue.sort((a, b) => a.cost - b.cost);
    let {cost: currentCost, node: currentNode, path: currentPath} = priorQueue.shift(); // pop() returns last value of []
    visited[currentNode] = 1;

    if (currentNode == 4){
        console.log(`Path: ${currentPath}`);
        console.log(`Final Cost: ${currentCost}`);
        break;
    } else{
        let i;
        for (i = 0; i < 5; i+=1){
            if (graph[currentNode][i] == 1 && visited[i] == 0){
                let newPath = [...currentPath, String.fromCharCode(65 + i)];
                let newCost = currentCost + cost[currentNode][i] + heuristic[i];
                priorQueue.push({'cost': newCost, 'node': i, 'path': newPath});
            }
        }
    }
}
