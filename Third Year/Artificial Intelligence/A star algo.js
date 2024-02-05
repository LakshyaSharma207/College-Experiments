             // A  B  C  D  E
const graph = [[0, 1, 1, 0, 0], // A
               [1, 0, 0, 1, 0], // B
               [1, 0, 0, 1, 1], // C
               [0, 1, 1, 0, 1], // D
               [0, 0, 1, 1, 0]] // E

const cost = [[0, 3, 2, 0, 0],
              [3, 0, 0, 4, 0],
              [2, 0, 0, 2, 4],
              [0, 1, 2, 0, 1],
              [0, 0, 3, 1, 0]];
// coordinates for heuristic cost
const coordinates = [{ x: 0, y: 0 }, // A
                     { x: 1, y: 0 }, // B
                     { x: 2, y: 0 }, // C
                     { x: 1, y: 1 }, // D
                     { x: 2, y: 1 }];// E

let priorQueue = [{'cost': 0, 'node': 0, 'path': ['A']}];  // (cost, node, path)
let visited = [0, 0, 0, 0, 0];

function heuristic(node, goal) {
    const dx = coordinates[node].x - coordinates[goal].x;
    const dy = coordinates[node].y - coordinates[goal].y;
    return Math.sqrt(dx * dx + dy * dy);
}

while(priorQueue != []){
    priorQueue.sort((a, b) => a.cost - b.cost);
    let {cost: currentCost, node: currentNode, path: currentPath} = priorQueue.shift(); // pop() returns last value of [] like stack
    visited[currentNode] = 1;

    if (currentNode == 4){
        console.log(`Path: ${currentPath}`);
        console.log(`Cumulative Cost: ${currentCost}`);
        break;
    } else{
        let i;
        for (i = 0; i < 5; i+=1){
            if (graph[currentNode][i] == 1 && visited[i] == 0){
                let newPath = [...currentPath, String.fromCharCode(65 + i)];
                let newCost = currentCost + cost[currentNode][i] + heuristic(i, 4);
                priorQueue.push({'cost': newCost, 'node': i, 'path': newPath});
            }
        }
    }
}


