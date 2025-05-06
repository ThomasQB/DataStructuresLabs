void sink(char** grid, int gridSize, int *gridColSize, int r, int c) {
    if (r<0 || r>=gridSize || c<0 || c>=gridColSize[0] || grid[r][c] == '0') //0 or oob
        return;
    //sink island
    grid[r][c] = '0';

    //check surrounding area
    sink(grid, gridSize, gridColSize, r+1, c);
    sink(grid, gridSize, gridColSize, r-1, c);
    sink(grid, gridSize, gridColSize, r, c+1);
    sink(grid, gridSize, gridColSize, r, c-1);
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0) return 0;
    int islands = 0;

    //Look at all spots
    for (int r = 0; r < gridSize; r++) {
        for (int c = 0; c < gridColSize[0]; c++) {
            //1 found
            if (grid[r][c] == '1') {
                islands++; // add new island to count
                // sink the whole island
                sink(grid, gridSize, gridColSize, r, c);
            }
        }
    }
    return islands;
}
