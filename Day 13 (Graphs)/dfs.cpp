#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Node      //  one edge
{
    int vertex;
    Node* next;
};


struct Location
{
    string name;
    string type;
    int battles;
    int x, y;
};

class Graph
{
private:
    int V;
    Node ** adj;
    Location* locations;

public:
    Graph(int vertices)
    {
        V = vertices;

        locations = new Location[V];

        adj = new Node * [V];
        
        for (int i = 0; i < V; i++)
        {
            adj[i] = NULL;
        }
    }


    void addEdge(int id, int neighbor)    //        directed edge + insertion at head
    {
        // TODO
        Node* newnode = new Node;
        newnode->next = adj[id];
        newnode->vertex = neighbor;
        adj[id] = newnode;
    }
 

    void printGraph()
    {
        for (int i = 0; i < V; i++)
        {
            cout << locations[i].name << " (" << locations[i].type << ") -> ";

            // TODO: Initialize temp for the current location
            // ~1 line of code
            Node* temp = adj[i];

            while (temp)
            {
                // TODO: Replace the ? such that it shows the connected locations of the current location
                int val= temp->vertex;
                cout << locations[val].name << " | ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    

    void readCSV(const string& filename)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cout << "Failed to open file.\n";
            return;
        }

        string line;
        getline(file, line); // skip header

        while (getline(file, line))
        {
            stringstream ss(line);
            string idStr, name, type, popStr, xStr, yStr, connections;

            getline(ss, idStr, ',');
            getline(ss, name, ',');
            getline(ss, type, ',');
            getline(ss, popStr, ',');
            getline(ss, xStr, ',');
            getline(ss, yStr, ',');
            getline(ss, connections, ',');

            int id = stoi(idStr);
            int battles = stoi(popStr);
            int x = stoi(xStr);
            int y = stoi(yStr);

            // store location info
            locations[id].name = name;
            locations[id].type = type;
            locations[id].battles = battles;
            locations[id].x = x;
            locations[id].y = y;

            // parse connections
            stringstream connSS(connections);
            string neighborStr;
            while (getline(connSS, neighborStr, '|'))
            {
                int neighbor = stoi(neighborStr);
                addEdge(id, neighbor);
            }
        }

        file.close();
    }


    // TODO: Write C++ code from this pseudocode
    bool dfsPath(int currentNode,int destination,bool visited[],int path[],bool pathLength)
    {
        //MARK visited[currentNode] AS true

        visited[currentNode] = true;

        //ADD currentNode TO path at index pathLength

        path[pathLength] = currentNode;

        pathLength++;

        //IF currentNode == destination THEN
        //RETURN true   // Path found

        if (currentNode == destination)
        {
            return true;
        }

        //FOR each neighbor IN adjacency list of currentNode DO
        
        Node* neighbor = adj[currentNode];

        while(true)
        {
            //IF neighbor is not visited THEN

            if (!visited[neighbor])
            {
                //IF DFS_Path(neighbor, destination, visited, path, pathLength) RETURNS true THEN
                dfsPath(neighbor, destination, visited, path, pathLength)
                {
                    return true;  // RETURN true   // Path exists via this neighbor
                }
            }
            neighbor = neighbor->next;
            // Backtracking
            pathLength--;  // Remove currentNode from path
            return false  // No path found from this node
        }
    }
        

    void findAndPrintPath(int src, int dest)
    {

        bool* visited = new bool[V]; // Dynamic array for visited
        int* path = new int[V];      // Dynamic array for path storage
        int pathLen = 0;

        for (int i = 0; i < V; i++)
            visited[i] = false;

        if (dfsPath(src, dest, visited, path, pathLen))
        {
            cout << "\nPath found!\n";
            cout << "Path from " << locations[src].name << " to " << locations[dest].name << ":\n";
            for (int i = 0; i < pathLen; i++)
            {
                cout << locations[path[i]].name;

                if (i < pathLen - 1)
                    cout << " -> ";
            }
            cout << endl;
        }

        else
        {
            cout << "No path exists from " << locations[src].name << " to " << locations[dest].name << endl;
        }

        delete[] visited;
        delete[] path;
    }
};

int main()
{
    const int N = 30; // number of locations
    Graph g(N);

    g.readCSV("battlefield4_maps.csv");

    g.printGraph();

    int src, dest;
    cout << "Enter source index: ";
    cin >> src;
    cout << "Enter destination index: ";
    cin >> dest;

    g.findAndPrintPath(src, dest);

    return 0;
}


