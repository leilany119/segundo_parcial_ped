#include <iostream>
#include <queue>
#include <stack>

void RemoveConsecutiveDuplicates(std::stack<int>& values) {
    std::stack<int> result;
    bool hasPrevious = false;
    int previous = 0;

    while (!values.empty()) {
        int current = values.top();
        values.pop();

        if (!hasPrevious || current != previous) {
            result.push(current);
        }

        previous = current;
        hasPrevious = true;
    }

    while (!result.empty()) {
        values.push(result.top());
        result.pop();
    }
}

void PrintFromTop(std::stack<int> values) {
    while (!values.empty()) {
        std::cout << values.top() << ' ';
        values.pop();
    }
    std::cout << '\n';
}

void SeparateRequests(
    std::queue<int>& requests,
    std::queue<int>& priority) {
    std::queue<int> remaining;
    const std::size_t originalSize = requests.size();

    for (std::size_t i = 0; i < originalSize; ++i) {
        int request = requests.front();
        requests.pop();

        if (request % 3 == 0) {
            priority.push(request);
        } else {
            remaining.push(request);
        }
    }

    requests.swap(remaining);
}

void PrintQueue(std::queue<int> values) {
    while (!values.empty()) {
        std::cout << values.front() << ' ';
        values.pop();
    }
    std::cout << '\n';
}

int main() {
    std::stack<int> values;
    values.push(2);
    values.push(2);
    values.push(7);
    values.push(7);
    values.push(3);
    values.push(8);
    values.push(8);
    values.push(5);
    values.push(5);
    values.push(5);

    std::cout << "Pila inicial (tope a fondo): ";
    PrintFromTop(values);

    RemoveConsecutiveDuplicates(values);

    std::cout << "Pila resultante (tope a fondo): ";
    PrintFromTop(values);

    std::queue<int> requests;
    std::queue<int> priority;
    requests.push(4);
    requests.push(6);
    requests.push(9);
    requests.push(2);
    requests.push(12);
    requests.push(5);
    requests.push(7);
    requests.push(3);

    std::cout << "Cola inicial (frente a final): ";
    PrintQueue(requests);

    SeparateRequests(requests, priority);

    std::cout << "requests: ";
    PrintQueue(requests);
    std::cout << "priority: ";
    PrintQueue(priority);

    return 0;
}