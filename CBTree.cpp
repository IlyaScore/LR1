#include "header.h"
#include <queue> // Для использования очереди

// Функция для вставки узла в дерево
void CBTree::insert(int value) {
    root = insert(root, value);
}

// Функция для поиска узла в дереве
bool CBTree::find(int value) {
    return find(root, value);
}

// Функция для проверки, является ли дерево Complete Binary Tree
bool CBTree::isCompleteBT(int index, int nodeCount) {
    return isCompleteBT(root, index, nodeCount);
}

// Функция для подсчета количества узлов в дереве
int CBTree::countNodes() {
    return countNodes(root);
}

// Функция для вывода дерева (обход в ширину)
void CBTree::read() {
    readByLevels(root);
}

// Внутренняя функция для вставки узла в дерево
TreeNode* CBTree::insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (root->left == nullptr) {
        root->left = insert(root->left, value);
    } else if (root->right == nullptr) {
        root->right = insert(root->right, value);
    } else {
        root->left = insert(root->left, value);
    }
    return root;
}

// Внутренняя функция для поиска узла в дереве
bool CBTree::find(TreeNode* root, int value) {
    if (root == nullptr) {
        return false;
    }
    if (root->digit == value) {
        return true;
    }
    return find(root->left, value) || find(root->right, value);
}

// Внутренняя функция для проверки, является ли дерево Complete Binary Tree
bool CBTree::isCompleteBT(TreeNode* root, int index, int nodeCount) {
    if (root == nullptr) {
        return true;
    }
    if (index >= nodeCount) {
        return false;
    }
    return isCompleteBT(root->left, 2 * index + 1, nodeCount) &&
           isCompleteBT(root->right, 2 * index + 2, nodeCount);
}

// Внутренняя функция для подсчета количества узлов в дереве
int CBTree::countNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Внутренняя функция для вывода дерева по уровням (обход в ширину)
void CBTree::readByLevels(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Используем очередь для обхода в ширину
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size(); // Количество узлов на текущем уровне

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();

            // Выводим значение текущего узла
            cout << current->digit << " ";

            // Добавляем дочерние узлы в очередь
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        // Переходим на новую строку после вывода всех узлов текущего уровня
        cout << endl;
    }
}