/*
    Maze Escape

    Sometimes when dealing with graphs, it is easiest to leave it in its input format 
    rather than creating another structure like an adjacency list/matrix. You are given 
    a graph represented as a vector of strings. Write a function 
    `traverse(vector<string>& graph)` that takes as input a graph and returns the length 
    of the shortest path between vertices `s` and `t`. If no path exists between `s` and 
    `t`, then return `-1`. The details of the graph as a vector of strings are as follows:

    1. The start position is represented by a 's' and will always be the first character of 
       the first string (`graph[0][0]`). 
    2. The end position is represented by a 't' and will always be the last character of the 
       final string (`graph[graph.size()-1][graph[0].length()-1]`).
    3. A '.' character represents a normal vertex in the graph.
    4. A '#' character represents that you cannot visit this vertex in the graph (or there 
       is no vertex at this position).
    5. Adjacent vertices are those immediately horizontal or vertical from the current vertex 
       (diagonal moves are not allowed).
    6. The cost of moving along one edge (from one vertex to an adjacent vertex) is always 1 
       (i.e. this is an unweighted graph).

    Sample Input
        s#.#.   
        .#...  
        ...#t    

    Sample Output: 8
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int traverse(std::vector<std::string> &graph) 
{
    vector<vector<int>> distance_matrix;
    queue<pair<int, int>> q;

    for (int i = 0; i < graph.size(); i++) {
        distance_matrix.push_back({});

        for (int j = 0; j < graph[i].size(); j++) {
            if (graph[i][j] == '#') {
                distance_matrix[i].push_back(-1);
            } else {
                distance_matrix[i].push_back(INT_MAX);
            }
        }
    }

    int row_count = distance_matrix.size(), col_count = distance_matrix[0].size();

    q.emplace(pair<int, int> (0, 0));

    while (q.empty() == false) {
        int row = q.front().first, col = q.front().second;

        int min_dist = INT_MAX;

        q.pop();

        if (row + 1 < row_count) {
            if (distance_matrix[row + 1][col] == INT_MAX) {
                q.emplace(pair<int, int> (row + 1, col));
            } else if (distance_matrix[row + 1][col] != -1) {
                min_dist = min(min_dist, distance_matrix[row + 1][col]);
            }
        }

        if (row - 1 >= 0) {
            if (distance_matrix[row - 1][col] == INT_MAX) {
                q.emplace(pair<int, int> (row - 1, col));
            } else if (distance_matrix[row - 1][col] != -1) {
                min_dist = min(min_dist, distance_matrix[row - 1][col]);
            }
        }

        if (col + 1 < col_count) {
            if (distance_matrix[row][col + 1] == INT_MAX) {
                q.emplace(pair<int, int> (row, col + 1));
            } else if (distance_matrix[row][col + 1] != -1) {
                min_dist = min(min_dist, distance_matrix[row][col + 1]);
            }
        }

        if (col - 1 >= 0) {
            if (distance_matrix[row][col - 1] == INT_MAX) {
                q.emplace(pair<int, int> (row, col - 1));
            } else if (distance_matrix[row][col - 1] != -1) {
                min_dist = min(min_dist, distance_matrix[row][col - 1]);
            }
        }

        distance_matrix[row][col] = (min_dist == INT_MAX ? 0 : min_dist + 1);
    }

    // This is me printing out the final matrix just for double-checking.

//    for (vector<int> v : distance_matrix) {
//        for (int i : v) {
//            cout << i << " ";
//        }
//
//        cout << endl;
//    }

    return distance_matrix[row_count - 1][col_count - 1];
}
