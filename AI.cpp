enum class NPCState {
    IDLE,
    WALKING,
    ATTACKING,
    FLEEING
};

NPCState currentState;

void updateAI(double dt) {
    switch (currentState) {
        case NPCState::IDLE:
            // Handle idle behavior
            break;
        case NPCState::WALKING:
            // Handle walking behavior
            break;
        case NPCState::ATTACKING:
            // Handle attacking behavior
            break;
        case NPCState::FLEEING:
            // Handle fleeing behavior
            break;
    }
}

#include <unordered_map>
#include <queue>

std::unordered_map<int, Node> openSet;
std::unordered_map<int, Node> closedSet;

std::vector<Node> findPath(Node start, Node goal) {
    openSet[start.getId()] = start;
    while (!openSet.empty()) {
        Node current = getNodeWithLowestCost(openSet);
        if (current == goal) {
            return constructPath(goal);
        }
        openSet.erase(current.getId());
        closedSet[current.getId()] = current;
        for (Node neighbor : current.getNeighbors()) {
            if (closedSet.count(neighbor.getId()) > 0) {
                continue;
            }
            double cost = current.getCost() + getDistance(current, neighbor);
            if (openSet.count(neighbor.getId()) == 0 || cost < neighbor.getCost()) {
                neighbor.setCost(cost);
                neighbor.setParent(current);
                openSet[neighbor.getId()] = neighbor;
            }
        }
    }
    return std::vector<Node>();
}
