#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cassert>
#include <vector>
#include <list>
#include <queue>

class graph
{
public:

    // default constructor
    // pre: none
    // post: creates an empty graph
    graph()
    {
        _v = std::vector<std::list<std::size_t>>();
    }

    // pre: none
    // post: returns the number of vertices in this graph
    std::size_t n() const
    {
        return _v.size();
    }

    // pre: none
    // post: returns the number of edges in this graph
    std::size_t m() const
    {
        std::size_t ans(0);
        for (auto e: _v)
            ans += e.size();

        return ans/2;
    }

    // pre: none
    // post: a new vertex (numbered with an integer) has
    //       been added to this graph
    void add_vertex()
    {
        _v.push_back(std::list<std::size_t>());
    }


    // pre: a & b are existing vertices
    // post: edge {a b} has been added to this graph
    //       if it was not in this graph; otherwise do nothing
    void add_edge(std::size_t a, std::size_t b)
    {
        assert(a < n() && b < n());
        if (!is_edge(a, b))
        {
            _v[a].push_front(b);
            _v[b].push_front(a);
        }
    }

    // pre: a is an existing vertex
    // post: vertex a and associated edges with a as an endpoint
    //       has been removed from this graph
    void remove_vertex(std::size_t a);

    // pre: a, b are existing vertices
    // post: edge {a, b} has been removed from this graph if it
    //       was in this graph; otherwise do nothing
    void remove_edge(std::size_t a, std::size_t b)
    {
        assert(a < n() && b < n());
        if (is_edge(a, b))
        {
            _v[a].remove(b);
            _v[b].remove(a);
        }
    }

    // pre: none
    // post: returns true iff {a, b} is an edge in this graph
    bool is_edge(std::size_t a, std::size_t b) const
    {
        if (a >= n() || b >= n())
            return false;

        for (auto e: _v[a])
            if (e == b)
                return true;

        return false;
    }
    std::list<std::size_t> neighbors (std::size_t a) const
    {
        assert(a < n());
        return _v[a];
    }

    std::size_t ncc()
    {
        std::vector<int> parent(n(), -1);
        std::size_t connected_components(0);
        std::size_t dia(0);
        std::size_t w;

        for (std::size_t start = 0; start < n(); ++start)
        {
            if (parent[start] == -1)
            {
                bfs1(start, parent);
                ++connected_components;
                if (diameter(start) > dia)
                {
                    w = start;
                    dia = diameter(start);
                }
            }
        }
        std::cout << "diameter = " << dia << " at " << w << std::endl;
        return connected_components;
    }

    bool is_connected()
    {
        return (ncc() == 1);

    }

    bool is_cyclic() const;
    bool is_tree() const;
    bool is_bipartite() const;

    bool is_complete() const
    {
        for (auto e: _v)
            if (e.size() != n()-1)
                return false;

        return true;
    }

    std::size_t diameter(std::size_t start)
    {
        std::queue<std::size_t> q;
        std::vector<int> d(n(), -1);
        q.push(start);
        d[start] = 0;
        std::size_t f;
        while (!q.empty())
        {
            f = q.front();
            q.pop();
            for (auto e: _v[f])
                if (d[e] == -1)
                {
                    d[e] = d[f] + 1;
                    q.push(e);

                }
        }
        std::cout << "diameter starting at " << f;
        std::size_t newstart = f;
        q.push(f);
        d = std::vector<int>(n(), -1);
        d[f] = 0;
        while(!q.empty())
        {
            f = q.front();
            q.pop();
            for (auto e: _v[f])
                if (d[e] == -1)
                {
                    d[e] = d[f] + 1;
                    q.push(e);
                }
        }
        std::cout << "  ending at " << f << ": " << d[f] << std::endl;

        for (auto e: shortest_path(newstart, f))
            std::cout << e << " ";
        std::cout << "  len = " << d[f] << std::endl;


        return d[f];
    }

    std::vector<int> shortest_path(std::size_t start, std::size_t dest)
    {

        std::vector<int> parent(n(), -1);
        bfs1(start, parent);

        if (parent[dest] == -1)
            return std::vector<int>();

        std::vector<int> ans;
        for (int v = dest; v != start; v = parent[v])
        {
            ans.push_back(v);
        }
        ans.push_back(start);
        return ans;
    }


private:

    void bfs1(std::size_t start, std::vector<int> & parent)
    {
        std::queue<std::size_t> q;

        parent[start] = start;
        q.push(start);

        while(!q.empty())
        {
            std::size_t f = q.front();
            q.pop();
            for (auto e: _v[f])
                if (parent[e] == -1)
                {
                    parent[e] = f;
                    q.push(e);
                }
        }
    }


    std::vector<std::list<std::size_t>> _v;

    // invariants:
    // n = number of vertices
    // m = number of edges
    // vertices are consecutively number 0, 1, ..., n-1
    // _v[i] is an (unsorted) list of neighbors of i
    //  (vertices adjacent to i)

};


std::ostream & operator <<(std::ostream & os, const graph & g)
{
    os << g.n() << " " << g.m() << std::endl;
    for (std::size_t i = 0; i < g.n(); ++i)
    {
        std::list<std::size_t> n = g.neighbors(i);
        for (auto e: n)
            if (e > i)
                os << i << " " << e << std::endl;
    }
    return os;
}

std::istream & operator >>(std::istream & is, graph & g)
{
    std::size_t n, m, a, b;

    is >> n >> m;

    g = graph();
    for (std::size_t i = 0; i < n; ++i)
        g.add_vertex();

    for (std::size_t i = 0; i < m; ++i)
    {
        is >> a >> b;
        g.add_edge(a, b);
    }
    return is;


}

#endif // GRAPH_H
