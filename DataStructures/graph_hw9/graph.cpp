//
// Created by Matthew Li on 5/30/22.
//

#include "graph.h"
// FILE: graph.template (part of the namespace main_savitch_15)
// TEMPLATE CLASS IMPLEMENTED: graph<Item> (See graph.h for documentation.)
// This file is included in the header file and not compiled separately.
// INVARIANT for the graph class:
//   1. The number of vertices in the graph is stored in the member variable
//      many_vertices.
//   1. These vertices are numbered from 0 to many_vertices-1.
//   2. edges is the adjacency matrix for the graph (with true in edges[i][j]
//      to indicate an edge from vertex i to vertex j).
//   3. For each i < many_vertices, labels[i] is the label of vertex i.

#include <bits/stdc++.h>

namespace main_savitch_15
{
    template <class Item>
    const std::size_t graph<Item>::MAXIMUM;

    template <class Item>
    void graph<Item>::add_edge(std::size_t source, std::size_t target)
    // Library facilities used: cassert, cstdlib
    {
        assert(source < size( ));
        assert(target < size( ));
        edges[source][target] = true;
    }

    template <class Item>
    void graph<Item>::add_vertex(const Item& label)
    // Library facilities used: cassert, cstdlib
    {
        std::size_t new_vertex_number;
        std::size_t other_number;

        assert(size( ) < MAXIMUM);
        new_vertex_number = many_vertices;
        many_vertices++;
        for (other_number = 0; other_number < many_vertices; ++other_number)
        {
            edges[other_number][new_vertex_number] = false;
            edges[new_vertex_number][other_number] = false;
        }
        labels[new_vertex_number] = label;
    }

    template <class Item>
    bool graph<Item>::is_edge(std::size_t source, std::size_t target) const
    // Library facilities used: cassert, cstdlib
    {
        assert(source < size( ));
        assert(target < size( ));
        return edges[source][target];
    }

    template <class Item>
    Item& graph<Item>::operator[ ] (std::size_t vertex)
    // Library facilities used: cassert, cstdlib
    {
        assert(vertex < size( ));
        return labels[vertex];     // Returns a reference to the label
    }

    template <class Item>
    Item graph<Item>::operator[ ] (std::size_t vertex) const
    // Library facilities used: cassert, cstdlib
    {
        assert(vertex < size( ));
        return labels[vertex];     // Returns only a copy of the label
    }

    template <class Item>
    std::set<std::size_t> graph<Item>::neighbors(std::size_t vertex) const
    // Library facilities used: cassert, cstdlib, set
    {
        std::set<std::size_t> answer;
        std::size_t i;

        assert(vertex < size( ));

        for (i = 0; i < size( ); ++i)
        {
            if (edges[vertex][i])
                answer.insert(i);
        }
        return answer;
    }

    template <class Item>
    void graph<Item>::remove_edge(std::size_t source, std::size_t target)
    // Library facilities used: cassert, cstdlib
    {
        assert(source < size( ));
        assert(target < size( ));
        edges[source][target] = false;
    }

    template <class Item>
    void graph<Item>::dfs(std::vector<int>& dp, std::vector<bool>& visited, std::size_t source, std::size_t target) const{
        if(visited[source] || source == target) {
            return;
        }
        visited[source] == true;
        std::set<std::size_t>::iterator it;
        std::set<std::size_t> connections = neighbors(source);
        for(it = connections.begin(); it != connections.end(); it++) {
            if(!visited[*it]) {
                dfs(dp, visited, *it, target);
                dp[source] = std::max(dp[source], dp[*it]+1);
            }
        }
    }

    template <class Item>
    std::size_t graph<Item>::longest_distance(std::size_t source, std::size_t target) const {
        std::vector<int> dp(size(), 0);
        std::vector<bool> visited(size(), false);
        dfs(dp, visited, source, target);
        std::size_t m = 0;
        for(auto e: dp) {
            if(e > m) {
                m = e;
            }
        }
        return m;
    }
}

