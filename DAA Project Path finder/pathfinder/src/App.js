import React, { useState } from "react";
import "./App.css";

const ROWS = 10;
const COLS = 20;
//jj

function createGrid(start, end) {
  const grid = [];
  for (let r = 0; r < ROWS; r++) {
    const row = [];
    for (let c = 0; c < COLS; c++) {
      row.push({
        row: r,
        col: c,
        isStart: r === start.row && c === start.col,
        isEnd: r === end.row && c === end.col,
        distance: Infinity,
        isVisited: false,


        //l
        previousNode: null,
        isPath: false,
        weight: Math.floor(Math.random() * 5) + 1,
        isWall:
          Math.random() < 0.25 &&
          !(r === start.row && c === start.col) &&
          !(r === end.row && c === end.col),
      });
    }
    grid.push(row);
  }
  return grid;
}

export default function App() {
  const [start] = useState({ row: 0, col: 0 });
  const [end] = useState({ row: 9, col: 19 });
  const [grid, setGrid] = useState(createGrid(start, end));

  const getNeighbors = (node, grid) => {
    const neighbors = [];
    const { row, col } = node;

    if (row > 0) neighbors.push(grid[row - 1][col]);
    if (row < ROWS - 1) neighbors.push(grid[row + 1][col]);
    if (col > 0) neighbors.push(grid[row][col - 1]);
    if (col < COLS - 1) neighbors.push(grid[row][col + 1]);

    return neighbors;
  };

  const runDijkstra = () => {
    const newGrid = createGrid(start, end);

    const startNode = newGrid[start.row][start.col];
    startNode.distance = 0;

    const unvisited = newGrid.flat();
    const visitedNodes = [];

    while (unvisited.length) {
      unvisited.sort((a, b) => a.distance - b.distance);
      const closest = unvisited.shift();

      if (!closest || closest.isWall) continue;
      if (closest.distance === Infinity) break;

      closest.isVisited = true;
      visitedNodes.push(closest);

      if (closest.row === end.row && closest.col === end.col) break;

      const neighbors = getNeighbors(closest, newGrid);

      for (let neighbor of neighbors) {
        if (neighbor.isWall) continue;

        const newDist = closest.distance + neighbor.weight;
        if (newDist < neighbor.distance) {
          neighbor.distance = newDist;
          neighbor.previousNode = closest;
        }
      }
    }

    animate(visitedNodes, newGrid);
  };

  const animate = (visitedNodes, gridCopy) => {
    for (let i = 0; i < visitedNodes.length; i++) {
      setTimeout(() => {
        const node = visitedNodes[i];
        gridCopy[node.row][node.col].isVisited = true;
        setGrid([...gridCopy]);
      }, 15 * i);
    }

    setTimeout(() => {
      animatePath(gridCopy);
    }, 15 * visitedNodes.length);
  };

  const animatePath = (gridCopy) => {
    const path = [];
    let curr = gridCopy[end.row][end.col];

    while (curr) {
      path.unshift(curr);
      curr = curr.previousNode;
    }

    for (let i = 0; i < path.length; i++) {
      setTimeout(() => {
        const node = path[i];
        gridCopy[node.row][node.col].isPath = true;
        setGrid([...gridCopy]);
      }, 40 * i);
    }
  };

  return (
    <div className="container">
      <h1 className="title">🚀 Path Finder Visualizer</h1>

      <div className="card">
        <button onClick={runDijkstra}>Find Path</button>
        <button onClick={() => setGrid(createGrid(start, end))}>
          Reset Grid
        </button>

        <div className="grid">
          {grid.map((row, rIdx) => (
            <div key={rIdx} className="row">
              {row.map((node, cIdx) => {
                let classes = "node";

                if (node.isStart) classes += " start";
                else if (node.isEnd) classes += " end";
                else if (node.isWall) classes += " wall";
                else if (node.isPath) classes += " path";
                else if (node.isVisited) classes += " visited";

                return <div key={cIdx} className={classes}></div>;
              })}
            </div>
          ))}
        </div>
      </div>
    </div>
  );
}