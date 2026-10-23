#include <stack>

void RemoveConsecutiveDuplicates(std::stack<int>& values) {
    if (values.empty()) {
        return;
    }

    std::stack<int> aux;
    aux.push(values.top());
    values.pop();

    while (!values.empty()) {
        if (values.top() != aux.top()) {
            aux.push(values.top());
        }
        values.pop();
    }

    while (!aux.empty()) {
        values.push(aux.top());
        aux.pop();
    }
}