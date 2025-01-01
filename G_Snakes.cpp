#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> length(n + 1, 1); // Length of each snake, initialized to 1
    vector<pair<int, char>> events(q); // Store events for processing

    // Read events
    for (int i = 0; i < q; ++i) {
        int snake_id;
        char event;
        cin >> snake_id >> event;
        events[i] = {snake_id, event};
    }

    // To track the maximum occupied cell
    set<int> occupied; // Set to track occupied cells

    // Process events in reverse to determine optimal initial positions
    for (int i = q - 1; i >= 0; --i) {
        int snake_id = events[i].first;
        char event = events[i].second;

        if (event == '+') {
            // Snake is supposed to grow, so we need to place it in a way that allows growth
            length[snake_id]++; // Increase length for the next position
        } else {
            // Snake is supposed to shrink, so we need to place it in a way that allows shrinking
            if (length[snake_id] > 1) {
                length[snake_id]--; // Decrease length for the next position
            }
        }
    }

    // Now we need to place the snakes in a way that minimizes the maximum occupied cell
    vector<int> position(n + 1, 0); // Position of each snake
    int current_position = 1;

    // Place snakes in a way that they do not overlap
    for (int i = 1; i <= n; ++i) {
        while (occupied.find(current_position) != occupied.end()) {
            current_position++; // Find the next free position
        }
        position[i] = current_position; // Place the snake
        occupied.insert(current_position); // Mark this position as occupied
        current_position++; // Move to the next cell for the next snake
    }

    // Calculate the maximum occupied cell
    int overall_max_cell = 0;
    for (int i = 1; i <= n; ++i) {
        overall_max_cell = max(overall_max_cell, position[i] + length[i] - 1);
    }

    cout << overall_max_cell << endl;

    return 0;
}